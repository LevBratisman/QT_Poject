#include "function.h"

QByteArray parsing (QString client_data)
{
    QStringList client_data_list = client_data.split('&');
    QString name_of_func = client_data_list.front();
    client_data_list.pop_front();

    if(name_of_func == "auth"){
        return auth(client_data_list.at(0), client_data_list(1));
    }
    else if(name_of_func == "reg"){
        return reg(client_data_lis.at(0), client_data_list(1), client_data_list(2));
    }
    else
        return "error";
}
