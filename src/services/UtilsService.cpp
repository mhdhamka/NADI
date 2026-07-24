#include "services/UtilsService.h"


#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <random>
#include <cctype>



using namespace std;







string UtilsService::toUpper(

const string& text

)

{

    string result=text;


    transform(

        result.begin(),

        result.end(),

        result.begin(),

        ::toupper

    );


    return result;

}







string UtilsService::trim(

const string& text

)

{

    size_t start =

    text.find_first_not_of(" ");



    size_t end =

    text.find_last_not_of(" ");



    if(start==string::npos)

        return "";



    return text.substr(

        start,

        end-start+1

    );

}







bool UtilsService::isEmpty(

const string& text

)

{

    return trim(text).empty();

}







bool UtilsService::isNumber(

const string& text

)

{

    if(text.empty())

        return false;



    for(char c:text)

    {

        if(!isdigit(c))

            return false;

    }



    return true;

}







bool UtilsService::isValidEmail(

const string& email

)

{

    return

    email.find("@")

    != string::npos

    &&

    email.find(".")

    != string::npos;

}







string UtilsService::formatCurrency(

double amount

)

{

    stringstream stream;


    stream

    << fixed

    << setprecision(2)

    << "RM "

    << amount;



    return stream.str();

}







string UtilsService::currentDate()

{

    time_t now=time(nullptr);


    tm* local=localtime(&now);



    stringstream ss;


    ss

    << put_time(

        local,

        "%Y-%m-%d"

    );


    return ss.str();

}







string UtilsService::currentTime()

{

    time_t now=time(nullptr);


    tm* local=localtime(&now);



    stringstream ss;


    ss

    << put_time(

        local,

        "%H:%M:%S"

    );


    return ss.str();

}







string UtilsService::generateID(

const string& prefix

)

{

    random_device rd;


    mt19937 generator(rd());


    uniform_int_distribution<int>

    distribution(10000,99999);



    return

    prefix

    +

    to_string(

    distribution(generator)

    );

}







void UtilsService::clearScreen()

{

#ifdef _WIN32

    system("cls");

#else

    system("clear");

#endif

}







void UtilsService::pause()

{

    cout

    << "\nPress Enter to continue...";


    cin.ignore();

    cin.get();

}