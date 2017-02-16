#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // 在oj上需要引入这个头文件

using namespace std;

typedef struct Node
{
	string ID;
	string signInTime;
	string signOutTime;
} Student;

// 只需要写两个比较函数即可
bool compare_in_time(Student a, Student b)
{
	return a.signInTime < b.signInTime; //升序排列
}

bool compare_out_time(Student a, Student b)
{
	return a.signOutTime > b.signOutTime; //降序排列
}


int main()
{
	int M;
	cin >> M;
	vector<Student> stus;

	for(int i = 0; i < M; i++)
	{
		Student student; // 存储在栈中
		cin >> student.ID >> student.signInTime >> student.signOutTime;
		stus.push_back(student);
	}
	sort(stus.begin(), stus.end(),compare_in_time);

	cout << stus[0].ID << " ";

	sort(stus.begin(), stus.end(),compare_out_time);
	cout << stus[0].ID << endl;
	
	return 0;
}
