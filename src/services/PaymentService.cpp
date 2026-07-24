#include "services/PaymentService.h"

#include <iostream>


using namespace std;



PaymentService::PaymentService()

{

}







Payment PaymentService::createPayment(

    const string& orderID,

    double amount,

    const string& method

)

{

    Payment payment;



    payment.generatePaymentID();



    payment.setOrderID(orderID);



    payment.setAmount(amount);



    payment.setPaymentMethod(method);



    payment.setStatus("PENDING");



    payments.push_back(payment);



    return payment;

}









bool PaymentService::processPayment(

    const string& paymentID

)

{

    Payment* payment =

        getPaymentByID(paymentID);



    if(payment == nullptr)

        return false;



    payment->setStatus("PAID");



    return true;

}









bool PaymentService::cancelPayment(

    const string& paymentID

)

{

    Payment* payment =

        getPaymentByID(paymentID);



    if(payment == nullptr)

        return false;



    payment->setStatus("CANCELLED");



    return true;

}









bool PaymentService::refundPayment(

    const string& paymentID

)

{

    Payment* payment =

        getPaymentByID(paymentID);



    if(payment == nullptr)

        return false;



    payment->setStatus("REFUNDED");



    return true;

}









Payment* PaymentService::getPaymentByID(

    const string& paymentID

)

{

    for(auto& payment : payments)

    {

        if(payment.getPaymentID()

            == paymentID)

        {

            return &payment;

        }

    }



    return nullptr;

}









Payment* PaymentService::getPaymentByOrderID(

    const string& orderID

)

{

    for(auto& payment : payments)

    {

        if(payment.getOrderID()

            == orderID)

        {

            return &payment;

        }

    }



    return nullptr;

}









vector<Payment>

PaymentService::getAllPayments() const

{

    return payments;

}









double PaymentService::getTotalRevenue()

{

    double total = 0;



    for(auto& payment : payments)

    {


        if(payment.getStatus()

            == "PAID")

        {

            total += payment.getAmount();

        }

    }



    return total;

}



void PaymentService::displayPayments() const

{

    cout

    << "\n========== PAYMENT HISTORY ==========\n";



    for(auto& payment : payments)

    {

        payment.displayPayment();

    }



    cout

    << "\n=====================================\n";

}