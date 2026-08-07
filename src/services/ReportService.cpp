#include "services/ReportService.h"

#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;




ReportService::ReportService()

{

}







ReportService::ReportService(

    const vector<Order>& orders,

    const vector<Product>& products,

    const vector<Customer>& customers,

    const vector<Payment>& payments

)

{

    this->orders = orders;

    this->products = products;

    this->customers = customers;

    this->payments = payments;

}








double ReportService::calculateTotalSales()

{

    double total = 0;



    for(auto& payment : payments)

    {

        if(payment.getStatus() == PaymentStatus::Completed)

        {

            total += payment.getAmount();

        }

    }



    return total;

}









double ReportService::calculateDailySales()

{

    // Future:

    // compare transaction date

    // with current date


    return calculateTotalSales();

}









double ReportService::calculateMonthlySales()

{

    // Future:

    // filter by month


    return calculateTotalSales();

}









Product ReportService::getBestSellingProduct()

{

    Product result;



    int highest = 0;



    for(auto& product : products)

    {

        if(product.getTotalSold() > highest)

        {

            highest = product.getTotalSold();

            result = product;

        }

    }



    return result;

}









vector<Product>

ReportService::getLowStockProducts()

{

    vector<Product> result;



    for(auto& product : products)

    {

        if(product.getStockQuantity() < 10)

        {

            result.push_back(product);

        }

    }



    return result;

}









double ReportService::calculateInventoryValue()

{

    double value = 0;



    for(auto& product : products)

    {

        value +=

        product.getCostPrice()

        *

        product.getStockQuantity();

    }



    return value;

}









Customer ReportService::getTopCustomer()

{

    Customer result;



    double highest = 0;



    for(auto& customer : customers)

    {

        if(customer.getTotalSpent() > highest)

        {

            highest = customer.getTotalSpent();

            result = customer;

        }

    }



    return result;

}









void ReportService::generateSalesReport()

{

    cout << "\n========== SALES REPORT ==========\n";


    cout

    << fixed

    << setprecision(2);


    cout

    << "Total Sales: RM "

    << calculateTotalSales()

    << endl;



    cout

    << "==================================\n";

}









void ReportService::generateInventoryReport()

{

    cout

    << "\n========== INVENTORY REPORT ==========\n";



    cout

    << "Inventory Value: RM "

    << calculateInventoryValue()

    << endl;



    cout

    << "\nLow Stock Items:\n";



    for(auto& product : getLowStockProducts())

    {

        cout

        << product.getName()

        << endl;

    }



}









void ReportService::generateCustomerReport()

{

    cout

    << "\n========== CUSTOMER REPORT ==========\n";



    Customer customer = getTopCustomer();



    cout

    << "Top Customer:\n";



    customer.displayCustomer();



}









bool ReportService::exportCSV(

    const string& filename

)

{

    ofstream file(filename);



    if(!file)

        return false;



    file

    << "Report Type,Value\n";



    file

    << "Total Sales,"

    << calculateTotalSales()

    << "\n";



    file.close();



    return true;

}