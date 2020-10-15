#include <MySQL/MySQL.hpp>

int main()
{
    mysqltuner::MySQL* connection = new mysqltuner::MySQL("localhost", "root", "", "mysqltuner");
    sql::ResultSet* result = connection->execute("SELECT * from employee");

    std::cout << std::endl << std::endl;

    while(result->next())
    {
        std::cout << result->getInt("id") << " " << result->getString("first_name").c_str() << " " << result->getString("last_name").c_str() << std::endl;
    }

    std::cout << std::endl << std::endl;

    result = nullptr;
    result = connection->execute("SELECT * from user");

    while(result->next())
    {
        std::cout << result->getInt("id") << " " << result->getInt("employee_id") << " " << result->getString("user_type").c_str() << std::endl;
    }

    std::cout << std::endl << std::endl;

    result = nullptr;

    delete connection;
    delete result;

    return EXIT_SUCCESS;
}
