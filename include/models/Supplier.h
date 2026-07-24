#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <chrono>


enum class SupplierStatus
{
    Active,
    Inactive,
    Blacklisted
};



class Supplier
{

private:

    std::string supplierID;


    std::string companyName;


    std::string contactPerson;


    std::string phone;


    std::string email;


    std::string address;



    SupplierStatus status;



    std::chrono::system_clock::time_point createdAt;



public:


    Supplier();



    Supplier(
        const std::string& supplierID,
        const std::string& companyName,
        const std::string& contactPerson,
        const std::string& phone,
        const std::string& email,
        const std::string& address
    );



    // Getters

    std::string getSupplierID() const;


    std::string getCompanyName() const;


    std::string getContactPerson() const;


    std::string getPhone() const;


    std::string getEmail() const;


    std::string getAddress() const;


    SupplierStatus getStatus() const;



    // Setters

    void setCompanyName(
        const std::string& name
    );


    void setContactPerson(
        const std::string& name
    );


    void setPhone(
        const std::string& phone
    );


    void setEmail(
        const std::string& email
    );


    void setAddress(
        const std::string& address
    );



    // Supplier management

    void activate();


    void deactivate();


    void blacklist();



    bool isActive() const;



    void displaySupplier() const;


};


#endif