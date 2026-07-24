#include "services/InventoryService.h"

#include <iostream>

using namespace std;

InventoryService::InventoryService()

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

}