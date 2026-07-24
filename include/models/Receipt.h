#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <vector>
#include <chrono>

#include "Order.h"



enum class ReceiptStatus
{
    Generated,
    Printed,
    Cancelled
};



class Receipt
{

private:


    std::string receiptID;


    std::string orderID;


    Order order;



    double subtotal;


    double tax;


    double discount;


    double totalAmount;



    ReceiptStatus status;



    std::chrono::system_clock::time_point createdAt;



public:


    Receipt();



    Receipt(
        const std::string& receiptID,
        const Order& order
    );



    // Getters

    std::string getReceiptID() const;


    std::string getOrderID() const;


    double getSubtotal() const;


    double getTax() const;


    double getDiscount() const;


    double getTotalAmount() const;


    ReceiptStatus getStatus() const;



    // Actions

    void printReceipt() const;


    void markPrinted();


    void cancelReceipt();



    void displayReceipt() const;


};


#endif