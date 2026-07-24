#include "services/MenuService.h"


#include <iostream>


#include "UtilsService.h"



using namespace std;





MenuService::MenuService()

{

    auth=nullptr;

    productService=nullptr;

    orderService=nullptr;

    reportService=nullptr;

    inventoryService=nullptr;

}







MenuService::MenuService(

AuthenticationService* auth,

ProductService* productService,

OrderService* orderService,

ReportService* reportService,

InventoryService* inventoryService

)

{

    this->auth=auth;

    this->productService=productService;

    this->orderService=orderService;

    this->reportService=reportService;

    this->inventoryService=inventoryService;

}









void MenuService::start()

{


    while(true)

    {

        loginMenu();

    }

}









void MenuService::loginMenu()

{

    UtilsService::clearScreen();



    cout

    << "\n==============================\n"

    << " RAKYAT ELECTRONICS SYSTEM\n"

    << "==============================\n\n";



    string username;

    string password;



    cout<<"Username: ";

    cin>>username;



    cout<<"Password: ";

    cin>>password;



    if(auth->login(username,password))

    {


        string role =

        auth->getCurrentUser()

        ->getRole();



        if(role=="ADMIN")

            adminMenu();



        else if(role=="MANAGER")

            managerMenu();



        else if(role=="CASHIER")

            cashierMenu();



        else

            customerMenu();



    }

    else

    {

        cout

        << "\nInvalid login\n";


        UtilsService::pause();

    }

}









void MenuService::adminMenu()

{

    int choice;



    do

    {

        UtilsService::clearScreen();



        cout

        << "\n====== ADMIN MENU ======\n"

        << "1. Manage Products\n"

        << "2. Manage Users\n"

        << "3. View Reports\n"

        << "4. Logout\n"

        << "\nChoice: ";



        cin>>choice;



        switch(choice)

        {


        case 1:

            productService->displayProducts();

            break;



        case 3:

            reportService->generateSalesReport();

            break;



        case 4:

            auth->logout();

            break;



        default:

            cout<<"Invalid option";

        }



        UtilsService::pause();



    }

    while(choice!=4);


}









void MenuService::managerMenu()

{

    int choice;



    do

    {

        UtilsService::clearScreen();



        cout

        << "\n====== MANAGER MENU ======\n"

        << "1. Inventory Report\n"

        << "2. Sales Report\n"

        << "3. Logout\n"

        << "\nChoice: ";



        cin>>choice;



        if(choice==1)

        {

            inventoryService->displayInventory();

        }


        else if(choice==2)

        {

            reportService->generateSalesReport();

        }


        else if(choice==3)

        {

            auth->logout();

        }


        UtilsService::pause();



    }

    while(choice!=3);

}









void MenuService::cashierMenu()

{

    int choice;



    do

    {


        UtilsService::clearScreen();



        cout

        << "\n====== CASHIER MENU ======\n"

        << "1. Create Order\n"

        << "2. View Receipt\n"

        << "3. Logout\n"

        << "\nChoice: ";



        cin>>choice;



        switch(choice)

        {

        case 1:

            orderService->createOrder();

            break;


        case 2:

            orderService->viewReceipt();

            break;


        case 3:

            auth->logout();

            break;

        }



        UtilsService::pause();



    }

    while(choice!=3);

}


void MenuService::customerMenu()

{

    cout

    << "Customer menu coming soon";



}