#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Thank you for your smile.";
	string str2 = "you";
	string str3 = "me";

	if(str.find(str2) != string::npos)
	{
		cout << str.find(str2) << endl;
	}
	// 从指定的pos开始匹配字符串
	if(str.find(str2,7) != string::npos)
	{
		cout << str.find(str2,7) << endl;
	}
	
	return 0;
}