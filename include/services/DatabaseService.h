#ifndef DATABASE_SERVICE_H
#define DATABASE_SERVICE_H


#include <string>

#include <sqlite3.h>



class DatabaseService
{


private:


    sqlite3* database;


    std::string databaseName;




public:


    DatabaseService();



    DatabaseService(

        const std::string& filename

    );



    ~DatabaseService();




    // Connection


    bool connect();



    void disconnect();




    // Database creation


    bool initializeDatabase();




    // Execute SQL


    bool execute(

        const std::string& sql

    );



    // Tables
    bool createTables();

    // Backup
    bool backupDatabase(

        const std::string& filename

    );



};



#endif