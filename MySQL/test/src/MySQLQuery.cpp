#include <MySQL/MySQL.hpp>

int main()
{
    mysqltuner::MySQL* connection = new mysqltuner::MySQL("localhost", "root", "", "test");
    delete connection;
    return EXIT_SUCCESS;
}
