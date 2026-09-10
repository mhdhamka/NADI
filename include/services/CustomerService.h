#ifndef CUSTOMER_SERVICE_H
#define CUSTOMER_SERVICE_H


#include <vector>
#include <string>

#include "../models/Customer.h"



class CustomerService
{


private:


    std::vector<Customer> customers;



public:


    CustomerService();



    // CREATE

    bool addCustomer(
        const Customer& customer
    );



    // READ


    Customer* getCustomerByID(
        const std::string& id
    );



    std::vector<Customer>
    getAllCustomers() const;



    std::vector<Customer>
    searchCustomer(
        const std::string& keyword
    );



    // UPDATE


    bool updateCustomer(

        const std::string& id,

        const Customer& customer

    );



    // DELETE


    bool deleteCustomer(

        const std::string& id

    );



    // DISPLAY


    void displayCustomers() const;



};



#endif