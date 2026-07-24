#ifndef LOGGER_SERVICE_H
#define LOGGER_SERVICE_H


#include <string>


class LoggerService
{


private:

    std::string logFile;



    std::string getCurrentTime();



public:


    LoggerService();



    LoggerService(

        const std::string& filename

    );



    void log(

        const std::string& message

    );



    void info(

        const std::string& message

    );



    void warning(

        const std::string& message

    );



    void error(

        const std::string& message

    );



    void security(

        const std::string& message

    );



};


#endif