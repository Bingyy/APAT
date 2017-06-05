#include <iostream>
#include <string>

using namespace std;
// 2017-2-26 15:34

int n; // 有效位数

// 去除前导0的套路再现：在大数中也用这个方法处理过进位后的数据
string deal(string s, int &e)
{
	int k = 0; // s的下标
	while(s.length() > 0 && s[0] == '0')
	{
		s.erase(s.begin());//数据长度大于0且第一位是0时，s会被清空，这个情况后面需要特判
	}

	if(s[0] == '.') // 去掉前导0后，第一个数据是小数点，表示原数据是个小数
	{
		s.erase(s.begin()); // 去掉小数点
		while(s.length() > 0 && s[0] == '0')
		{
			// 去掉小数点后，每去掉一个0，指数减1
			s.erase(s.begin());
			e--;
		}
	}
	else
	{
		// 去掉前导零后不是小数点，找到后面的小数点删去，找到的过程中计算指数
		while(k < s.length() && s[k] != '.')
		{
			k++;
			e++;
		}

		if(k < s.length())
		{
			// while循环结束后,k比s.length()小，说明遇到了小数点
			s.erase(s.begin() + k);
		}
	}

	if(s.length() == 0)
	{
		e = 0;
	}

	int num = 0;
	k = 0;
	string res;

	while(num < n)
	{
		if(k < s.length())
		{
			res += s[k++];
		}
		else
		{
			res += '0';
		}
		num++; // 精度位数
	}
	return res;
}

int main()
{
	string s1,s2,s3,s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1,e1);
	s4 = deal(s2,e2);
	if(s3 == s4 && e1 == e2)
	{
		cout << "YES 0." << s3 <<"*10^" << e1 << endl;
	}
	else
	{
		cout << "NO 0." << s3 <<"*10^" << e1 << " 0."<< s4 <<"*10^" << e2 <<endl;
	}
	
	return 0;
}