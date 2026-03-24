#include <iostream>
#include <cstring>

using namespace std;


class Student
{
    private:
      char name[50];
    public:
      Student(const char entered_name[50])
      {
        cout<<"The constructor was called with the string "<<entered_name<<endl;

        strcpy(name,entered_name);
        cout<<"The object was initialized with the member variable ->"<<name<<endl;

      }

      void print()
      {
        cout<<"Student object {name="<<name<<") "<<endl;
      }

      ~Student()
      {
        cout<<"The destructor was called for the object "<<name<<endl;
      }
};

int main(void)
{
    const char the_name[50] = "George Calin";
    const char the_name_1[50] = "Mara Calin";
    Student s1(the_name),s2(the_name_1);

    s1.print();
    s2.print();

    cout<<"The main function completed its execution. exiting now.."<<endl;

    return 0;
}