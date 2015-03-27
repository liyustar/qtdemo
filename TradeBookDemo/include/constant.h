#ifndef CONSTANT_H_
#define CONSTANT_H_

#include <string>
#include <QMetaType>

class Constant
{
    public:
        static const std::string IMS_IF_URL;

        enum ORDER_DIRECT {
            ORDER_UNKNOW = -1,
            ORDER_BUY = 0,
            ORDER_SELL = 1,
        };
};

Q_DECLARE_METATYPE(Constant);

#endif // CONSTANT_H_
