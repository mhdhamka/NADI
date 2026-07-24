#ifndef AUTHENTICATION_SERVICE_H
#define AUTHENTICATION_SERVICE_H


#include <vector>
#include <string>


#include "../models/User.h"



class AuthenticationService
{


private:


    std::vector<User> users;


    User* currentUser;



public:


    AuthenticationService();



    // User management


    bool registerUser(

        const User& user

    );



    bool deleteUser(

        const std::string& userID

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