#include <iostream>
#include <string>

using namespace std;



class Student
{
    private:
        string fullName;
    public:
        Student()
        {
            cout<<"Inside of the no-argument constructor"<<endl;
        }

        Student(string name) : fullName(name)
        {
            cout<<"Inside of the 1-argument constructor for the object ->"<<fullName<<endl;
        }

        virtual ~Student()
        {
            cout<<"Inside the destructor"<<endl;
        }
};


int main(void)
{
    const Student student_1("George Calin");
    //Student& student2 = student_1; // error will be fetched 
    /*
    qualifiers dropped in binding reference of type "Student &" to initializer of type "const Student"C/C++(433)
    const Student student_1
    */

    Student& student3 = const_cast<Student&>(student_1);

    return 0;
}