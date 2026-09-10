#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <chrono>


enum class CustomerStatus
{
    Active,
    Suspended,
    Deleted
};



class Customer
{

private:

    std::string customerID;


    std::string name;


    std::string phone;


    std::string email;


    std::string address;

    int loyaltyPoints;
    double totalSpent;
    CustomerStatus status;

    std::chrono::system_clock::time_point createdAt;



public:


    Customer();



    Customer(
        const std::string& customerID,
        const std::string& name,
        const std::string& phone,
        const std::string& email,
        const std::string& address
    );



    // Getters
    std::string getCustomerID() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getAddress() const;



    int getLoyaltyPoints() const;

    double getTotalSpent() const;

    CustomerStatus getStatus() const;




    // Setters

    void setName(
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


    void addSpentAmount(
        double amount
    );



    // Loyalty system

    void addLoyaltyPoints(
        int points
    );


    bool redeemPoints(
        int points
    );



    // Account management

    void activate();


    void suspend();


    void remove();



    bool isActive() const;



    void displayCustomer() const;


};


#endif