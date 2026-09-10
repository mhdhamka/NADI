#ifndef SUPPLIER_SERVICE_H
#define SUPPLIER_SERVICE_H


#include <vector>
#include <string>

#include "../models/Supplier.h"



class SupplierService
{


private:


    std::vector<Supplier> suppliers;



public:


    SupplierService();



    // CREATE

    bool addSupplier(
        const Supplier& supplier
    );



    // READ

    Supplier* getSupplierByID(
        const std::string& id
    );



    std::vector<Supplier>
    getAllSuppliers() const;



    std::vector<Supplier>
    searchSupplier(
        const std::string& keyword
    );



    // UPDATE

    bool updateSupplier(
        const std::string& id,
        const Supplier& supplier
    );



    // DELETE

    bool deleteSupplier(
        const std::string& id
    );



    // Status management

    bool activateSupplier(
        const std::string& id
    );



    bool deactivateSupplier(
        const std::string& id
    );



    bool blacklistSupplier(
        const std::string& id
    );



    // DISPLAY

    void displaySuppliers() const;


};



#endif