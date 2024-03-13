#include "Database.h"

Database *Database::p_instance = nullptr;
DatabaseDestroyer Database::destroyer;

/**
 * @brief Construct a new Database:: Database object
 *
 */
Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("..//server//DATABASE");
    if (!db.open())
    {
        qDebug() << "Error: failed to open database";
    }
}

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool Database::createTable()
{
    QSqlQuery query(db);
    return query.exec("create table users(id integer primary key not null, login text not null unique, password text not null, email text not null unique);");
}

/**
 * @brief Destroy the Database:: Database object
 *
 */
Database::~Database()
{
    db.close();
}

/**
 * @brief
 *
 * @return Database&
 */
Database &Database::getInstance()
{
    if (!p_instance)
    {
        p_instance = new Database();
        p_instance->createTable();
    }
    return *p_instance;
}

/**
 * @brief
 *
 * @return QSqlDatabase&
 */
QSqlDatabase &Database::getDatabase()
{
    return db;
}

/**
 * @brief Destroy the Database Destroyer:: Database Destroyer object
 *
 */
DatabaseDestroyer::~DatabaseDestroyer()
{
    delete p_instance;
}

/**
 * @brief
 *
 * @param p
 */
void DatabaseDestroyer::initialize(Database *p)
{
    p_instance = p;
}

/**
 * @brief
 *
 * @param src
 * @return QStringList
 */
QStringList Database::queryToDatabase(QStringList src)
{
    QSqlQuery query(db);
    query.prepare(src[0]);
    int i = 1;
    while (i < src.size())
    {
        query.bindValue(src[i], src[i + 1]);
        i += 2;
    }

    QStringList res;
    if (src[0].contains("SELECT"))
    {
        // qDebug() << query.exec();
        // qDebug() << query.first();
        if (query.exec() && query.first())
        {
            res.append("found");
            return res;
        }
    }
    else
    {
        if (query.exec())
        {
            res.append("ok");
            return res;
        }
    }
    return res;
}
