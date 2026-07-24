#include "models/Receipt.h"

#include <iostream>
#include <iomanip>


using namespace std;



Receipt::Receipt()

{

    receiptID = "";

    orderID = "";


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
    const Order& order

)

{

    this->receiptID = receiptID;


    this->order = order;


    this->orderID =
        order.getOrderID();



    subtotal =
        order.getSubtotal();


    tax =
        order.getTax();


    discount =
        order.getDiscount();


    totalAmount =
        order.getTotalAmount();



    status =
        ReceiptStatus::Generated;



    createdAt =
        chrono::system_clock::now();

}





string Receipt::getReceiptID() const

{
    return receiptID;
}



string Receipt::getOrderID() const

{
    return orderID;
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
    << "\n=================================\n"
    << "       RAKYAT ELECTRONICS\n"
    << "             RECEIPT\n"
    << "=================================\n";


    cout
    << "Receipt ID: "
    << receiptID

    << "\nOrder ID: "
    << orderID;



    cout
    << "\n\nITEMS\n"
    << "---------------------------------\n";



    for(auto item : order.getItems())

    {

        cout

        << item.getProduct().getName()

        << " x "

        << item.getQuantity()

        << "    RM "

        << fixed
        << setprecision(2)

        << item.getSubtotal()

        << "\n";

    }



    cout
    << "---------------------------------\n"

    << "Subtotal: RM "
    << subtotal

    << "\nDiscount: RM "
    << discount

    << "\nTax: RM "
    << tax

    << "\nTOTAL: RM "
    << totalAmount


    << "\n=================================\n";

}





void Receipt::displayReceipt() const

{

    printReceipt();

}