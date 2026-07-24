#include "services/ReceiptService.h"

#include <iostream>
#include <iomanip>


using namespace std;



ReceiptService::ReceiptService()

{

    receiptCounter = 1;

}







Receipt ReceiptService::generateReceipt(

    const Order& order,

    const Payment& payment

)

{


    Receipt receipt;



    string id =

        "RCPT-"

        + to_string(receiptCounter++);



    receipt.setReceiptID(id);



    receipt.setOrderID(

        order.getOrderID()

    );



    receipt.setPaymentID(

        payment.getPaymentID()

    );



    receipt.setCustomerID(

        order.getCustomerID()

    );



    receipt.setTotalAmount(

        payment.getAmount()

    );



    receipt.setStatus(

        "COMPLETED"

    );



    receipts.push_back(receipt);



    return receipt;

}









Receipt* ReceiptService::getReceiptByID(

    const string& receiptID

)

{


    for(auto& receipt : receipts)

    {

        if(receipt.getReceiptID()

            == receiptID)

        {

            return &receipt;

        }

    }



    return nullptr;

}









Receipt* ReceiptService::getReceiptByOrderID(

    const string& orderID

)

{


    for(auto& receipt : receipts)

    {

        if(receipt.getOrderID()

            == orderID)

        {

            return &receipt;

        }

    }



    return nullptr;

}









vector<Receipt>

ReceiptService::getAllReceipts() const

{

    return receipts;

}









void ReceiptService::printReceipt(

    const string& receiptID

)

{


    Receipt* receipt =

        getReceiptByID(receiptID);



    if(receipt == nullptr)

    {

        cout

        << "Receipt not found\n";

        return;

    }



    receipt->displayReceipt();

}









void ReceiptService::displayReceiptHistory() const

{

    cout

    << "\n========== RECEIPT HISTORY ==========\n";



    for(auto& receipt : receipts)

    {

        receipt.displayReceipt();

    }



    cout

    << "\n=====================================\n";

}