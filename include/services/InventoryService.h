#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

#include <string>
#include <vector>

#include "../models/Product.h"

class ProductService;

class InventoryService
{
private:
    ProductService* productService;

public:
    InventoryService();

    InventoryService(
        ProductService* productService
    );

    // Product management

    bool addProduct(
        const Product& product
    );

    bool removeProduct(
        const std::string& productID
    );

    Product* findProduct(
        const std::string& productID
    );

    std::vector<Product> getAllProducts() const;

    // Stock operation

    bool stockIn(
        const std::string& productID,
        int quantity,
        const std::string& reason
    );

    bool stockOut(
        const std::string& productID,
        int quantity,
        const std::string& reason
    );

    bool updateStock(
        const std::string& productID,
        int quantity
    );

    // Reports

    std::vector<Product> getLowStockProducts();

    void displayInventory() const;
};

#endif