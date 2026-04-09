#include <QCoreApplication>
#include "test.h"

using namespace std;

void function_1()
{
    qInfo()<<"START FUNCTION";
    unique_ptr<Test> automatedPtr(new Test());
    automatedPtr->doStuff();
    qInfo()<<"END FUNCTION. out of scope. pointer gets deleted automatically";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<<"START PROGRAM";
    {
        unique_ptr<Test> automatedPtr(new Test());
        automatedPtr->doStuff();
        //gets out of scope once the block ends, deconstructor called automatically
    }

    qInfo()<<"END PROGRAM";

    function_1();

    return QCoreApplication::exec();
}
