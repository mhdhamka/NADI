#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H


#include <vector>
#include <string>

#include "../models/Product.h"
#include "../models/Inventory.h"



class InventoryService
{


private:


    Inventory inventory;



public:


    InventoryService();



    InventoryService(
        const Inventory& inventory
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



    std::vector<Product>
    getAllProducts() const;




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





    // Report


    std::vector<Product>
    getLowStockProducts();




    void displayInventory() const;



};



#endif