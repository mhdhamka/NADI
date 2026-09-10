#ifndef INVENTORY_SERVICE_H
#define INVENTORY_SERVICE_H

<<<<<<< HEAD
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

=======

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


>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    bool addProduct(
        const Product& product
    );

<<<<<<< HEAD
=======


>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    bool removeProduct(
        const std::string& productID
    );

<<<<<<< HEAD
=======


>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    Product* findProduct(
        const std::string& productID
    );

<<<<<<< HEAD
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

=======


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



>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
#endif