//
// Created by vasco on 12/03/2025.
//

#ifndef FSOFT2025_CLASS_1DC_TEAM2_DB_CONNECTION_H
#define FSOFT2025_CLASS_1DC_TEAM2_DB_CONNECTION_H

#include <mysql_driver.h>
#include <mysql_connection.h>

class DBConnection {
public:
    DBConnection(const std::string &host, const std::string &user, const std::string &password,
                 const std::string &schema);

    ~DBConnection();

    sql::Connection *getConnection();

private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
};

#endif //FSOFT2025_CLASS_1DC_TEAM2_DB_CONNECTION_H
