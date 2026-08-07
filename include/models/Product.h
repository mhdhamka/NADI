#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <chrono>


enum class ProductStatus
{
    Active,
    Discontinued,
    OutOfStock
};


class Product
{

private:

    std::string productID;

    std::string SKU;

    std::string barcode;

    std::string name;

    std::string brand;

    std::string categoryID;


    double costPrice;
    double sellingPrice;

    int stockQuantity;
    int totalSold;
    int reorderLevel;


    ProductStatus status;


    std::chrono::system_clock::time_point createdAt;

    std::chrono::system_clock::time_point updatedAt;



public:


    Product();


    Product(
        const std::string& productID,
        const std::string& SKU,
        const std::string& barcode,
        const std::string& name,
        const std::string& brand,
        const std::string& categoryID,
        double costPrice,
        double sellingPrice,
        int stockQuantity
    );


    // Getters

    std::string getProductID() const;

    std::string getSKU() const;

    std::string getBarcode() const;

    std::string getName() const;

    std::string getBrand() const;

    std::string getCategoryID() const;


    double getCostPrice() const;
    double getSellingPrice() const;


    int getStockQuantity() const;
    int getTotalSold() const;
    int getReorderLevel() const;


    ProductStatus getStatus() const;



    // Setters

    void setName(
        const std::string& name
    );


    void setSellingPrice(
        double price
    );


    void setStockQuantity(
        int quantity
    );

    void addSoldQuantity(
        int quantity
    );

    void increaseStock(
        int amount
    );


    bool decreaseStock(
        int amount
    );



    bool isAvailable() const;


    bool needsRestock() const;



    double calculateProfitMargin() const;


    void displayProduct() const;


};

#endif