#include "services/DatabaseService.h"
#include "models/User.h"

#include <fstream>
#include <iostream>

using namespace std;

DatabaseService::DatabaseService()
{
    database = nullptr;
    databaseName = "rakyat_electronics.db";
}

DatabaseService::DatabaseService(const string& filename)
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
    if(database != nullptr)
    {
        return true;
    }

    int result = sqlite3_open(
        databaseName.c_str(),
        &database
    );

    return result == SQLITE_OK;
}

void DatabaseService::disconnect()
{
    if(database != nullptr)
    {
        sqlite3_close(database);
        database = nullptr;
    }
}

bool DatabaseService::execute(const string& sql)
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
        if(errorMessage)
        {
            cout << errorMessage << endl;
            sqlite3_free(errorMessage);
        }

        return false;
    }

    return true;
}

bool DatabaseService::initializeDatabase()
{
    if(!connect())
    {
        return false;
    }

    if(!createTables())
    {
        return false;
    }

    if(!createDefaultAdmin())
    {
        return false;
    }

    return true;
}

bool DatabaseService::createDefaultAdmin()
{
    const char* sql =
        "SELECT COUNT(*) FROM Users;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    int count = 0;

    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        count = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);

    if(count > 0)
    {
        return true;
    }

    User admin;

    admin.setUsername("admin");
    admin.setPassword("admin123");
    admin.setRole("ADMIN");

    return insertUser(admin);
}

bool DatabaseService::insertUser(const User& user)
{
    const char* sql =
        "INSERT INTO Users(username,password_hash,role)"
        "VALUES(?,?,?);";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(
        stmt,
        1,
        user.getUsername().c_str(),
        -1,
        SQLITE_TRANSIENT
    );

    sqlite3_bind_text(
        stmt,
        2,
        user.getPassword().c_str(),
        -1,
        SQLITE_TRANSIENT
    );

    sqlite3_bind_text(
        stmt,
        3,
        user.getRole().c_str(),
        -1,
        SQLITE_TRANSIENT
    );

    bool success =
        sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);

    return success;
}

bool DatabaseService::getUserByUsername(
    const string& username,
    User& outUser
)
{
    const char* sql =
        "SELECT username,password_hash,role "
        "FROM Users "
        "WHERE username=?;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(
        stmt,
        1,
        username.c_str(),
        -1,
        SQLITE_TRANSIENT
    );

    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        outUser.setUsername(
            reinterpret_cast<const char*>(
                sqlite3_column_text(stmt,0)
            )
        );

        outUser.setPassword(
            reinterpret_cast<const char*>(
                sqlite3_column_text(stmt,1)
            )
        );

        outUser.setRole(
            reinterpret_cast<const char*>(
                sqlite3_column_text(stmt,2)
            )
        );

        sqlite3_finalize(stmt);
        return true;
    }

    sqlite3_finalize(stmt);
    return false;
}

bool DatabaseService::deleteUser(const string& username)
{
    const char* sql =
        "DELETE FROM Users WHERE username=?;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        return false;
    }

    sqlite3_bind_text(
        stmt,
        1,
        username.c_str(),
        -1,
        SQLITE_TRANSIENT
    );

    bool success =
        sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);

    return success;
}

// ======================================================
// Product Operations
// ======================================================

bool DatabaseService::insertProduct(
    const Product& product
)
{
    const char* sql =
        "INSERT INTO Products("
        "productID,sku,barcode,name,brand,categoryID,"
        "costPrice,sellingPrice,stockQuantity,totalSold,reorderLevel,status"
        ") VALUES(?,?,?,?,?,?,?,?,?,?,?,?);";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt,1,product.getProductID().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,2,product.getSKU().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,3,product.getBarcode().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,4,product.getName().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,5,product.getBrand().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,6,product.getCategoryID().c_str(),-1,SQLITE_TRANSIENT);

    sqlite3_bind_double(stmt,7,product.getCostPrice());
    sqlite3_bind_double(stmt,8,product.getSellingPrice());

    sqlite3_bind_int(stmt,9,product.getStockQuantity());
    sqlite3_bind_int(stmt,10,product.getTotalSold());
    sqlite3_bind_int(stmt,11,product.getReorderLevel());
    sqlite3_bind_int(stmt,12,product.getStatus());

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);

    return success;
}

bool DatabaseService::updateProduct(
    const Product& product
)
{
    const char* sql =
        "UPDATE Products SET "
        "sku=?,"
        "barcode=?,"
        "name=?,"
        "brand=?,"
        "categoryID=?,"
        "costPrice=?,"
        "sellingPrice=?,"
        "stockQuantity=?,"
        "totalSold=?,"
        "reorderLevel=?,"
        "status=? "
        "WHERE productID=?;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt,1,product.getSKU().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,2,product.getBarcode().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,3,product.getName().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,4,product.getBrand().c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,5,product.getCategoryID().c_str(),-1,SQLITE_TRANSIENT);

    sqlite3_bind_double(stmt,6,product.getCostPrice());
    sqlite3_bind_double(stmt,7,product.getSellingPrice());

    sqlite3_bind_int(stmt,8,product.getStockQuantity());
    sqlite3_bind_int(stmt,9,product.getTotalSold());
    sqlite3_bind_int(stmt,10,product.getReorderLevel());
    sqlite3_bind_int(stmt,11,product.getStatus());

    sqlite3_bind_text(stmt,12,product.getProductID().c_str(),-1,SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);

    return success;
}

bool DatabaseService::deleteProduct(
    const string& productID
)
{
    const char* sql =
        "DELETE FROM Products WHERE productID=?;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt,1,productID.c_str(),-1,SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);

    return success;
}

bool DatabaseService::getProductByID(
    const string& productID,
    Product& outProduct
)
{
    const char* sql =
        "SELECT "
        "productID,sku,barcode,name,brand,categoryID,"
        "costPrice,sellingPrice,stockQuantity,totalSold,reorderLevel,status "
        "FROM Products "
        "WHERE productID=?;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt,1,productID.c_str(),-1,SQLITE_TRANSIENT);

    if(sqlite3_step(stmt) != SQLITE_ROW)
    {
        sqlite3_finalize(stmt);
        return false;
    }

    outProduct.setProductID(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0)));
    outProduct.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1)));
    outProduct.setBarcode(reinterpret_cast<const char*>(sqlite3_column_text(stmt,2)));
    outProduct.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt,3)));
    outProduct.setBrand(reinterpret_cast<const char*>(sqlite3_column_text(stmt,4)));
    outProduct.setCategoryID(reinterpret_cast<const char*>(sqlite3_column_text(stmt,5)));

    outProduct.setCostPrice(sqlite3_column_double(stmt,6));
    outProduct.setSellingPrice(sqlite3_column_double(stmt,7));

    outProduct.setStockQuantity(sqlite3_column_int(stmt,8));
    outProduct.setTotalSold(sqlite3_column_int(stmt,9));
    outProduct.setReorderLevel(sqlite3_column_int(stmt,10));
    outProduct.setStatus(sqlite3_column_int(stmt,11));

    sqlite3_finalize(stmt);

    return true;
}

vector<Product> DatabaseService::getAllProducts()
{
    vector<Product> products;

    const char* sql =
        "SELECT "
        "productID,sku,barcode,name,brand,categoryID,"
        "costPrice,sellingPrice,stockQuantity,totalSold,reorderLevel,status "
        "FROM Products;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return products;

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        Product product;

        product.setProductID(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0)));
        product.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1)));
        product.setBarcode(reinterpret_cast<const char*>(sqlite3_column_text(stmt,2)));
        product.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt,3)));
        product.setBrand(reinterpret_cast<const char*>(sqlite3_column_text(stmt,4)));
        product.setCategoryID(reinterpret_cast<const char*>(sqlite3_column_text(stmt,5)));

        product.setCostPrice(sqlite3_column_double(stmt,6));
        product.setSellingPrice(sqlite3_column_double(stmt,7));

        product.setStockQuantity(sqlite3_column_int(stmt,8));
        product.setTotalSold(sqlite3_column_int(stmt,9));
        product.setReorderLevel(sqlite3_column_int(stmt,10));
        product.setStatus(sqlite3_column_int(stmt,11));

        products.push_back(product);
    }

    sqlite3_finalize(stmt);

    return products;
}

vector<Product> DatabaseService::searchProducts(
    const string& keyword
)
{
    vector<Product> products;

    const char* sql =
        "SELECT "
        "productID,sku,barcode,name,brand,categoryID,"
        "costPrice,sellingPrice,stockQuantity,totalSold,reorderLevel,status "
        "FROM Products "
        "WHERE name LIKE ?;";

    sqlite3_stmt* stmt = nullptr;

    if(sqlite3_prepare_v2(database, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return products;

    string pattern = "%" + keyword + "%";

    sqlite3_bind_text(stmt,1,pattern.c_str(),-1,SQLITE_TRANSIENT);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        Product product;

        product.setProductID(reinterpret_cast<const char*>(sqlite3_column_text(stmt,0)));
        product.setSKU(reinterpret_cast<const char*>(sqlite3_column_text(stmt,1)));
        product.setBarcode(reinterpret_cast<const char*>(sqlite3_column_text(stmt,2)));
        product.setName(reinterpret_cast<const char*>(sqlite3_column_text(stmt,3)));
        product.setBrand(reinterpret_cast<const char*>(sqlite3_column_text(stmt,4)));
        product.setCategoryID(reinterpret_cast<const char*>(sqlite3_column_text(stmt,5)));

        product.setCostPrice(sqlite3_column_double(stmt,6));
        product.setSellingPrice(sqlite3_column_double(stmt,7));

        product.setStockQuantity(sqlite3_column_int(stmt,8));
        product.setTotalSold(sqlite3_column_int(stmt,9));
        product.setReorderLevel(sqlite3_column_int(stmt,10));
        product.setStatus(sqlite3_column_int(stmt,11));

        products.push_back(product);
    }

    sqlite3_finalize(stmt);

    return products;
}

bool DatabaseService::createTables()
{
    string sql = R"(

CREATE TABLE IF NOT EXISTS Users
(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE,
    password_hash TEXT,
    role TEXT
);

CREATE TABLE IF NOT EXISTS Products
(
    productID TEXT PRIMARY KEY,
    sku TEXT,
    barcode TEXT,
    name TEXT,
    brand TEXT,
    categoryID TEXT,

    costPrice REAL,
    sellingPrice REAL,

    stockQuantity INTEGER,
    totalSold INTEGER DEFAULT 0,
    reorderLevel INTEGER DEFAULT 10,

    status INTEGER DEFAULT 0
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

bool DatabaseService::backupDatabase(const string& filename)
{
    ofstream file(filename);

    if(!file)
    {
        return false;
    }

    file.close();

    return true;
}