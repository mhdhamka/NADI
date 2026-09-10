#ifndef RECEIPT_SERVICE_H
#define RECEIPT_SERVICE_H


#include <vector>
#include <string>


#include "../models/Receipt.h"
#include "../models/Order.h"
#include "../models/Payment.h"



class ReceiptService
{


private:


    std::vector<Receipt> receipts;


    int receiptCounter;



public:


    ReceiptService();



    // Generate receipt


    Receipt generateReceipt(

        const Order& order,

        const Payment& payment

    );



    // Search


    Receipt* getReceiptByID(

        const std::string& receiptID

    );



    Receipt* getReceiptByOrderID(

        const std::string& orderID

    );



    std::vector<Receipt>

    getAllReceipts() const;




    // Output


    void printReceipt(

        const std::string& receiptID

    );



    void displayReceiptHistory() const;



};



#endif