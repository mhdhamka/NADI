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



    // =========================
    // ID
    // =========================

    void generateOrderID();


    std::string getOrderID() const;



    // =========================
    // Customer
    // =========================

    void setCustomerID(
        const std::string& customerID
    );


    std::string getCustomerID() const;



    // =========================
    // Items
    // =========================

    void addItem(
        const OrderItem& item
    );


    bool removeItem(
        const std::string& productID
    );


    bool updateQuantity(
        const std::string& productID,
        int quantity
    );


    void clearItems();



    std::vector<OrderItem> getItems() const;



    // =========================
    // Calculation
    // =========================

    double getSubtotal() const;


    double getDiscount() const;


    double getTax() const;


    double getTotalAmount() const;



    // Compatibility with OrderService.cpp

    double calculateSubtotal() const;


    double calculateTotal() const;



    // =========================
    // Status
    // =========================

    void setStatus(
        OrderStatus status
    );

    OrderStatus getStatus() const;

    void completeOrder();
    void cancelOrder();


    OrderStatus getOrderStatus() const;


    // =========================
    // Discount / Tax
    // =========================

    void applyDiscount(
        double amount
    );


    void applyTax(
        double amount
    );



    // =========================
    // Display
    // =========================

    void displayOrder() const;


};


#endif