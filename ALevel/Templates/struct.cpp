#include <stdio.h>

struct studentInfo
{
    int id;
    char gender;
    // 默认构造函数
    // studentInfo(int _id, char _gender ) 
    // {
    //     // 赋值
    //     id = _id;
    //     gender = _gender;
    // }

    studentInfo( ) {}
    studentInfo(int _id, char _gender): id(_id),gender(_gender) {}
};

int main(int argc, char const *argv[])
{
	studentInfo stu = studentInfo(123,'M');
	studentInfo stu2;

	printf("%d\n", stu.id);
	return 0;
}