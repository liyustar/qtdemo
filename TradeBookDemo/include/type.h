#ifndef TYPE_H_
#define TYPE_H_

#include <QString>
#include <map>
#include <string>

#include "constant.h"

typedef std::map<std::string, std::string> ParamMap;

typedef struct Order {
    Order(QString s = "[None]", Constant::ORDER_DIRECT d = Constant::ORDER_UNKNOW, double p = 0.0, int q = 0)
        : symbol(s), direct(d), price(p), quantity(q) {}

    QString symbol;
    Constant::ORDER_DIRECT direct;
    double price;
    int quantity;
} Order_t;

ParamMap convToParam(const Order_t&);
Order_t convToOrder(const ParamMap&);

#endif // TYPE_H_
