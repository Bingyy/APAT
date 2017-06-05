#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 这种直观的写法可以拿到23分，最后一个测试点2分拿不到，因为超时，为了解决这个问题，需要不借助map实现映射
// 这里的映射是string到vector，可以选择让string变成int，写一个运算函数即可

// 最直观的思路是用map<string, vector<int> > : 学生id--选课列表
map<string, vector<int> > lst;
vector<string> query;// 存储查询的学生姓名
int main()
{
	int n,k;//n:查询的学生数，k:课程数，从1~k编号
	cin >> n >> k;
	for(int i = 0; i < k; i++)
	{
		// 循环课程数目次数，输入每门课的选课学生
		int courseIndex,stuNum; 
		cin >> courseIndex >> stuNum;
		string name;
		for(int i = 0; i < stuNum; i++)
		{
			cin >> name;
			lst[name].push_back(courseIndex); // 将姓名与课程的映射写入map
		}
	}

	for(auto it = lst.begin(); it != lst.end(); it++)
	{
		// 用索引器：it->second 索引到数组
		// 对每一个输入的课程列表进行排序
		sort(it->second.begin(),it->second.end());
	}
	for(int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		query.push_back(name);
	}


	// 控制输出
	for(int i = 0; i < n; i++)
	{
		int len = lst[query[i]].size(); // 取得vector的长度
		cout << query[i] << " " << len;
		if(len > 0)
		{
			cout << " ";
		}
		for(int j = 0; j < len; j++)
		{
			cout << lst[query[i]][j];
			if(j < len - 1)
			{
				cout << " ";
			}
		}
		cout << endl;	
	}
	return 0;
}