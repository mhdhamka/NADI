#include <iostream>
#include <windows.h>

#include "services/AuthenticationService.h"
#include "services/DatabaseService.h"
#include "services/ProductService.h"
#include "services/OrderService.h"
#include "services/InventoryService.h"
#include "services/ReportService.h"
#include "services/MenuService.h"

int main()
{
    // =========================================
    // Enable UTF-8 Console (Windows)
    // =========================================
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout
        << "=========================================\n";

    std::cout
        << "    NETWORKED AUTOMATED DIGITAL INVENTORY SYSTEM\n";

    std::cout
        << "=========================================\n\n";

    // =========================================
    // Database
    // =========================================
    DatabaseService databaseService;

    if(!databaseService.initializeDatabase())
    {
        std::cout
            << "Failed to initialize database!\n";

        return 1;
    }

    // =========================================
    // Core Services
    // =========================================
    AuthenticationService authenticationService(
        &databaseService
    );

    ProductService productService;
    OrderService orderService;
    InventoryService inventoryService;
    ReportService reportService;

    // =========================================
    // Menu Controller
    // =========================================
    MenuService menuService(

        &authenticationService,
        &productService,
        &orderService,
        &reportService,
        &inventoryService

    );

    // =========================================
    // Start Application
    // =========================================
    menuService.start();

    std::cout
        << "\nThank you for using Networked Automated Digital Inventory System.\n";

    return 0;
}