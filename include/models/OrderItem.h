#ifndef ORDER_ITEM_H
#define ORDER_ITEM_H

#include <string>

#include "Product.h"


class OrderItem
{

private:

    std::string orderItemID;


    Product product;


    int quantity;


    // Snapshot price when purchased
    double unitPrice;


    double discount;


    double subtotal;



    void calculateSubtotal();



public:


    OrderItem();


    OrderItem(
        const std::string& orderItemID,
        const Product& product,
        int quantity
    );



    // Getters

    std::string getOrderItemID() const;


    Product getProduct() const;


    int getQuantity() const;


    double getUnitPrice() const;


    double getDiscount() const;


    double getSubtotal() const;



    // Setters

    void setQuantity(
        int quantity
    );


    void increaseQuantity(
        int amount
    );


    void decreaseQuantity(
        int amount
    );



    void applyDiscount(
        double discountAmount
    );



    void displayItem() const;


};



#endif