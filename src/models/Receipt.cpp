#include "models/Receipt.h"

#include <iostream>
#include <iomanip>


using namespace std;



Receipt::Receipt()

{

    receiptID = "";

    orderID = "";

    paymentID = "";

    customerID = "";


    subtotal = 0;

    tax = 0;

    discount = 0;

    totalAmount = 0;


    status =
        ReceiptStatus::Generated;


    createdAt =
        chrono::system_clock::now();

}





Receipt::Receipt(
    const string& receiptID,
    const string& orderID,
    const string& paymentID,
    const string& customerID
)

{

    this->receiptID = receiptID;

    this->orderID = orderID;

    this->paymentID = paymentID;

    this->customerID = customerID;


    subtotal = 0;

    tax = 0;

    discount = 0;

    totalAmount = 0;


    status =
        ReceiptStatus::Generated;


    createdAt =
        chrono::system_clock::now();

}





// Getters


string Receipt::getReceiptID() const
{
    return receiptID;
}



string Receipt::getOrderID() const
{
    return orderID;
}



string Receipt::getPaymentID() const
{
    return paymentID;
}



string Receipt::getCustomerID() const
{
    return customerID;
}



double Receipt::getSubtotal() const
{
    return subtotal;
}



double Receipt::getTax() const
{
    return tax;
}



double Receipt::getDiscount() const
{
    return discount;
}



double Receipt::getTotalAmount() const
{
    return totalAmount;
}



ReceiptStatus Receipt::getStatus() const
{
    return status;
}





// Setters


void Receipt::setReceiptID(
    const string& receiptID
)
{
    this->receiptID = receiptID;
}



void Receipt::setOrderID(
    const string& orderID
)
{
    this->orderID = orderID;
}



void Receipt::setPaymentID(
    const string& paymentID
)
{
    this->paymentID = paymentID;
}



void Receipt::setCustomerID(
    const string& customerID
)
{
    this->customerID = customerID;
}



void Receipt::setSubtotal(
    double subtotal
)
{
    this->subtotal = subtotal;
}



void Receipt::setTax(
    double tax
)
{
    this->tax = tax;
}



void Receipt::setDiscount(
    double discount
)
{
    this->discount = discount;
}



void Receipt::setTotalAmount(
    double amount
)
{
    this->totalAmount = amount;
}



void Receipt::setStatus(
    ReceiptStatus status
)
{
    this->status = status;
}





// Actions


void Receipt::markPrinted()

{
    status =
        ReceiptStatus::Printed;
}





void Receipt::cancelReceipt()

{
    status =
        ReceiptStatus::Cancelled;
}





void Receipt::printReceipt() const

{

    cout
    << "\n==========================================\n"
    << "       NETWORKED AUTOMATED DIGITAL INVENTORY SYSTEM\n"
    << "             RECEIPT\n"
    << "==========================================\n";


    cout

    << "Receipt ID: "
    << receiptID

    << "\nOrder ID: "
    << orderID

    << "\nPayment ID: "
    << paymentID

    << "\nCustomer ID: "
    << customerID;



    cout
    << "\n\n---------------------------------\n"

    << "Subtotal: RM "
    << fixed
    << setprecision(2)
    << subtotal

    << "\nDiscount: RM "
    << discount

    << "\nTax: RM "
    << tax

    << "\nTOTAL: RM "
    << totalAmount


    << "\n---------------------------------\n"

    << "Status: ";


    switch(status)
    {

        case ReceiptStatus::Generated:
            cout << "Generated";
            break;


        case ReceiptStatus::Printed:
            cout << "Printed";
            break;


        case ReceiptStatus::Cancelled:
            cout << "Cancelled";
            break;

    }


    cout
    << "\n=================================\n";

}





void Receipt::displayReceipt() const

{
    printReceipt();
}