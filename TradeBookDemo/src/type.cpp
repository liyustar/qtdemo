#include "type.h"

#include <iostream>

ParamMap convToParam(const Order_t& order)
{
    ParamMap map;
    map["symbol"] = order.symbol.toUtf8().data();
    map["direct"] = QString().setNum(order.direct).toUtf8().data();
    map["price"] = QString().setNum(order.price, 'g', 16).toUtf8().data();
    map["quantity"] = QString().setNum(order.quantity).toUtf8().data();
    return map;
}

Order_t convToOrder(const ParamMap& map)
{
    Order_t order;
    order.symbol = QString(map.at("symbol").c_str());
    order.direct = static_cast<Constant::ORDER_DIRECT>(QString(map.at("direct").c_str()).toInt());
    order.price = QString(map.at("price").c_str()).toDouble();
    order.quantity = QString(map.at("quantity").c_str()).toInt();
    return order;
}
