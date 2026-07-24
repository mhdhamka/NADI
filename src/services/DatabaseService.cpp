#include "services/DatabaseService.h"


#include <iostream>
#include <fstream>



using namespace std;




DatabaseService::DatabaseService()

{

    database = nullptr;

    databaseName = "rakyat_electronics.db";

}







DatabaseService::DatabaseService(

    const string& filename

)

{

    database = nullptr;

    databaseName = filename;

}







DatabaseService::~DatabaseService()

{

    disconnect();

}







bool DatabaseService::connect()

{

    int result;



    result = sqlite3_open(

        databaseName.c_str(),

        &database

    );



    if(result != SQLITE_OK)

    {

        return false;

    }



    return true;

}







void DatabaseService::disconnect()

{

    if(database)

    {

        sqlite3_close(database);

        database = nullptr;

    }

}








bool DatabaseService::execute(

    const string& sql

)

{


    char* errorMessage = nullptr;



    int result = sqlite3_exec(

        database,

        sql.c_str(),

        nullptr,

        nullptr,

        &errorMessage

    );



    if(result != SQLITE_OK)

    {


        sqlite3_free(errorMessage);


        return false;

    }



    return true;

}









bool DatabaseService::initializeDatabase()

{

    if(!connect())

        return false;



    return createTables();

}









bool DatabaseService::createTables()

{


    string sql = R"(


CREATE TABLE IF NOT EXISTS Users

(

id INTEGER PRIMARY KEY AUTOINCREMENT,

username TEXT UNIQUE,

password TEXT,

role TEXT

);



CREATE TABLE IF NOT EXISTS Products

(

id INTEGER PRIMARY KEY AUTOINCREMENT,

name TEXT,

brand TEXT,

price REAL,

stock INTEGER

);



CREATE TABLE IF NOT EXISTS Customers

(

id INTEGER PRIMARY KEY AUTOINCREMENT,

name TEXT,

phone TEXT,

email TEXT

);



CREATE TABLE IF NOT EXISTS Orders

(

id INTEGER PRIMARY KEY AUTOINCREMENT,

customerID INTEGER,

total REAL,

status TEXT

);



CREATE TABLE IF NOT EXISTS Payments

(

id INTEGER PRIMARY KEY AUTOINCREMENT,

orderID INTEGER,

amount REAL,

method TEXT,

status TEXT

);



CREATE TABLE IF NOT EXISTS Receipts

(

id INTEGER PRIMARY KEY AUTOINCREMENT,

orderID INTEGER,

paymentID INTEGER,

amount REAL

);


)";



return execute(sql);

}









bool DatabaseService::backupDatabase(

    const string& filename

)

{

    ofstream file(filename);



    if(!file)

        return false;



    file.close();



    return true;

}