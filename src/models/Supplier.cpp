#include "models/Supplier.h"

#include <iostream>


using namespace std;



Supplier::Supplier()

{

    supplierID = "";

    companyName = "";

    contactPerson = "";

    phone = "";

    email = "";

    address = "";


    status = SupplierStatus::Active;


    createdAt =
        chrono::system_clock::now();

}





Supplier::Supplier(
    const string& supplierID,
    const string& companyName,
    const string& contactPerson,
    const string& phone,
    const string& email,
    const string& address

)

{

    this->supplierID = supplierID;


    this->companyName = companyName;


    this->contactPerson = contactPerson;


    this->phone = phone;


    this->email = email;


    this->address = address;



    status = SupplierStatus::Active;



    createdAt =
        chrono::system_clock::now();

}





string Supplier::getSupplierID() const
{
    return supplierID;
}



string Supplier::getCompanyName() const
{
    return companyName;
}



string Supplier::getContactPerson() const
{
    return contactPerson;
}



string Supplier::getPhone() const
{
    return phone;
}



string Supplier::getEmail() const
{
    return email;
}



string Supplier::getAddress() const
{
    return address;
}



SupplierStatus Supplier::getStatus() const
{
    return status;
}





void Supplier::setCompanyName(
    const string& name
)

{
    companyName = name;
}




void Supplier::setContactPerson(
    const string& name
)

{
    contactPerson = name;
}




void Supplier::setPhone(
    const string& phone
)

{
    this->phone = phone;
}




void Supplier::setEmail(
    const string& email
)

{
    this->email = email;
}




void Supplier::setAddress(
    const string& address
)

{
    this->address = address;
}





void Supplier::activate()

{
    status = SupplierStatus::Active;
}




void Supplier::deactivate()

{
    status = SupplierStatus::Inactive;
}




void Supplier::blacklist()

{
    status = SupplierStatus::Blacklisted;
}





bool Supplier::isActive() const

{
    return status == SupplierStatus::Active;
}





void Supplier::displaySupplier() const

{

    cout
    << "\n========== SUPPLIER ==========\n"


    << "Supplier ID: "
    << supplierID


    << "\nCompany: "
    << companyName


    << "\nContact Person: "
    << contactPerson


    << "\nPhone: "
    << phone


    << "\nEmail: "
    << email


    << "\nAddress: "
    << address



    << "\nStatus: ";



    switch(status)

    {

        case SupplierStatus::Active:
            cout << "Active";
            break;


        case SupplierStatus::Inactive:
            cout << "Inactive";
            break;


        case SupplierStatus::Blacklisted:
            cout << "Blacklisted";
            break;

    }



    cout
    << "\n==============================\n";

}