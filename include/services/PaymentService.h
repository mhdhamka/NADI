#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H


#include <vector>
#include <string>


#include "../models/Payment.h"



class PaymentService
{


private:


    std::vector<Payment> payments;



public:


    PaymentService();



    // Create payment
    Payment createPayment(
        const std::string& orderID,
        double amount,
        PaymentMethod method
    );


    // Payment processing
    bool processPayment(

        const std::string& paymentID

    );



    bool cancelPayment(

        const std::string& paymentID

    );



    bool refundPayment(

        const std::string& paymentID

    );





    // Searching


    Payment* getPaymentByID(

        const std::string& paymentID

    );



    Payment* getPaymentByOrderID(

        const std::string& orderID

    );




    std::vector<Payment>

    getAllPayments() const;




    // Reports


    double getTotalRevenue();



    void displayPayments() const;



};



#endif