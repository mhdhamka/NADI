#ifndef ORDER_SERVICE_H
#define ORDER_SERVICE_H


#include <vector>
#include <string>


#include "../models/Order.h"
#include "../models/Product.h"



class OrderService
{


private:


    std::vector<Order> orders;



public:


    OrderService();



    // Order creation


    Order createOrder(

        const std::string& customerID

    );



    bool cancelOrder(

        const std::string& orderID

    );



    // Item management


    bool addItem(

        const std::string& orderID,

        const Product& product,

        int quantity

    );



    bool removeItem(

        const std::string& orderID,

        const std::string& productID

    );



    bool updateQuantity(

        const std::string& orderID,

        const std::string& productID,

        int quantity

    );



    // Calculation


    double calculateSubtotal(

        const std::string& orderID

    );



    double calculateTax(

        const std::string& orderID

    );



    double calculateTotal(

        const std::string& orderID

    );



    // Searching


    Order* getOrderByID(

        const std::string& orderID

    );



    std::vector<Order>

    getAllOrders() const;



    std::vector<Order>

    getCustomerOrders(

        const std::string& customerID

    );



    // Status


    bool completeOrder(

        const std::string& orderID

    );



    bool displayOrder(

        const std::string& orderID

    );



};



#endif