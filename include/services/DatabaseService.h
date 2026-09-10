#ifndef DATABASE_SERVICE_H
#define DATABASE_SERVICE_H

#include <string>
<<<<<<< HEAD
#include <vector>
#include <sqlite3.h>

#include "models/Product.h"

=======
#include <sqlite3.h>

>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
class User;

class DatabaseService
{
private:
    sqlite3* database;
    std::string databaseName;

public:
<<<<<<< HEAD
    // ======================================================
    // Constructors
    // ======================================================

=======
    // Constructors
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    DatabaseService();
    DatabaseService(const std::string& filename);
    ~DatabaseService();

<<<<<<< HEAD
    // ======================================================
    // Connection
    // ======================================================

    bool connect();
    void disconnect();

    // ======================================================
    // Database Initialization
    // ======================================================

=======
    // Connection
    bool connect();
    void disconnect();

    // Database initialization
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    bool initializeDatabase();
    bool createTables();
    bool createDefaultAdmin();

<<<<<<< HEAD
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
=======
    // Execute SQL
    bool execute(const std::string& sql);

    // User Operations
    bool insertUser(const User& user);
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98

    bool getUserByUsername(
        const std::string& username,
        User& outUser
    );

    bool deleteUser(
        const std::string& username
    );

<<<<<<< HEAD
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

=======
    // Database Maintenance
>>>>>>> d3b786b596bfbf909e73e8bb539fe9261ead3c98
    bool backupDatabase(
        const std::string& filename
    );
};

#endif