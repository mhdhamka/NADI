#ifndef DATABASE_SERVICE_H
#define DATABASE_SERVICE_H

#include <string>
#include <vector>
#include <sqlite3.h>

#include "models/Product.h"

class User;

class DatabaseService
{
private:
    sqlite3* database;
    std::string databaseName;

public:
    // ======================================================
    // Constructors
    // ======================================================

    DatabaseService();
    DatabaseService(const std::string& filename);
    ~DatabaseService();

    // ======================================================
    // Connection
    // ======================================================

    bool connect();
    void disconnect();

    // ======================================================
    // Database Initialization
    // ======================================================

    bool initializeDatabase();
    bool createTables();
    bool createDefaultAdmin();

    // ======================================================
    // Execute SQL
    // ======================================================

    bool execute(const std::string& sql);

    // ======================================================
    // User Operations
    // ======================================================

    bool insertUser(
        const User& user
    );

    bool getUserByUsername(
        const std::string& username,
        User& outUser
    );

    bool deleteUser(
        const std::string& username
    );

    // ======================================================
    // Product Operations
    // ======================================================

    bool insertProduct(
        const Product& product
    );

    bool updateProduct(
        const Product& product
    );

    bool deleteProduct(
        const std::string& productID
    );

    bool getProductByID(
        const std::string& productID,
        Product& outProduct
    );

    std::vector<Product> getAllProducts();

    std::vector<Product> searchProducts(
        const std::string& keyword
    );

    // ======================================================
    // Database Maintenance
    // ======================================================

    bool backupDatabase(
        const std::string& filename
    );
};

#endif