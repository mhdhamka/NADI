#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

#include "Product.h"



enum class StockMovementType
{
    StockIn,
    StockOut,
    Adjustment
};



struct StockMovement
{

    std::string movementID;

    std::string productID;


    StockMovementType type;


    int quantity;


    std::string reason;

};



class Inventory
{

private:

    std::string inventoryID;


    std::vector<Product> products;


    std::vector<StockMovement> movements;



public:


    Inventory();



    Inventory(
        const std::string& inventoryID
    );



    // Product management

    void addProduct(
        const Product& product
    );


    bool removeProduct(
        const std::string& productID
    );



    Product* findProduct(
        const std::string& productID
    );



    std::vector<Product> getProducts() const;



    // Stock management

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



    void adjustStock(
        const std::string& productID,
        int quantity
    );



    // Report

    std::vector<Product> getLowStockProducts();



    void displayInventory() const;



};


#endif