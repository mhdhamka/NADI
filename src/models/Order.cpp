#include "models/Order.h"

#include <iostream>
#include <iomanip>


using namespace std;



Order::Order()

{

    orderID = "";

    customerID = "";

    status = OrderStatus::Pending;

    subtotal = 0;

    discount = 0;

    tax = 0;

    totalAmount = 0;

}



Order::Order(
    const string& orderID,
    const string& customerID
)

{

    this->orderID = orderID;

    this->customerID = customerID;

    status = OrderStatus::Pending;

    subtotal = 0;

    discount = 0;

    tax = 0;

    totalAmount = 0;

}


string orderStatusToString(OrderStatus status)
{
    switch(status)
    {
        case OrderStatus::Pending:
            return "PENDING";

        case OrderStatus::Completed:
            return "COMPLETED";

        case OrderStatus::Cancelled:
            return "CANCELLED";

        default:
            return "UNKNOWN";
    }
}


void Order::generateOrderID()

{

    static int counter = 1;


    orderID =
        "ORD-"
        +
        to_string(counter++);

}




string Order::getOrderID() const

{

    return orderID;

}




void Order::setCustomerID(
    const string& customerID
)

{

    this->customerID = customerID;

}




string Order::getCustomerID() const

{

    return customerID;

}




void Order::setStatus(
    OrderStatus status
)
{
    this->status = status;
}




OrderStatus Order::getStatus() const
{
    return status;
}




void Order::addItem(
    const OrderItem& item
)

{

    items.push_back(item);


    calculateTotal();

}




bool Order::removeItem(
    const string& productID
)

{

    for(auto iterator = items.begin();
        iterator != items.end();
        iterator++)

    {


        if(iterator->getProduct().getProductID()
            == productID)

        {

            items.erase(iterator);


            calculateTotal();


            return true;

        }

    }


    return false;

}




bool Order::updateQuantity(
    const string& productID,
    int quantity
)

{

    for(auto& item : items)

    {

        if(item.getProduct().getProductID()
            == productID)

        {

            item.setQuantity(quantity);


            calculateTotal();


            return true;

        }

    }


    return false;

}




double Order::calculateSubtotal() const

{

    double total = 0;


    for(const auto& item : items)

    {

        total += item.getSubtotal();

    }


    return total;

}




void Order::calculateTotal()

{

    subtotal = calculateSubtotal();


    totalAmount =
        subtotal
        -
        discount
        +
        tax;


    if(totalAmount < 0)

        totalAmount = 0;

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

    << customerID

    << "\nStatus: "

    << orderStatusToString(status);



    cout

    << "\n\nItems:\n";



    for(const auto& item : items)

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