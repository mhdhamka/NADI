#ifndef DATABASE_SERVICE_H
#define DATABASE_SERVICE_H

#include <string>
#include <sqlite3.h>

class User;

class DatabaseService
{
private:
    sqlite3* database;
    std::string databaseName;

public:
    // Constructors
    DatabaseService();
    DatabaseService(const std::string& filename);
    ~DatabaseService();

    // Connection
    bool connect();
    void disconnect();

    // Database initialization
    bool initializeDatabase();
    bool createTables();
    bool createDefaultAdmin();

    // Execute SQL
    bool execute(const std::string& sql);

    // User Operations
    bool insertUser(const User& user);

    bool getUserByUsername(
        const std::string& username,
        User& outUser
    );

    bool deleteUser(
        const std::string& username
    );

    // Database Maintenance
    bool backupDatabase(
        const std::string& filename
    );
};

#endif