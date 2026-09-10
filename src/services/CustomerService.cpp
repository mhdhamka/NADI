#include "services/CustomerService.h"

#include <iostream>
#include <algorithm>



using namespace std;





CustomerService::CustomerService()

{

}







bool CustomerService::addCustomer(

    const Customer& customer

)

{

    for(auto& existing : customers)

    {

        if(existing.getCustomerID()

            == customer.getCustomerID())

        {

            return false;

        }

    }



    customers.push_back(customer);



    return true;

}








Customer* CustomerService::getCustomerByID(

    const string& id

)

{

    for(auto& customer : customers)

    {

        if(customer.getCustomerID()
            == id)

        {

            return &customer;

        }

    }



    return nullptr;

}









vector<Customer>

CustomerService::getAllCustomers() const

{

    return customers;

}








vector<Customer>

CustomerService::searchCustomer(

    const string& keyword

)

{

    vector<Customer> result;



    for(auto& customer : customers)

    {


        if(

            customer.getName()

            .find(keyword)

            != string::npos

        )

        {

            result.push_back(customer);

        }


    }



    return result;

}









bool CustomerService::updateCustomer(

    const string& id,

    const Customer& customer

)

{


    Customer* existing =

        getCustomerByID(id);



    if(existing == nullptr)

        return false;



    *existing = customer;



    return true;

}









bool CustomerService::deleteCustomer(

    const string& id

)

{


    auto iterator =

    remove_if(

        customers.begin(),

        customers.end(),

        [&](Customer& customer)

        {

            return customer.getCustomerID()

                == id;

        }

    );



    if(iterator == customers.end())

        return false;



    customers.erase(

        iterator,

        customers.end()

    );



    return true;

}









void CustomerService::displayCustomers() const

{

    cout

    << "\n========== CUSTOMERS ==========\n";



    for(auto& customer : customers)

    {

        customer.displayCustomer();

    }



    cout

    << "\n===============================\n";

}