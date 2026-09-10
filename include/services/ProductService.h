#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H

<<<<<<< HEAD
#include <string>
#include <vector>

#include "../models/Product.h"

class DatabaseService;
=======

#include <vector>
#include <string>

#include "../models/Product.h"


>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98

class ProductService
{

<<<<<<< HEAD
private:
    DatabaseService* databaseService;

public:
    ProductService(DatabaseService* databaseService);

    // ========= Interactive Menu Functions =========

    void addProduct();

    void searchProduct();

    void updateProduct();

    void deleteProduct();

    void displayProducts() const;

    // ========= Core CRUD Logic =========
=======

private:


    std::vector<Product> products;



public:


    ProductService();



    // CREATE
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98

    bool addProduct(
        const Product& product
    );

<<<<<<< HEAD
=======


    // READ

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    Product* getProductByID(
        const std::string& id
    );

<<<<<<< HEAD
    std::vector<Product> getAllProducts() const;

    std::vector<Product> searchProduct(
        const std::string& keyword
    );

=======


    std::vector<Product>
    getAllProducts() const;



    std::vector<Product>
    searchProduct(
        const std::string& keyword
    );



    // UPDATE

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    bool updateProduct(
        const std::string& id,
        const Product& updatedProduct
    );

<<<<<<< HEAD
    bool deleteProduct(
        const std::string& id
    );
};

=======


    // DELETE

    bool deleteProduct(
        const std::string& id
    );



    // DISPLAY

    void displayProducts() const;



};



>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
#endif