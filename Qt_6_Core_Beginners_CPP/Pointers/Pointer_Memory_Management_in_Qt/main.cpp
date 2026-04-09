#include <QCoreApplication>
#include <QDebug>

void test(QString *some_variable)
{
    qInfo()<<"The address of the variable ->"<<&some_variable;
    qInfo()<<"The memory address it points to ->"<<some_variable;
    qInfo()<<"The value at the memory address it points to ->"<<*some_variable;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString string_stack = "George Calin"; //this is automatically managed by C++
    qInfo()<< "the address of string_stack "<<&string_stack<<" and the value "<<string_stack;

    QString *string_ptr = new QString("Mara Calin"); //this creates a string_ptr variable on the stack pointing for "Mara Calin" on the heap


    test(string_ptr);

    delete string_ptr;  //heap memory management has to be done manually

    return QCoreApplication::exec();
}
