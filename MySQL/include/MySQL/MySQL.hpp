#if !defined(__MYDQL_INCLUDED__)
#define __MYDQL_INCLUDED__

#include <iostream>
#include <string>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

namespace mysqltuner {

    class MySQL {
    // Life cycle
    public:
        MySQL(const sql::SQLString& db_host, const sql::SQLString& db_user, const sql::SQLString& db_pass, const sql::SQLString& name);
        virtual ~MySQL();

    // Private methods
    private:
        void init();
        void createConnection(const sql::SQLString& db_host, const sql::SQLString& db_user, const sql::SQLString& db_pass, const sql::SQLString& name);

    // Private properties
    private:
        sql::Driver* driver;
        sql::Connection* connection;
        sql::Statement* statement;
        sql::PreparedStatement* preparedStatament;
        sql::ResultSet* result;

        const sql::SQLString db_host;
        const sql::SQLString db_user;
        const sql::SQLString db_pass;
        const sql::SQLString db_name;
    };

} // namespace mysqltuner

#endif // __MYDQL_INCLUDED__
