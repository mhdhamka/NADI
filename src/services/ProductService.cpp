#include "services/ProductService.h"

#include <iostream>
#include <algorithm>



using namespace std;




ProductService::ProductService()

{

}





bool ProductService::addProduct(
    const Product& product
)

{

    // prevent duplicate ID

    for(auto& existing : products)

    {

        if(existing.getProductID()
            == product.getProductID())

        {

            return false;

        }

    }



    products.push_back(product);


    return true;

}







Product* ProductService::getProductByID(
    const string& id
)

{

    for(auto& product : products)

    {

        if(product.getProductID()
            == id)

        {

            return &product;

        }

    }



    return nullptr;

}







vector<Product>
ProductService::getAllProducts() const

{

    return products;

}








vector<Product>
ProductService::searchProduct(
    const string& keyword
)

{

    vector<Product> result;



    for(auto& product : products)

    {

        string name =
            product.getName();



        if(name.find(keyword)
            != string::npos)

        {

            result.push_back(product);

        }

    }



    return result;

}







bool ProductService::updateProduct(

    const string& id,

    const Product& updatedProduct

)

{


    Product* product =
        getProductByID(id);



    if(product == nullptr)

        return false;



    *product =
        updatedProduct;



    return true;

}








bool ProductService::deleteProduct(
    const string& id
)

{

    auto iterator =
        remove_if(

            products.begin(),

            products.end(),

            [&](Product& product)

            {

                return product.getProductID()
                    == id;

            }

        );



    if(iterator == products.end())

        return false;



    products.erase(
        iterator,
        products.end()
    );



    return true;

}








void ProductService::displayProducts() const

{

    cout
    << "\n========== PRODUCTS ==========\n";



    for(auto& product : products)

    {

        product.displayProduct();

    }



    cout
    << "\n==============================\n";

}