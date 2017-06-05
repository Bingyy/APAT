#include <iostream>
#include <string>
#include <map>

using namespace std;

bool check(char c)
{
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	else return false;
}

int main()
{
	map<string, int> count; //统计单词出现的次数

	// 学习这种单词划分的思路：由字符串遍历，判定是否为有效字符进行划分
	string str;
	getline(cin,str);

	int i = 0;
	
	while(i < str.length())
	{
		string word = "";
		while(i < str.length() && check(str[i])) // 有效字符
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;// 大写化为小写
			}
			word += str[i]; //将有效字符加在word后面
			i++;
		}
		
		if(word != "") // 单词非空，计算单词的个数
		{
			if(count.find(word) == count.end())
			{
				count[word] = 1; // 第一次出现，则令其个数为1
			}
			else
			{
				count[word]++;
			}
		}
		while(i < str.length() && !check(str[i]))// 非有效字符时，指针右移即可
		{
			i++;
		}
	}

	string ans;
	int MAX = 0;
	for(auto it = count.begin(); it != count.end(); it++)
	{
		if(it->second > MAX) // 寻找出现次数最多的单词
		{
			MAX = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << MAX << endl;
	return 0;
}