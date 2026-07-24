#include <iostream>

#include "Menu.h"
#include "Database.h"
#include "Inventory.h"
#include "Sales.h"
#include "Report.h"
#include "User.h"

int main()
{
    std::cout << "=========================================\n";
    std::cout << "    Rakyat Electronic System v1.0\n";
    std::cout << "=========================================\n\n";

    Database database;
    Inventory inventory;
    Sales sales;
    Report report;
    User user;
    Menu menu;

    // Load data
    database.loadProducts();
    database.loadUsers();
    database.loadSales();

    // Login
    if (!user.login())
    {
        std::cout << "\nLogin failed.\n";
        return 0;
    }

    // Main application
    menu.run(database, inventory, sales, report);

    // Save before exit
    database.saveProducts();
    database.saveSales();

    std::cout << "\nThank you for using Rakyat Electronic System.\n";

    return 0;
}