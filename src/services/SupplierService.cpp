#include "services/SupplierService.h"

#include <iostream>
#include <algorithm>


using namespace std;




SupplierService::SupplierService()

{

}







bool SupplierService::addSupplier(

    const Supplier& supplier

)

{


    for(auto& existing : suppliers)

    {

        if(existing.getSupplierID()

            == supplier.getSupplierID())

        {

            return false;

        }

    }



    suppliers.push_back(supplier);



    return true;

}








Supplier* SupplierService::getSupplierByID(

    const string& id

)

{


    for(auto& supplier : suppliers)

    {

        if(supplier.getSupplierID()
            == id)

        {

            return &supplier;

        }

    }



    return nullptr;

}








vector<Supplier>

SupplierService::getAllSuppliers() const

{

    return suppliers;

}








vector<Supplier>

SupplierService::searchSupplier(

    const string& keyword

)

{

    vector<Supplier> result;



    for(auto& supplier : suppliers)

    {


        if(

            supplier.getCompanyName()

            .find(keyword)

            != string::npos

        )

        {

            result.push_back(supplier);

        }

    }



    return result;

}








bool SupplierService::updateSupplier(

    const string& id,

    const Supplier& supplier

)

{

    Supplier* existing =
        getSupplierByID(id);



    if(existing == nullptr)

        return false;



    *existing = supplier;



    return true;

}








bool SupplierService::deleteSupplier(

    const string& id

)

{

    auto iterator =

    remove_if(

        suppliers.begin(),

        suppliers.end(),

        [&](Supplier& supplier)

        {

            return supplier.getSupplierID()
                == id;

        }

    );



    if(iterator == suppliers.end())

        return false;



    suppliers.erase(

        iterator,

        suppliers.end()

    );



    return true;

}








bool SupplierService::activateSupplier(

    const string& id

)

{

    Supplier* supplier =
        getSupplierByID(id);



    if(!supplier)

        return false;



    supplier->activate();



    return true;

}








bool SupplierService::deactivateSupplier(

    const string& id

)

{

    Supplier* supplier =
        getSupplierByID(id);



    if(!supplier)

        return false;



    supplier->deactivate();



    return true;

}








bool SupplierService::blacklistSupplier(

    const string& id

)

{

    Supplier* supplier =
        getSupplierByID(id);



    if(!supplier)

        return false;



    supplier->blacklist();



    return true;

}








void SupplierService::displaySuppliers() const

{


    cout

    << "\n========== SUPPLIERS ==========\n";



    for(auto& supplier : suppliers)

    {

        supplier.displaySupplier();

    }



    cout

    << "\n===============================\n";


}