#include "models/Product.h"

#include <iostream>
#include <iomanip>


using namespace std;



Product::Product()
{

    productID = "";

    SKU = "";

    barcode = "";

    name = "";

    brand = "";

    categoryID = "";


    costPrice = 0;

    sellingPrice = 0;


    stockQuantity = 0;

    reorderLevel = 10;


    status = ProductStatus::OutOfStock;


    createdAt =
        chrono::system_clock::now();


    updatedAt = createdAt;

}



Product::Product(
    const string& productID,
    const string& SKU,
    const string& barcode,
    const string& name,
    const string& brand,
    const string& categoryID,
    double costPrice,
    double sellingPrice,
    int stockQuantity
)

{

    this->productID = productID;

    this->SKU = SKU;

    this->barcode = barcode;

    this->name = name;

    this->brand = brand;

    this->categoryID = categoryID;


    this->costPrice = costPrice;

    this->sellingPrice = sellingPrice;


    this->stockQuantity = stockQuantity;


    reorderLevel = 10;


    if(stockQuantity > 0)
        status = ProductStatus::Active;

    else
        status = ProductStatus::OutOfStock;


    createdAt =
        chrono::system_clock::now();


    updatedAt = createdAt;

}




string Product::getProductID() const
{
    return productID;
}


string Product::getSKU() const
{
    return SKU;
}


string Product::getBarcode() const
{
    return barcode;
}


string Product::getName() const
{
    return name;
}


string Product::getBrand() const
{
    return brand;
}


string Product::getCategoryID() const
{
    return categoryID;
}



double Product::getCostPrice() const
{
    return costPrice;
}



double Product::getSellingPrice() const
{
    return sellingPrice;
}



int Product::getStockQuantity() const
{
    return stockQuantity;
}



int Product::getReorderLevel() const
{
    return reorderLevel;
}



ProductStatus Product::getStatus() const
{
    return status;
}




void Product::setName(
    const string& name
)
{
    this->name = name;

    updatedAt =
        chrono::system_clock::now();
}



void Product::setSellingPrice(
    double price
)
{
    if(price > 0)
    {
        sellingPrice = price;
    }

    updatedAt =
        chrono::system_clock::now();
}



void Product::setStockQuantity(
    int quantity
)
{
    stockQuantity = quantity;


    if(stockQuantity <= 0)
        status = ProductStatus::OutOfStock;

    else
        status = ProductStatus::Active;
}



void Product::increaseStock(
    int amount
)
{
    if(amount > 0)
    {
        stockQuantity += amount;

        status = ProductStatus::Active;
    }
}




bool Product::decreaseStock(
    int amount
)
{

    if(amount <= 0)
        return false;


    if(amount > stockQuantity)
        return false;


    stockQuantity -= amount;


    if(stockQuantity == 0)
        status = ProductStatus::OutOfStock;


    return true;
}




bool Product::isAvailable() const
{
    return stockQuantity > 0;
}




bool Product::needsRestock() const
{
    return stockQuantity <= reorderLevel;
}




double Product::calculateProfitMargin() const
{
    if(sellingPrice == 0)
        return 0;


    return 
    ((sellingPrice - costPrice)
    /
    sellingPrice)
    *
    100;
}




void Product::displayProduct() const
{

    cout
    << "\n========== PRODUCT ==========\n"

    << "ID: "
    << productID

    << "\nName: "
    << name

    << "\nBrand: "
    << brand

    << "\nSelling Price: RM "
    << fixed
    << setprecision(2)
    << sellingPrice

    << "\nStock: "
    << stockQuantity

    << "\nProfit Margin: "
    << calculateProfitMargin()
    << "%"

    << "\n=============================\n";

}