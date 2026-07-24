#include "models/Order.h"

#include <iostream>
#include <iomanip>


using namespace std;



Order::Order()
{

    orderID = "";

    customerID = "";

    subtotal = 0;

    discount = 0;

    tax = 0;

    totalAmount = 0;


    status = OrderStatus::Pending;


    createdAt =
        chrono::system_clock::now();

}



Order::Order(
    const string& orderID,
    const string& customerID
)

{

    this->orderID = orderID;

    this->customerID = customerID;


    subtotal = 0;

    discount = 0;

    tax = 0;

    totalAmount = 0;


    status = OrderStatus::Pending;


    createdAt =
        chrono::system_clock::now();

}




void Order::calculateTotal()

{

    subtotal = 0;


    for(auto& item : items)
    {
        subtotal += item.getSubtotal();
    }


    totalAmount =
        subtotal
        -
        discount
        +
        tax;



    if(totalAmount < 0)
        totalAmount = 0;

}




void Order::addItem(
    const OrderItem& item
)

{

    items.push_back(item);


    calculateTotal();

}




bool Order::removeItem(
    const string& orderItemID
)

{

    for(auto iterator = items.begin();
        iterator != items.end();
        iterator++)

    {

        if(iterator->getOrderItemID()
            == orderItemID)

        {

            items.erase(iterator);


            calculateTotal();


            return true;

        }

    }


    return false;

}




void Order::clearItems()

{

    items.clear();


    calculateTotal();

}




double Order::getSubtotal() const
{
    return subtotal;
}



double Order::getDiscount() const
{
    return discount;
}



double Order::getTax() const
{
    return tax;
}



double Order::getTotalAmount() const
{
    return totalAmount;
}




void Order::applyDiscount(
    double amount
)

{

    if(amount > 0)
    {
        discount = amount;

        calculateTotal();
    }

}




void Order::applyTax(
    double amount
)

{

    if(amount > 0)
    {
        tax = amount;

        calculateTotal();
    }

}




void Order::completeOrder()

{

    status =
        OrderStatus::Completed;

}




void Order::cancelOrder()

{

    status =
        OrderStatus::Cancelled;

}




OrderStatus Order::getStatus() const
{
    return status;
}




string Order::getOrderID() const
{
    return orderID;
}



string Order::getCustomerID() const
{
    return customerID;
}



vector<OrderItem> Order::getItems() const
{
    return items;
}




void Order::displayOrder() const

{

    cout
    << "\n=========== ORDER ===========\n"

    << "Order ID: "
    << orderID

    << "\nCustomer ID: "
    << customerID;


    cout
    << "\n\nItems:\n";


    for(auto& item : items)
    {
        item.displayItem();
    }



    cout
    << "\nSubtotal: RM "
    << fixed
    << setprecision(2)
    << subtotal

    << "\nDiscount: RM "
    << discount

    << "\nTax: RM "
    << tax

    << "\nTotal: RM "
    << totalAmount


    << "\n=============================\n";

}