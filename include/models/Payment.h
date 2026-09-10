#ifndef PAYMENT_H
#define PAYMENT_H


#include <string>
#include <chrono>



enum class PaymentMethod
{

    Cash,

    CreditCard,

    DebitCard,

    OnlineBanking,

    EWallet

};



enum class PaymentStatus
{

    Pending,

    Completed,

    Failed,

    Refunded

};





class Payment
{

private:


    std::string paymentID;


    std::string orderID;


    double amount;



    PaymentMethod method;


    PaymentStatus status;



    std::chrono::system_clock::time_point paymentDate;



public:


    Payment();



    Payment(

        const std::string& paymentID,

        const std::string& orderID,

        double amount,

        PaymentMethod method

    );




    // ID
    void generatePaymentID();



    // Getters
    std::string getPaymentID() const;
    std::string getOrderID() const;


    double getAmount() const;


    PaymentMethod getMethod() const;
    PaymentStatus getStatus() const;


    // Setters
    void setOrderID(
        const std::string& orderID
    );

    void setAmount(
        double amount
    );

    void setMethod(
        PaymentMethod method
    );

    void setStatus(
        PaymentStatus status
    );


    // Payment actions
    bool processPayment();
    void refundPayment();
    void failPayment();
    bool isSuccessful() const;
    void displayPayment() const;


};



#endif