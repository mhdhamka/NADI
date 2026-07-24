#include "models/Payment.h"

#include <iostream>
#include <iomanip>



using namespace std;




Payment::Payment()

{

    paymentID = "";

    orderID = "";

    amount = 0;


    method =
        PaymentMethod::Cash;



    status =
        PaymentStatus::Pending;



    paymentDate =
        chrono::system_clock::now();

}





Payment::Payment(

    const string& paymentID,

    const string& orderID,

    double amount,

    PaymentMethod method

)

{


    this->paymentID = paymentID;


    this->orderID = orderID;


    this->amount = amount;


    this->method = method;



    status =
        PaymentStatus::Pending;



    paymentDate =
        chrono::system_clock::now();

}







string Payment::getPaymentID() const

{

    return paymentID;

}





string Payment::getOrderID() const

{

    return orderID;

}





double Payment::getAmount() const

{

    return amount;

}





PaymentMethod Payment::getMethod() const

{

    return method;

}





PaymentStatus Payment::getStatus() const

{

    return status;

}








bool Payment::processPayment()

{


    /*
        In a real system this connects to:

        - bank API
        - card gateway
        - payment provider

        Example:
        iPay88
        Stripe
        ToyyibPay

    */


    status =
        PaymentStatus::Completed;



    return true;

}






void Payment::refundPayment()

{

    if(status == PaymentStatus::Completed)

    {

        status =
            PaymentStatus::Refunded;

    }

}






void Payment::failPayment()

{

    status =
        PaymentStatus::Failed;

}






bool Payment::isSuccessful() const

{

    return status ==
        PaymentStatus::Completed;

}







void Payment::displayPayment() const

{

    cout
    << "\n========== PAYMENT ==========\n";


    cout
    << "Payment ID: "
    << paymentID;



    cout
    << "\nOrder ID: "
    << orderID;



    cout
    << "\nAmount: RM "
    << fixed
    << setprecision(2)
    << amount;



    cout
    << "\nMethod: ";



    switch(method)

    {

        case PaymentMethod::Cash:

            cout<<"Cash";

            break;



        case PaymentMethod::CreditCard:

            cout<<"Credit Card";

            break;



        case PaymentMethod::DebitCard:

            cout<<"Debit Card";

            break;



        case PaymentMethod::OnlineBanking:

            cout<<"Online Banking";

            break;



        case PaymentMethod::EWallet:

            cout<<"E-Wallet";

            break;

    }




    cout
    << "\nStatus: ";



    switch(status)

    {

        case PaymentStatus::Pending:

            cout<<"Pending";

            break;



        case PaymentStatus::Completed:

            cout<<"Completed";

            break;



        case PaymentStatus::Failed:

            cout<<"Failed";

            break;



        case PaymentStatus::Refunded:

            cout<<"Refunded";

            break;

    }



    cout
    << "\n=============================\n";


}