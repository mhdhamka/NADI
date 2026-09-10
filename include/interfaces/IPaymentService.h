#ifndef IPAYMENTSERVICE_H
#define IPAYMENTSERVICE_H

#include <memory>

class Order;

class IPaymentService
{
public:

    virtual bool processPayment(
        std::shared_ptr<Order> order
    ) = 0;

    virtual bool refundPayment(
        std::shared_ptr<Order> order
    ) = 0;

    virtual ~IPaymentService() = default;
};

#endif