#ifndef UTILS_SERVICE_H
#define UTILS_SERVICE_H


#include <string>


class UtilsService
{


public:


    // String


    static std::string toUpper(

        const std::string& text

    );



    static std::string trim(

        const std::string& text

    );




    static bool isEmpty(

        const std::string& text

    );




    // Validation


    static bool isNumber(

        const std::string& text

    );



    static bool isValidEmail(

        const std::string& email

    );




    // Currency


    static std::string formatCurrency(

        double amount

    );




    // Date/time


    static std::string currentDate();



    static std::string currentTime();




    // ID generator


    static std::string generateID(

        const std::string& prefix

    );


    // Console
    static void clearScreen();
    static void pause();

};



#endif