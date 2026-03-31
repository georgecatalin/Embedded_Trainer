#include "student.h"
#include "school.h"


int main(void)
{
    Student student("George");
    School school(29);

    school.admitStudent(student);
    school.expelStudent(student);


    return 0;
}