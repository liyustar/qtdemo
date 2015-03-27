#ifndef METHODINVOKER_H_
#define METHODINVOKER_H_

#include <string>
#include <map>

#include "type.h"

class MethodInvokerDelegate
{
    public:
        virtual std::string& onGetStringStore() = 0;
};

class MethodInvoker
{
    public:
        MethodInvoker() : delegate(NULL) {}
        void registerDelegate(MethodInvokerDelegate* delegate);
        // invoke web interface
        int invoke(const std::string& method, ParamMap& params);

    private:
        MethodInvokerDelegate* delegate;
};

inline void MethodInvoker::registerDelegate(MethodInvokerDelegate* dlg)
{
    delegate = dlg;
}

#endif // METHODINVOKER_H_
