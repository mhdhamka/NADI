#include "services/MenuService.h"

#include <iostream>
<<<<<<< HEAD
#include <iomanip>
#include <ctime>
=======
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98

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

<<<<<<< HEAD
    cout << WHITE << "Branch   : " << CYAN << "Kuching HQ\n";
    cout << WHITE << "Version  : " << YELLOW << "2.0.0\n";
    cout << WHITE << "Database : " << GREEN << "Connected ✓\n\n";

    cout << "┌─────────────────────────────────────────────┐\n";
    cout << "│                 LOGIN                       │\n";
    cout << "├─────────────────────────────────────────────┤\n\n";
=======
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
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98

    string username;
    string password;

<<<<<<< HEAD
    cout << " Username : ";
    cin >> username;

    cout << "\n Password : ";
    cin >> password;

    cout << "\n──────────────────────────────────────────────\n";
    cout << " Press ENTER to Login\n";
    cout << " Press CTRL+C to Exit\n";
    cout << "└─────────────────────────────────────────────┘\n\n";

    if(auth->login(username,password))
    {
        string role = auth->getCurrentUser()->getRole();

        if(role=="ADMIN")
            adminMenu();
        else if(role=="MANAGER")
            managerMenu();
        else if(role=="CASHIER")
            cashierMenu();
=======
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

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
        else
            customerMenu();
    }
    else
    {
<<<<<<< HEAD
        cout << RED << "\nInvalid Username or Password.\n" << RESET;
=======
        cout << RED
             << "\nInvalid Username or Password.\n"
             << RESET;

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
        UtilsService::pause();
    }
}

<<<<<<< HEAD
std::string getCurrentTime()
{
    time_t now = time(nullptr);

    tm* local = localtime(&now);

    char buffer[20];

    strftime(buffer, sizeof(buffer), "%I:%M %p", local);

    return std::string(buffer);
}

void MenuService::adminMenu()
{
    int choice;

    do
    {
        UtilsService::clearScreen();

        cout << BLUE;
        cout << "══════════════════════════════════════════════════════════════════════\n";
        cout << RESET;

        cout << "User : "
             << GREEN
             << auth->getCurrentUser()->getUsername()
             << RESET;

        cout << "      Role : "
             << CYAN
             << auth->getCurrentUser()->getRole()
             << RESET;

        cout << "      Time : "
             << YELLOW
             << getCurrentTime()
             << RESET
             << "\n";

        cout << BLUE;
        cout << "══════════════════════════════════════════════════════════════════════\n";
        cout << RESET;

        cout << "\n";

                cout << "[1] Products\n";
        cout << "[2] Inventory\n";
        cout << "[3] Customers\n";
        cout << "[4] Sales\n";
        cout << "[5] Orders\n";
        cout << "[6] Reports\n";
        cout << "[7] User Management\n";
        cout << "[8] Settings\n";

        cout << "\n---------------------------------------------\n";

        cout << "[9] Backup Database\n";
        cout << "[0] Logout\n";

        cout << "\n==============================================================\n";
        cout << "Select Option > ";

        cin >> choice;

                switch(choice)
        {
        case 1:
            productMenu();
            break;

        case 2:
            inventoryService->displayInventory();
            break;

        case 3:
            cout << "\nCustomer module coming soon.\n";
            break;

        case 4:
            cout << "\nSales module coming soon.\n";
            break;

        case 5:
            cout << "\nOrders module coming soon.\n";
            break;

        case 6:
            reportService->generateSalesReport();
            break;

        case 7:
            cout << "\nUser Management coming soon.\n";
            break;

        case 8:
            cout << "\nSettings coming soon.\n";
            break;

        case 9:
            cout << "\nBackup completed.\n";
            break;

        case 0:
            auth->logout();
            break;

        default:
            cout << RED << "\nInvalid option.\n" << RESET;
        }

        if(choice != 0)
            UtilsService::pause();

    } while(choice != 0);
}

void MenuService::productMenu()
{
    int choice;

    do
    {
        UtilsService::clearScreen();

        cout << "=============================================\n";
        cout << "          PRODUCT MANAGEMENT\n";
        cout << "=============================================\n\n";

        cout << "[1] Add Product\n";
        cout << "[2] View Products\n";
        cout << "[3] Search Product\n";
        cout << "[4] Update Product\n";
        cout << "[5] Delete Product\n";
        cout << "[0] Back\n\n";

        cout << "Choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            productService->addProduct();
            break;

        case 2:
            productService->displayProducts();
            break;

        case 3:
            productService->searchProduct();
            break;

        case 4:
            productService->updateProduct();
            break;

        case 5:
            productService->deleteProduct();
            break;

        case 0:
            break;

        default:
            cout << "Invalid option.\n";
        }

        if(choice != 0)
            UtilsService::pause();

    } while(choice != 0);
}

=======

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









>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
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


<<<<<<< HEAD
=======







>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
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