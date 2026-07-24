#include "services/AuthenticationService.h"

#include <iostream>


using namespace std;



AuthenticationService::AuthenticationService()

{

    currentUser = nullptr;

}






bool AuthenticationService::registerUser(

    const User& user

)

{


    for(auto& existing : users)

    {

        if(existing.getUsername()

            == user.getUsername())

        {

            return false;

        }

    }



    users.push_back(user);



    return true;

}









bool AuthenticationService::deleteUser(

    const string& userID

)

{


    for(auto iterator = users.begin();

        iterator != users.end();

        iterator++)

    {


        if(iterator->getUserID()

            == userID)

        {

            users.erase(iterator);

            return true;

        }

    }



    return false;

}









User* AuthenticationService::findUser(

    const string& username

)

{


    for(auto& user : users)

    {

        if(user.getUsername()

            == username)

        {

            return &user;

        }

    }



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



    for(auto& user : users)

    {

        user.displayUser();

    }



    cout

    << "\n===========================\n";

}