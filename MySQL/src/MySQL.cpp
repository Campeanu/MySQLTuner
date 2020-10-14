#include <MySQL/MySQL.hpp>

namespace mysqltuner {

    void MySQL::init()
    {
        this->driver = nullptr;
        this->connection = nullptr;
        this->statement = nullptr;
        this->preparedStatament = nullptr;
        this->result = nullptr;
    }

    void MySQL::createConnection(const sql::SQLString& db_host, const sql::SQLString& db_user, const sql::SQLString& db_pass, const sql::SQLString& db_name)
    {
        try {

            this->driver = get_driver_instance();
            this->connection = this->driver->connect(db_host, db_user, db_pass);
            this->connection->setSchema(db_name);

        } catch(const sql::SQLException& e) {

            std::cout << "# ERR: SQLException in " << __FILE__ << std::endl;
            std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
            std::cout << "# ERR: " << e.what() << std::endl;
            std::cout << " (MySQL error code: " << e.getErrorCode() << std::endl;
            std::cout << ", SQLState: " << e.getSQLState().c_str() << " )" << std::endl;

        }

        if(this->connection->isValid())
        {
            std::cout << "The connection was succesfull !" << std::endl;
        }
    }

    MySQL::MySQL(const sql::SQLString& db_host, const sql::SQLString& db_user, const sql::SQLString& db_pass, const sql::SQLString& db_name)
        : db_host{db_host}, db_user{db_user}, db_pass{db_pass}, db_name{db_name}
    {
        this->init();
        this->createConnection(this->db_host, this->db_user, this->db_pass, this->db_name);
        this->statement = this->connection->createStatement();
    }

    MySQL::~MySQL()
    {
        delete this->connection;
        delete this->statement;
        delete this->preparedStatament;
        delete this->result;
    }

} // namespace mysqltuner
