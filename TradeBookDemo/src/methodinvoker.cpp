#include "methodinvoker.h"
#include "constant.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <curl/curl.h>

namespace {

// invoke interface callback
size_t write_callback(char *ptr, size_t size, size_t nmumb, void *userp)
{
    MethodInvokerDelegate* dlg = (MethodInvokerDelegate *)userp;
    std::string &data = dlg->onGetStringStore();
    data.append(ptr, size * nmumb);
    return size * nmumb;
}

std::string mapToJsonstr(const MethodInvoker::ParamMap& params)
{
    // init post params
    QJsonObject json;
    for (MethodInvoker::ParamMap::const_iterator iter = params.begin();
            iter != params.end(); ++iter) {
        json[iter->first.c_str()] = iter->second.c_str();
    }
    QJsonDocument doc(json);
    QByteArray jsonBytes = doc.toJson(QJsonDocument::Compact);

    std::string data;
    data.append(jsonBytes.data(), jsonBytes.length());
    return data;
}

MethodInvoker::ParamMap responseToMap(const std::string& response)
{
    MethodInvoker::ParamMap params;
    QJsonDocument doc = QJsonDocument::fromRawData(response.data(), response.length());
    QJsonObject obj = doc.object();
    for (QJsonObject::const_iterator iter = obj.begin();
            iter != obj.end(); ++iter) {
        params[iter.key().toUtf8().data()] = iter.value().toString().toUtf8().data();
    }
    return params;
}

}

int MethodInvoker::invoke(const std::string& method, ParamMap& params)
{
    int rst = -1;
    if (delegate == NULL || method.empty())
        return -1;

    CURL *curl;
    curl = curl_easy_init();
    if (curl) {
        // clear string store
        delegate->onGetStringStore().clear();
        std::string data = "method=" + method + "&params=" + mapToJsonstr(params);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, Constant::IMS_IF_URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)delegate);

        CURLcode result = curl_easy_perform(curl);
        if (CURLE_OK != result) {
            qDebug() << "curl perform error";
        }
        else {
            // return params
            params = responseToMap(delegate->onGetStringStore());
            rst = 0;
        }

        curl_easy_cleanup(curl);
    }
    return rst;
}

