#include "models/Inventory.h"

#include <iostream>

using namespace std;

Inventory::Inventory()
{
    inventoryID = "";
}

Inventory::Inventory(const string& inventoryID)
{
    this->inventoryID = inventoryID;
}

// =====================================================
// Product Management
// =====================================================

void Inventory::addProduct(const Product& product)
{
    products.push_back(product);
}

bool Inventory::removeProduct(const string& productID)
{
    for(auto it = products.begin(); it != products.end(); ++it)
    {
        if(it->getProductID() == productID)
        {
            products.erase(it);
            return true;
        }
    }

    return false;
}

Product* Inventory::findProduct(const string& productID)
{
    for(auto& product : products)
    {
        if(product.getProductID() == productID)
        {
            return &product;
        }
    }

    return nullptr;
}

vector<Product> Inventory::getProducts() const
{
    return products;
}

// =====================================================
// Stock Operations
// =====================================================

bool Inventory::stockIn(
    const string& productID,
    int quantity,
    const string& reason
)
{
    Product* product = findProduct(productID);

    if(product == nullptr)
    {
        return false;
    }

    product->increaseStock(quantity);

    StockMovement movement;
    movement.productID = productID;
    movement.type = StockMovementType::StockIn;
    movement.quantity = quantity;
    movement.reason = reason;

    movements.push_back(movement);

    return true;
}

bool Inventory::stockOut(
    const string& productID,
    int quantity,
    const string& reason
)
{
    Product* product = findProduct(productID);

    if(product == nullptr)
    {
        return false;
    }

    if(!product->decreaseStock(quantity))
    {
        return false;
    }

    StockMovement movement;
    movement.productID = productID;
    movement.type = StockMovementType::StockOut;
    movement.quantity = quantity;
    movement.reason = reason;

    movements.push_back(movement);

    return true;
}

void Inventory::adjustStock(
    const string& productID,
    int quantity
)
{
    Product* product = findProduct(productID);

    if(product != nullptr)
    {
        product->setStockQuantity(quantity);
    }
}

// =====================================================
// Reports
// =====================================================

vector<Product> Inventory::getLowStockProducts()
{
    vector<Product> result;

    for(auto& product : products)
    {
        if(product.needsRestock())
        {
            result.push_back(product);
        }
    }

    return result;
}

void Inventory::displayInventory() const
{
    cout << "\n========== INVENTORY ==========\n";

    for(const auto& product : products)
    {
        product.displayProduct();
    }

    cout << "===============================\n";
}