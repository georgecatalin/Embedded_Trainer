#include <QCoreApplication>
#include <QDebug>

template<class T>
void print(T value)
{
    qInfo()<<value;
}


template<typename T,typename F>
T add(T value1, F value2)
{
    return value1 + value2;
}




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    print<int>(1978);
    print<float>(3.14);
    print<QString>(QString("George Calin"));


    qInfo()<<add<int,int>(1,4);
    qInfo()<<add<float,float>(1.3,3.14);
    qInfo()<<add<float,bool>(3.14,true); //4.14
    qInfo()<<add<bool,float>(true,3.14); // true because 4.14 is non zero hence true
    //qInfo()<<add<QString,int>("George",3); //error unable .unknown how to convert QString to int


    return QCoreApplication::exec();
}
