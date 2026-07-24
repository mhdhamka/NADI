#ifndef REPORT_SERVICE_H
#define REPORT_SERVICE_H


#include <vector>
#include <string>


#include "../models/Order.h"
#include "../models/Product.h"
#include "../models/Customer.h"
#include "../models/Payment.h"



class ReportService
{


private:


    std::vector<Order> orders;

    std::vector<Product> products;

    std::vector<Customer> customers;

    std::vector<Payment> payments;



public:


    ReportService();



    ReportService(

        const std::vector<Order>& orders,

        const std::vector<Product>& products,

        const std::vector<Customer>& customers,

        const std::vector<Payment>& payments

    );




    // Sales Report


    double calculateTotalSales();



    double calculateDailySales();



    double calculateMonthlySales();




    // Product Report


    Product getBestSellingProduct();



    std::vector<Product>
    getLowStockProducts();



    double calculateInventoryValue();




    // Customer Report


    Customer getTopCustomer();



    void generateSalesReport();



    void generateInventoryReport();



    void generateCustomerReport();




    // Export


    bool exportCSV(

        const std::string& filename

    );



};



#endif