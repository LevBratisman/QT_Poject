#ifndef DATABASE_H
#define DATABASE_H

#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QStringList>

class Database;

class DatabaseDestroyer
{
private:
    Database * p_instance;
public:
    ~DatabaseDestroyer();
    /// \brief Инициализатор класса DataBaseDestroyer
    /// \param p указатель на базу данных
    void initialize(Database * p);
};

class Database {
private:
    static Database *p_instance;
    static DatabaseDestroyer destroyer;
    /// \brieы данныхf Объект баз
    QSqlDatabase db;
    /// \brief Конструктор класса Базы данных
    Database();
    /// \brief Деструктор базы данных
    ~Database();    
    Database(const Database&) = delete;
    void operator= (const Database&) = delete;
    friend class DatabaseDestroyer;

public:
    /// \brief Метод создания таблицы в базе данных
    bool createTable();
    /// \brief Метод который предоставляет доступ к базе данных
    static Database& getInstance();
    /// \brief Метод выполнения запросов к базе данных
    /// \param src Список содержащий параметры для SQL запроса
    QStringList queryToDatabase(QStringList src);
};


#endif // DATABASE_H
