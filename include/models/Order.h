#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <chrono>

#include "OrderItem.h"


enum class OrderStatus
{
    Pending,
    Processing,
    Completed,
    Cancelled
};



class Order
{

private:

    std::string orderID;


    std::string customerID;


    std::vector<OrderItem> items;


    double subtotal;


    double discount;


    double tax;


    double totalAmount;



    OrderStatus status;


    std::chrono::system_clock::time_point createdAt;



    void calculateTotal();



public:


    Order();



    Order(
        const std::string& orderID,
        const std::string& customerID
    );



    // Item management

    void addItem(
        const OrderItem& item
    );


    bool removeItem(
        const std::string& orderItemID
    );



    void clearItems();



    // Calculation

    double getSubtotal() const;


    double getDiscount() const;


    double getTax() const;


    double getTotalAmount() const;



    // Status

    void completeOrder();


    void cancelOrder();


    OrderStatus getStatus() const;



    // Information

    std::string getOrderID() const;


    std::string getCustomerID() const;


    std::vector<OrderItem> getItems() const;



    void applyDiscount(
        double amount
    );


    void applyTax(
        double amount
    );



    void displayOrder() const;


};


#endif