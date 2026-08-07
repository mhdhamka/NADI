#include "models/OrderItem.h"

#include <iostream>
#include <iomanip>


using namespace std;



OrderItem::OrderItem()
{

    orderItemID = "";

    quantity = 0;

    unitPrice = 0;

    discount = 0;

    subtotal = 0;

}



OrderItem::OrderItem(
    const string& orderItemID,
    const Product& product,
    int quantity

)

{

    this->orderItemID = orderItemID;

    this->product = product;

    this->quantity = quantity;


    this->unitPrice =
        product.getSellingPrice();


    discount = 0;


    calculateSubtotal();

}





void OrderItem::calculateSubtotal()

{

    subtotal =
        (unitPrice * quantity)
        -
        discount;


    if(subtotal < 0)
        subtotal = 0;

}




string OrderItem::getOrderItemID() const
{
    return orderItemID;
}



Product OrderItem::getProduct() const
{
    return product;
}



int OrderItem::getQuantity() const
{
    return quantity;
}



double OrderItem::getUnitPrice() const
{
    return unitPrice;
}



double OrderItem::getDiscount() const
{
    return discount;
}



double OrderItem::getSubtotal() const
{
    return subtotal;
}




void OrderItem::setQuantity(
    int quantity
)

{

    if(quantity > 0)
    {
        this->quantity = quantity;

        calculateSubtotal();
    }

}




void OrderItem::increaseQuantity(
    int amount
)

{

    if(amount > 0)
    {
        quantity += amount;

        calculateSubtotal();
    }

}




void OrderItem::decreaseQuantity(
    int amount
)

{

    if(amount > 0 &&
       amount <= quantity)

    {

        quantity -= amount;

        calculateSubtotal();

    }

}




void OrderItem::applyDiscount(
    double discountAmount
)

{

    if(discountAmount > 0)
    {
        discount = discountAmount;

        calculateSubtotal();
    }

}




void OrderItem::displayItem() const

{

    cout
    << "\n========== ORDER ITEM ==========\n"

    << "Product: "
    << product.getName()

    << "\nQuantity: "
    << quantity

    << "\nUnit Price: RM "
    << fixed
    << setprecision(2)
    << unitPrice

    << "\nDiscount: RM "
    << discount

    << "\nSubtotal: RM "
    << subtotal

    << "\n================================\n";

}

