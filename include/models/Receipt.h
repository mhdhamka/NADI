#ifndef RECEIPT_H
#define RECEIPT_H

#include <string>
#include <chrono>


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

    std::string paymentID;

    std::string customerID;


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
        const std::string& orderID,
        const std::string& paymentID,
        const std::string& customerID
    );



    // Getters

    std::string getReceiptID() const;


    std::string getOrderID() const;


    std::string getPaymentID() const;


    std::string getCustomerID() const;


    double getSubtotal() const;


    double getTax() const;


    double getDiscount() const;


    double getTotalAmount() const;



    ReceiptStatus getStatus() const;



    // Setters


    void setReceiptID(
        const std::string& receiptID
    );


    void setOrderID(
        const std::string& orderID
    );


    void setPaymentID(
        const std::string& paymentID
    );


    void setCustomerID(
        const std::string& customerID
    );


    void setSubtotal(
        double subtotal
    );


    void setTax(
        double tax
    );


    void setDiscount(
        double discount
    );


    void setTotalAmount(
        double amount
    );


    void setStatus(
        ReceiptStatus status
    );



    // Actions


    void printReceipt() const;


    void markPrinted();


    void cancelReceipt();


    void displayReceipt() const;


};



#endif