#if !defined(__MYDQL_INCLUDED__)
#define __MYDQL_INCLUDED__

#include <iostream>
#include <string>

/**
 * MySQL connector
 */
#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

namespace mysqltuner {

    class MySQL {
    public:
        MySQL();
        virtual ~MySQL();
    private:
    };

} // namespace mysqltuner

#endif // __MYDQL_INCLUDED__
