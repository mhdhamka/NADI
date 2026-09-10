#include "services/AuthenticationService.h"
#include "services/DatabaseService.h"

#include <iostream>


using namespace std;


AuthenticationService::AuthenticationService()
    : currentUser(nullptr),
      database(nullptr)
{
}

AuthenticationService::AuthenticationService(DatabaseService* database)
    : currentUser(nullptr),
      database(database)
{
}

bool AuthenticationService::registerUser(const User& user)
{
    if(database == nullptr)
    {
        return false;
    }

    if(findUser(user.getUsername()) != nullptr)
    {
        return false;
    }

    return database->insertUser(user);
}


bool AuthenticationService::deleteUser(
    const string& username
)
{
    if(database == nullptr)
    {
        return false;
    }

    return database->deleteUser(username);
}



User* AuthenticationService::findUser(const string& username)
{
    if(database == nullptr)
    {
        return nullptr;
    }

    User* user = new User();

    if(database->getUserByUsername(username, *user))
    {
        return user;
    }

    delete user;
    return nullptr;
}


bool AuthenticationService::login(

    const string& username,

    const string& password

)

{


    User* user =

        findUser(username);



    if(user == nullptr)

        return false;



    if(user->verifyPassword(password))

    {

        currentUser = user;


        return true;

    }



    return false;

}



void AuthenticationService::logout()

{

    currentUser = nullptr;

}




bool AuthenticationService::isAuthenticated()

{

    return currentUser != nullptr;

}



User* AuthenticationService::getCurrentUser()

{

    return currentUser;

}



bool AuthenticationService::hasRole(

    const string& role

)

{


    if(currentUser == nullptr)

        return false;



    return currentUser->getRole()

        == role;

}



bool AuthenticationService::isAdmin()

{

    return hasRole("ADMIN");

}




bool AuthenticationService::isManager()

{

    return hasRole("MANAGER");

}









bool AuthenticationService::isCashier()

{

    return hasRole("CASHIER");

}


void AuthenticationService::displayUsers() const

{


    cout

    << "\n========== USERS ==========\n";

    cout << "Display users feature coming soon.\n";

    cout

    << "\n===========================\n";

}