#include "services/InventoryService.h"
<<<<<<< HEAD
#include "services/ProductService.h"
=======
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98

#include <iostream>

using namespace std;

InventoryService::InventoryService()
<<<<<<< HEAD
{
    productService = nullptr;
}

InventoryService::InventoryService(
    ProductService* productService
)
{
    this->productService = productService;
}

bool InventoryService::addProduct(
    const Product& product
)
{
    return productService->addProduct(product);
}

bool InventoryService::removeProduct(
    const string& productID
)
{
    return productService->deleteProduct(productID);
}

Product* InventoryService::findProduct(
    const string& productID
)
{
    return productService->getProductByID(productID);
}

vector<Product> InventoryService::getAllProducts() const
{
    return productService->getAllProducts();
}

bool InventoryService::stockIn(
    const string& productID,
    int quantity,
    const string& reason
)
{
    (void)reason;

    if(quantity <= 0)
        return false;

    Product* product =
        productService->getProductByID(productID);

    if(product == nullptr)
        return false;

    product->increaseStock(quantity);

    return true;
}

bool InventoryService::stockOut(
    const string& productID,
    int quantity,
    const string& reason
)
{
    (void)reason;

    if(quantity <= 0)
        return false;

    Product* product =
        productService->getProductByID(productID);

    if(product == nullptr)
        return false;

    return product->decreaseStock(quantity);
}

bool InventoryService::updateStock(
    const string& productID,
    int quantity
)
{
    Product* product =
        productService->getProductByID(productID);

    if(product == nullptr)
        return false;

    product->setStockQuantity(quantity);

    return true;
}

vector<Product> InventoryService::getLowStockProducts()
{
    vector<Product> lowStock;

    vector<Product> products =
        productService->getAllProducts();

    for(const auto& product : products)
    {
        if(product.needsRestock())
        {
            lowStock.push_back(product);
        }
    }

    return lowStock;
}

void InventoryService::displayInventory() const
{
    vector<Product> products =
        productService->getAllProducts();

    cout << "\n=========================================================\n";
    cout << "                  INVENTORY STATUS\n";
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
=======

{

}


InventoryService::InventoryService(

    const Inventory& inventory

)

{

    this->inventory = inventory;

}


bool InventoryService::addProduct(

    const Product& product

)

{

    inventory.addProduct(product);


    return true;

}








bool InventoryService::removeProduct(

    const string& productID

)

{

    return inventory.removeProduct(productID);

}







Product* InventoryService::findProduct(

    const string& productID

)

{

    return inventory.findProduct(productID);

}








vector<Product>

InventoryService::getAllProducts() const

{

    return inventory.getProducts();

}










bool InventoryService::stockIn(

    const string& productID,

    int quantity,

    const string& reason

)

{


    if(quantity <= 0)

        return false;




    return inventory.stockIn(

        productID,

        quantity,

        reason

    );

}









bool InventoryService::stockOut(

    const string& productID,

    int quantity,

    const string& reason

)

{


    if(quantity <= 0)

        return false;



    return inventory.stockOut(

        productID,

        quantity,

        reason

    );

}


bool InventoryService::updateStock(

    const string& productID,

    int quantity

)

{


    Product* product =
        inventory.findProduct(productID);



    if(product == nullptr)

        return false;



    product->setStockQuantity(quantity);



    return true;

}










vector<Product>

InventoryService::getLowStockProducts()

{

    return inventory.getLowStockProducts();

}










void InventoryService::displayInventory() const

{

    inventory.displayInventory();

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
}