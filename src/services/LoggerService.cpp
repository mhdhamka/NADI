#include "services/LoggerService.h"


#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>



using namespace std;





LoggerService::LoggerService()

{

    logFile = "logs/system.log";

}






LoggerService::LoggerService(

    const string& filename

)

{

    logFile = filename;

}









string LoggerService::getCurrentTime()

{


    time_t now = time(nullptr);


    tm* localTime = localtime(&now);



    stringstream time;



    time

    << put_time(

        localTime,

        "%Y-%m-%d %H:%M:%S"

    );



    return time.str();

}









void LoggerService::log(

    const string& message

)

{

    ofstream file(

        logFile,

        ios::app

    );



    if(!file)

    {

        cout

        << "Cannot open log file";

        return;

    }



    file

    << "["

    << getCurrentTime()

    << "] "

    << message

    << endl;



    file.close();

}









void LoggerService::info(

    const string& message

)

{

    log(

        "[INFO] "

        + message

    );

}









void LoggerService::warning(

    const string& message

)

{

    log(

        "[WARNING] "

        + message

    );

}









void LoggerService::error(

    const string& message

)

{

    log(

        "[ERROR] "

        + message

    );

}









void LoggerService::security(

    const string& message

)

{

    log(

        "[SECURITY] "

        + message

    );

}