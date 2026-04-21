#include <QCoreApplication>
#include <QDebug>
#include <QIODevice>
#include <QBuffer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;
    if(buffer.open(QIODevice::OpenModeFlag::ReadWrite))
    {
        qInfo()<<"The buffer is open";

        QByteArray byteArray("Hello Mara How are you");

        for (int i = 0; i < 10; ++i)
        {
            buffer.write(byteArray);
            buffer.write("\r\n");
        }


        /*
         * QBuffer is reading — you’re just reading from the wrong position.
            After you write 10 times, the buffer’s internal position is at the end, so buffer.readAll() reads from current position
            to end → that’s an empty range, so you get nothing.
         */

        buffer.seek(0);

        qInfo()<<"Reading the buffer...";
        qInfo()<<buffer.readAll();


        qInfo()<<"Closing the buffer.";
        buffer.close();
    }
    else
    {
        qInfo()<<"Could not open the buffer";
    }

    qInfo()<<"Finished execution of the program.";

    return QCoreApplication::exec();
}

/*
The buffer is open
    Reading the buffer...
    "Hello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\nHello Mara How are you\r\n"
    Closing the buffer.
    Finished execution of the program.
*/
