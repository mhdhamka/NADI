#include "models/Customer.h"

#include <iostream>


using namespace std;



Customer::Customer()

{

    customerID = "";

    name = "";

    phone = "";

    email = "";

    address = "";


    loyaltyPoints = 0;


    status = CustomerStatus::Active;


    createdAt =
        chrono::system_clock::now();

}



Customer::Customer(
    const string& customerID,
    const string& name,
    const string& phone,
    const string& email,
    const string& address

)

{

    this->customerID = customerID;

    this->name = name;

    this->phone = phone;

    this->email = email;

    this->address = address;



    loyaltyPoints = 0;


    status = CustomerStatus::Active;



    createdAt =
        chrono::system_clock::now();

}





string Customer::getCustomerID() const
{
    return customerID;
}



string Customer::getName() const
{
    return name;
}



string Customer::getPhone() const
{
    return phone;
}



string Customer::getEmail() const
{
    return email;
}



string Customer::getAddress() const
{
    return address;
}



int Customer::getLoyaltyPoints() const
{
    return loyaltyPoints;
}



CustomerStatus Customer::getStatus() const
{
    return status;
}





void Customer::setName(
    const string& name
)

{
    this->name = name;
}




void Customer::setPhone(
    const string& phone
)

{
    this->phone = phone;
}




void Customer::setEmail(
    const string& email
)

{
    this->email = email;
}




void Customer::setAddress(
    const string& address
)

{
    this->address = address;
}





void Customer::addLoyaltyPoints(
    int points
)

{

    if(points > 0)
    {
        loyaltyPoints += points;
    }

}




bool Customer::redeemPoints(
    int points
)

{

    if(points <= 0)
        return false;


    if(points > loyaltyPoints)
        return false;


    loyaltyPoints -= points;


    return true;

}





void Customer::activate()

{
    status = CustomerStatus::Active;
}




void Customer::suspend()

{
    status = CustomerStatus::Suspended;
}




void Customer::remove()

{
    status = CustomerStatus::Deleted;
}





bool Customer::isActive() const

{
    return status == CustomerStatus::Active;
}





void Customer::displayCustomer() const

{

    cout
    << "\n========== CUSTOMER ==========\n"

    << "ID: "
    << customerID

    << "\nName: "
    << name

    << "\nPhone: "
    << phone

    << "\nEmail: "
    << email

    << "\nAddress: "
    << address

    << "\nLoyalty Points: "
    << loyaltyPoints

    << "\nStatus: ";



    switch(status)
    {

        case CustomerStatus::Active:
            cout << "Active";
            break;


        case CustomerStatus::Suspended:
            cout << "Suspended";
            break;


        case CustomerStatus::Deleted:
            cout << "Deleted";
            break;

    }



    cout
    << "\n==============================\n";

}