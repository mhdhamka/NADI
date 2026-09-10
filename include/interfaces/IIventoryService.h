#ifndef IINVENTORYSERVICE_H
#define IINVENTORYSERVICE_H

#include <string>

class IInventoryService
{
public:

    virtual bool hasStock(
        const std::string& productID,
        int quantity
    ) = 0;

    virtual bool reduceStock(
        const std::string& productID,
        int quantity
    ) = 0;

    virtual void increaseStock(
        const std::string& productID,
        int quantity
    ) = 0;

    virtual ~IInventoryService() = default;
};

#endif