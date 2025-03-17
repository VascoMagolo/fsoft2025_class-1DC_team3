//
// Created by vasco on 12/03/2025.
//
#include "db_connection.h"
#include <cppconn/exception.h>
#include <iostream>

DBConnection::DBConnection(const std::string &host, const std::string &user, const std::string &password,
                           const std::string &schema) {
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(host, user, password);
        con->setSchema(schema);

        std::cout << "Connected to database!" << std::endl;

    } catch (sql::SQLException &e) {
        std::cerr << "Database connection error: " << e.what() << std::endl;
        con = nullptr;
    }
}

DBConnection::~DBConnection() {
    delete con;
}

sql::Connection *DBConnection::getConnection() {
    return con;
}
