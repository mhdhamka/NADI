#include "services/MenuService.h"

#include <iostream>

#include "services/UtilsService.h"

using namespace std;

// ===== Terminal Colors =====
const string RESET  = "\033[0m";
const string BLUE   = "\033[34m";
const string CYAN   = "\033[36m";
const string GREEN  = "\033[32m";
const string YELLOW = "\033[33m";
const string RED    = "\033[31m";
const string WHITE  = "\033[37m";
const string BOLD   = "\033[1m";


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

    cout << BLUE;
    cout << "╔══════════════════════════════════════════════════════════════╗\n";
    cout << "║                                                              ║\n";
    cout << "║      ███╗   ██╗ █████╗ ██████╗ ██╗                           ║\n";
    cout << "║      ████╗  ██║██╔══██╗██╔══██╗██║                           ║\n";
    cout << "║      ██╔██╗ ██║███████║██║  ██║██║                           ║\n";
    cout << "║      ██║╚██╗██║██╔══██║██║  ██║██║                           ║\n";
    cout << "║      ██║ ╚████║██║  ██║██████╔╝██║                           ║\n";
    cout << "║      ╚═╝  ╚═══╝╚═╝  ╚═╝╚═════╝ ╚═╝                           ║\n";
    cout << "║                                                              ║\n";

    cout << CYAN;
    cout << "║          Networked Automated Digital Inventory              ║\n";
    cout << "║                 Retail Management System                    ║\n";

    cout << BLUE;
    cout << "║                                                              ║\n";
    cout << "╚══════════════════════════════════════════════════════════════╝\n";

    cout << RESET << "\n";

    cout << WHITE
         << "Branch   : "
         << CYAN
         << "Kuching HQ\n";

    cout << WHITE
         << "Version  : "
         << YELLOW
         << "2.0.0\n";

    cout << WHITE
         << "Database : "
         << GREEN
         << "Connected ✓\n";

    cout << RESET;

    cout << "\n--------------------------------------------------------------\n";

    string username;
    string password;

    cout << CYAN << "Username : " << RESET;
    cin >> username;

    cout << CYAN << "Password : " << RESET;
    cin >> password;

    if(auth->login(username,password))
    {
        cout << GREEN
             << "\nLogin Successful!\n"
             << RESET;

        UtilsService::pause();

        string role =
            auth->getCurrentUser()->getRole();

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
        cout << RED
             << "\nInvalid Username or Password.\n"
             << RESET;

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
        {
            string customerID;

            cout << "Customer ID: ";
            cin >> customerID;


            Order order = 
                orderService->createOrder(customerID);


            cout << "\nOrder created successfully!\n";
            cout << "Order ID: "
                << order.getOrderID()
                << "\n";

            break;
        }


        case 2:
        {
            string orderID;

            cout << "Order ID: ";
            cin >> orderID;


            if(!orderService->displayOrder(orderID))
            {
                cout << "Order not found.\n";
            }

            break;
        }


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