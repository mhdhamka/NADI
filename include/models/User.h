#ifndef USER_H
#define USER_H

#include <string>

class User
{
private:
    std::string username;
    std::string password;
    std::string role;

public:
    // Constructors
    User();

    User(
        const std::string& username,
        const std::string& password,
        const std::string& role
    );

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getRole() const;

    // Setters
    void setUsername(
        const std::string& username
    );

    void setPassword(
        const std::string& password
    );

    void setRole(
        const std::string& role
    );

    // Authentication
    bool verifyPassword(
        const std::string& inputPassword
    ) const;

    // Display
    void displayUser() const;
};

#endif