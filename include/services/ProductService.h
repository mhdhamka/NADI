#ifndef PRODUCT_SERVICE_H
#define PRODUCT_SERVICE_H

#include <string>
#include <vector>

#include "../models/Product.h"

class DatabaseService;

class ProductService
{

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

    bool addProduct(
        const Product& product
    );

    Product* getProductByID(
        const std::string& id
    );

    std::vector<Product> getAllProducts() const;

    std::vector<Product> searchProduct(
        const std::string& keyword
    );

    bool updateProduct(
        const std::string& id,
        const Product& updatedProduct
    );

    bool deleteProduct(
        const std::string& id
    );
};

#endif