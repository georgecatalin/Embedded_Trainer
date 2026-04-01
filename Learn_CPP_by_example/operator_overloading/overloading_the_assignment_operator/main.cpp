#include "student.h"

int main(void)
{
    Student george("George Calin");

    george.print();
    Student alex("Alex Grapeanu");
    alex.print();

    george = alex;
    cout<<"post asignment "<<endl;
    george.print();

    return 0;
}