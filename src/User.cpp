#include "models/User.h"

#include <iostream>

using namespace std;

// ======================
// Constructors
// ======================

User::User()
{
}

User::User(
    const string& username,
    const string& password,
    const string& role
)
{
    this->username = username;
    this->password = password;
    this->role = role;
}

// ======================
// Getters
// ======================

string User::getUsername() const
{
    return username;
}

string User::getPassword() const
{
    return password;
}

string User::getRole() const
{
    return role;
}

// ======================
// Setters
// ======================

void User::setUsername(
    const string& username
)
{
    this->username = username;
}

void User::setPassword(
    const string& password
)
{
    this->password = password;
}

void User::setRole(
    const string& role
)
{
    this->role = role;
}

// ======================
// Authentication
// ======================

bool User::verifyPassword(
    const string& inputPassword
) const
{
    return password == inputPassword;
}

// ======================
// Display
// ======================

void User::displayUser() const
{
    cout
        << "============================\n"
        << "Username : " << username << "\n"
        << "Role     : " << role << "\n"
        << "============================\n";
}