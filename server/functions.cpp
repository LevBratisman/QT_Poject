#include "function.h"

const float tolerance = 1e-6;
QByteArray parsing(QString client_data)
{
    QStringList client_data_list = client_data.split("&");
    QString func_name = client_data_list.front();

    if (func_name.compare("auth") == 0)
    {
        client_data_list.pop_front();
        return auth(client_data_list.at(0), client_data_list.at(1));
    }
    else if (func_name.compare("reg") == 0)
    {
        client_data_list.pop_front();
        return reg(client_data_list.at(0), client_data_list.at(1), client_data_list.at(2));
    }
    else if (func_name.compare("dijkstra") == 0){
        client_data_list.pop_front();
        QString temp = dijkstra(client_data_list.at(0), (client_data_list.at(1)).toInt(), (client_data_list.at(2)).toInt());
        return temp.toUtf8();
    }
    else if (func_name.compare("bisection_method") == 0){
        client_data_list.pop_front();
        QString temp1, temp2, d;
        d = check_descr((client_data_list.at(0)).toFloat(), (client_data_list.at(1)).toFloat(),
                        (client_data_list.at(2)).toFloat());
        if (d == "no_roots")
        {
            return QString("0").toUtf8();
        }
        else if (d == "1_root")
        {
            return QString::number(-((client_data_list.at(1)).toFloat()) / (2 * (client_data_list.at(0)).toFloat())).toUtf8();
        }
        else{
            temp1 = (bisection_method((client_data_list.at(0)).toFloat(), (client_data_list.at(1)).toFloat(),
                                      (client_data_list.at(2)).toFloat(), -1000, 0));
            temp2 = (bisection_method((client_data_list.at(0)).toFloat(), (client_data_list.at(1)).toFloat(),
                                     (client_data_list.at(2)).toFloat(), 0, 1000));
            if(temp1 == "nan" || temp2 == "nan"){
                return QString("0").toUtf8();
            }
            else{
                return QString(temp1 + "&" + temp2).toUtf8();
            }
        }
    }
        else
    {
        return "error\n";
    }
}
QByteArray auth(QString log, QString pass)
{
    QStringList querySrc;
    querySrc.append("SELECT login, password FROM users WHERE login == :login and password == :password;");
    querySrc.append(":login");
    querySrc.append(log);
    querySrc.append(":password");
    querySrc.append(pass);
    // qDebug()<<querySrc;
    querySrc = Database::getInstance().queryToDatabase(querySrc);
    if (querySrc.size() > 0)
    {
        return (QString("1")).toUtf8();
    }
    else
    {
        return "auth-";
    }
}

QByteArray reg(QString log, QString pass, QString mail)
{
    if (isValidEmail(mail))
    {
        QStringList querySrc;
        querySrc.append("SELECT login, password FROM users WHERE login == :login");
        querySrc.append(":login");
        querySrc.append(log);
        querySrc.append(":password");
        querySrc.append(pass);
        querySrc = Database::getInstance().queryToDatabase(querySrc);
        if (querySrc.size() > 0)
        {
            return "reg-\n";
        }
        else
        {
            querySrc.append("INSERT INTO users (login, password, email) VALUES (:login, :password, :email);");
            querySrc.append(":login");
            querySrc.append(log);
            querySrc.append(":password");
            querySrc.append(pass);
            querySrc.append(":email");
            querySrc.append(mail);
            querySrc = Database::getInstance().queryToDatabase(querySrc);
            if (querySrc.size() > 0)
            {
                return (QString("reg+&") + log + "\n").toUtf8();
            }
            else
            {
                return "failed to register user\n";
            }
        }
    }
    else
    {
        return "wrong email\n";
    }
}

QByteArray encript(QByteArray src)
{
    QByteArray res;
    res = src;
    // реализация rsa;
    return res;
}

bool isValidEmail(QString email)
{
    std::string email2 = email.trimmed().toUtf8().constData();
    qDebug() << email2;
    const std::regex emailPattern(
        "(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$)");

    return std::regex_match(email2, emailPattern);
}

QByteArray viewStat(){
    QString stat = "ivanov&12&4";// из БД
    return encript(stat.toUtf8());
}

QString dijkstra(QString points, int size, int src) {
    const int INF = std::numeric_limits<int>::max();
    QString reply;
    reply.clear();

    QStringList temp = points.split(" ");
    temp.pop_back();

    QVector<QVector<int>> graph(size, QVector<int>(size));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            graph[i][j] = temp.first().toInt();
            temp.pop_front();
        }
    }

    std::vector<int> dist(size, INF);
    std::vector<bool> visited(size, false);
    dist[src] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = -1;
        for (int i = 0; i < size; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        reply.push_back(QString::number(dist[i]));
        reply.push_back(" ");
        qDebug() << i << "\t" << dist[i];
    }

    qDebug() << reply;
    return reply;
}

QString bisection_method(float a, float b, float c, float x_low, float x_high){
    qDebug() << "function called";
    QString res;

    if (f(x_low, a, b, c) * f(x_high, a, b, c) >= 0)
    {
        res = QString::number(NAN);
        return res;
    }

    while ((x_high - x_low) / 2.0 > tolerance)
    {
        float x_mid = (x_high + x_low) / 2.0;
        if (f(x_mid, a, b, c) == 0)
        {
            res = QString::number(x_mid);
            //qDebug() << res.toFloat();
            return res;
        }
        else if (f(x_low, a, b, c) * f(x_mid, a, b, c) < 0)
        {
            x_high = x_mid;
        }
        else
        {
            x_low = x_mid;
        }
    }
    res = QString::number((x_high + x_low) / 2.0);
    qDebug() << res.toFloat();
    return res;
}

float f(float x, float a, float b, float c)
{
    return a * x * x + b * x + c;
}

QString check_descr(float a, float b, float c){
    float d = b * b - 4 * a * c;
    if (d < 0)
    {
        return QString("no_roots");
    }
    else if (d == 0)
    {
        return QString("1_root");
    }
    return QString("2_roots");
}
