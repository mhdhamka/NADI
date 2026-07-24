#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H


#include <vector>
#include <string>

#include "../models/Product.h"



class ProductService
{


private:


    std::vector<Product> products;



public:


    ProductService();



    // CREATE

    bool addProduct(
        const Product& product
    );



    // READ

    Product* getProductByID(
        const std::string& id
    );



    std::vector<Product>
    getAllProducts() const;



    std::vector<Product>
    searchProduct(
        const std::string& keyword
    );



    // UPDATE

    bool updateProduct(
        const std::string& id,
        const Product& updatedProduct
    );



    // DELETE

    bool deleteProduct(
        const std::string& id
    );



    // DISPLAY

    void displayProducts() const;



};



#endif