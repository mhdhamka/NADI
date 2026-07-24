#ifndef MENU_SERVICE_H
#define MENU_SERVICE_H


#include "AuthenticationService.h"
#include "ProductService.h"
#include "OrderService.h"
#include "ReportService.h"
#include "InventoryService.h"



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



#endif