#include "function.h"

QByteArray parsing(QString client_data)
{
    qDebug()<<"f started";
    QStringList client_data_list = client_data.split("&");
    QString func_name = client_data_list.front();
    //qDebug() << func_name;

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
    return "auth\n";
}

QByteArray reg(QString log, QString pass, QString mail)
{
    return "reg\n";
}
