#ifndef AUTHENTICATION_SERVICE_H
#define AUTHENTICATION_SERVICE_H


#include <vector>
#include <string>


#include "../models/User.h"

class DatabaseService;

class AuthenticationService
{


private:

    User* currentUser;
    DatabaseService* database;

public:


    // Constructors
    AuthenticationService();
    AuthenticationService(DatabaseService* database);

    // User management
    bool registerUser(
        const User& user
    );

    bool deleteUser(
        const std::string& username
    );

    User* findUser(
        const std::string& username
    );

    // Authentication
    bool login(
        const std::string& username,
        const std::string& password
    );

    void logout();

    bool isAuthenticated();

    User* getCurrentUser();

    // Authorization
    bool hasRole(
        const std::string& role
    );

    bool isAdmin();

    bool isManager();

    bool isCashier();

    // Display
    void displayUsers() const;

};



#endif