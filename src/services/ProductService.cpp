#include "services/ProductService.h"
#include "services/DatabaseService.h"

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

ProductService::ProductService(DatabaseService* databaseService)
{
    this->databaseService = databaseService;
}

// ======================================================
// Interactive Functions
// ======================================================

void ProductService::addProduct()
{
    string productID;
    string sku;
    string barcode;
    string name;
    string brand;
    string categoryID;

    double costPrice;
    double sellingPrice;

    int stockQuantity;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n=========================================\n";
    cout << "            ADD NEW PRODUCT\n";
    cout << "=========================================\n\n";

    cout << "Product ID     : ";
    getline(cin, productID);

    cout << "SKU            : ";
    getline(cin, sku);

    cout << "Barcode        : ";
    getline(cin, barcode);

    cout << "Product Name   : ";
    getline(cin, name);

    cout << "Brand          : ";
    getline(cin, brand);

    cout << "Category ID    : ";
    getline(cin, categoryID);

    cout << "Cost Price     : RM ";
    cin >> costPrice;

    cout << "Selling Price  : RM ";
    cin >> sellingPrice;

    cout << "Stock Quantity : ";
    cin >> stockQuantity;

    Product product(
        productID,
        sku,
        barcode,
        name,
        brand,
        categoryID,
        costPrice,
        sellingPrice,
        stockQuantity
    );

    if(addProduct(product))
    {
        cout << "\nProduct added successfully.\n";
    }
    else
    {
        cout << "\nProduct ID already exists.\n";
    }
}

void ProductService::searchProduct()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string keyword;

    cout << "\nSearch Keyword : ";
    getline(cin, keyword);

    vector<Product> results =
        searchProduct(keyword);

    if(results.empty())
    {
        cout << "\nNo products found.\n";
        return;
    }

    cout << "\n=========== SEARCH RESULT ===========\n";

    for(const auto& product : results)
    {
        product.displayProduct();
        cout << "-------------------------------------\n";
    }
}

void ProductService::updateProduct()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string id;

    cout << "\nProduct ID : ";
    getline(cin, id);

    Product* product =
        getProductByID(id);

    if(product == nullptr)
    {
        cout << "Product not found.\n";
        return;
    }

    string name;
    double price;
    int quantity;

    cout << "New Name : ";
    getline(cin, name);

    cout << "New Selling Price : RM ";
    cin >> price;

    cout << "New Stock Quantity : ";
    cin >> quantity;

    product->setName(name);
    product->setSellingPrice(price);
    product->setStockQuantity(quantity);

    cout << "\nProduct updated successfully.\n";
}

void ProductService::deleteProduct()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string id;

    cout << "\nProduct ID : ";
    getline(cin, id);

    if(deleteProduct(id))
    {
        cout << "\nProduct deleted successfully.\n";
    }
    else
    {
        cout << "\nProduct not found.\n";
    }
}

// ======================================================
// CRUD Logic
// ======================================================

bool ProductService::addProduct(const Product& product)
{
    Product existing;

    if(databaseService->getProductByID(
        product.getProductID(),
        existing
    ))
    {
        return false;
    }

    return databaseService->insertProduct(product);
}

Product* ProductService::getProductByID(
    const string& id
)
{
    static Product product;

    if(databaseService->getProductByID(id, product))
    {
        return &product;
    }

    return nullptr;
}

vector<Product> ProductService::getAllProducts() const
{
    return databaseService->getAllProducts();
}

vector<Product> ProductService::searchProduct(
    const string& keyword
)
{
    return databaseService->searchProducts(keyword);
}

bool ProductService::updateProduct(
    const string& id,
    const Product& updatedProduct
)
{
    return databaseService->updateProduct(updatedProduct);
}

bool ProductService::deleteProduct(
    const string& id
)
{
    return databaseService->deleteProduct(id);
}

void ProductService::displayProducts() const
{
    vector<Product> products =
        databaseService->getAllProducts();

    cout << "\n=========================================================\n";
    cout << "                  PRODUCT INVENTORY\n";
    cout << "=========================================================\n";

    if(products.empty())
    {
        cout << "\nNo products available.\n";
        return;
    }

    for(const auto& product : products)
    {
        product.displayProduct();
        cout << "---------------------------------------------------------\n";
    }
}