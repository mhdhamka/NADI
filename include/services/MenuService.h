#ifndef MENU_SERVICE_H
#define MENU_SERVICE_H

<<<<<<< HEAD
=======

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
#include "AuthenticationService.h"
#include "ProductService.h"
#include "OrderService.h"
#include "ReportService.h"
#include "InventoryService.h"

<<<<<<< HEAD
class MenuService
{
private:
    AuthenticationService* auth;
    ProductService* productService;
    OrderService* orderService;
    ReportService* reportService;
    InventoryService* inventoryService;

public:
    MenuService();

    MenuService(
        AuthenticationService* auth,
        ProductService* productService,
        OrderService* orderService,
        ReportService* reportService,
        InventoryService* inventoryService
    );

    void start();

private:
    void loginMenu();
    void adminMenu();
    void managerMenu();
    void cashierMenu();
    void customerMenu();

    void productMenu();
};

=======


class MenuService
{


private:


    AuthenticationService* auth;


    ProductService* productService;


    OrderService* orderService;


    ReportService* reportService;


    InventoryService* inventoryService;




public:


    MenuService();



    MenuService(

        AuthenticationService* auth,

        ProductService* productService,

        OrderService* orderService,

        ReportService* reportService,

        InventoryService* inventoryService

    );




    void start();



private:


    void loginMenu();

    void adminMenu();

    void managerMenu();

    void cashierMenu();

    void customerMenu();


};



>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
#endif