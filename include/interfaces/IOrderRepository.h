#ifndef IORDERREPOSITORY_H
#define IORDERREPOSITORY_H

#include <memory>
#include <vector>

class Order;

class IOrderRepository
{
public:

    virtual void save(
        std::shared_ptr<Order> order
    ) = 0;

    virtual void remove(
        const std::string& orderID
    ) = 0;

    virtual std::shared_ptr<Order> find(
        const std::string& orderID
    ) = 0;

    virtual std::vector<std::shared_ptr<Order>> findAll() = 0;

    virtual ~IOrderRepository() = default;
};

#endif