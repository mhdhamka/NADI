#include "services/OrderService.h"

#include <iostream>
#include <iomanip>


using namespace std;



OrderService::OrderService()

{

}







Order OrderService::createOrder(

    const string& customerID

)

{

    Order order;



    order.generateOrderID();



    order.setCustomerID(customerID);



    order.setStatus("PENDING");



    orders.push_back(order);



    return order;

}










bool OrderService::addItem(

    const string& orderID,

    const Product& product,

    int quantity

)

{


    Order* order =

        getOrderByID(orderID);



    if(order == nullptr)

        return false;



    if(quantity <= 0)

        return false;



    OrderItem item;



    item.setProductID(

        product.getProductID()

    );


    item.setProductName(

        product.getName()

    );


    item.setPrice(

        product.getSellingPrice()

    );


    item.setQuantity(quantity);



    order->addItem(item);



    return true;

}










bool OrderService::removeItem(

    const string& orderID,

    const string& productID

)

{


    Order* order =

        getOrderByID(orderID);



    if(order == nullptr)

        return false;



    return order->removeItem(productID);

}









bool OrderService::updateQuantity(

    const string& orderID,

    const string& productID,

    int quantity

)

{


    Order* order =

        getOrderByID(orderID);



    if(order == nullptr)

        return false;



    return order->updateQuantity(

        productID,

        quantity

    );

}









double OrderService::calculateSubtotal(

    const string& orderID

)

{


    Order* order =

        getOrderByID(orderID);



    if(order == nullptr)

        return 0;



    return order->calculateSubtotal();

}









double OrderService::calculateTax(

    const string& orderID

)

{


    double subtotal =

        calculateSubtotal(orderID);



    return subtotal * 0.06;

}









double OrderService::calculateTotal(

    const string& orderID

)

{


    return calculateSubtotal(orderID)

        + calculateTax(orderID);

}









Order* OrderService::getOrderByID(

    const string& orderID

)

{


    for(auto& order : orders)

    {

        if(order.getOrderID()

            == orderID)

        {

            return &order;

        }

    }



    return nullptr;

}









vector<Order>

OrderService::getAllOrders() const

{

    return orders;

}









vector<Order>

OrderService::getCustomerOrders(

    const string& customerID

)

{

    vector<Order> result;



    for(auto& order : orders)

    {

        if(order.getCustomerID()

            == customerID)

        {

            result.push_back(order);

        }

    }



    return result;

}









bool OrderService::completeOrder(

    const string& orderID

)

{


    Order* order =

        getOrderByID(orderID);



    if(order == nullptr)

        return false;



    order->setStatus("COMPLETED");



    return true;

}









bool OrderService::displayOrder(

    const string& orderID

)

{

    Order* order =

        getOrderByID(orderID);



    if(order == nullptr)

        return false;



    order->displayOrder();



    return true;

}