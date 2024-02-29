#include "function.h"

QByteArray parsing(QString client_data)
{
    qDebug()<<"f started";
    QStringList client_data_list = client_data.split("&");
    QString func_name = client_data_list.front();

    if(func_name.compare("auth") == 0){
        client_data_list.pop_front();
        return auth(client_data_list.at(0), client_data_list.at(1));
    }
    else if(func_name.compare("reg") == 0){
        client_data_list.pop_front();
        return reg(client_data_list.at(0), client_data_list.at(1), client_data_list.at(2));
    }
    else {
        return "error\n";
    }
}

QByteArray auth(QString log, QString pass)
{
    QStringList querrySrc;
    querrySrc.append("SELECT login, password FROM users WHERE login == :login and password == :password;");
    querrySrc.append(":login");
    querrySrc.append(log);
    querrySrc.append(":password");
    querrySrc.append(pass);
    qDebug()<<querrySrc;
    querrySrc = Database::getInstance().querryToDatabase(querrySrc);
    if(querrySrc.size()>0){
        return (QString("auth+&") + log+ "\n").toUtf8();
    }
    else {
        return "auth-\n";
    }
}

QByteArray reg(QString log, QString pass, QString mail)
{
    QSqlDatabase& db = Database::getInstance().getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT login, password, email FROM users WHERE login = :login;");
    query.bindValue(":login", log);
    query.bindValue(":email", mail);
    qDebug() << query.exec();
    qDebug() << query.first();
    if(query.exec() && query.first()){
        return "reg-\n";
    }
    else{
        QSqlQuery queryIn(db);
        queryIn.prepare("INSERT INTO users (login, password, email) VALUES (:login, :password, :email);");
        queryIn.bindValue(":login", log);
        queryIn.bindValue(":password", pass);
        queryIn.bindValue(":email", mail);
        // qDebug() << query.exec();
        // qDebug() << query.first();
        // qDebug() << query.last();
        if(queryIn.exec()){
            return "reg+&login\n";
        }
        else {
            return "failed to register user\n";
        }
    }
}
