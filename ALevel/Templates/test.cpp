#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

map<int,int> mp;

char s[1][3];

bool cmp(int a, int b)
{
	return a > b;
}


int hashID(char id[])
{
	int len = strlen(id);
	int intId = 0;
	for(int i = 0; i < len; i++)
	{
		intId = 10 * intId + id[i] - '0';
	}
	return intId;
}

int main()
{
	// vector<int> ins = {2,3,4,1};
	// sort(ins.data(),&ins[3] + 1);

	// for(auto it = ins.begin(); it != ins.end();it++)
	// {
	// 	printf("%d ",(int)(it-ins.begin()) + 1);
	// }
	// printf("%d\n" ,grades[5]);
	// gets(s[0]);
	// printf("%s\n", s[0]);
	// reverse(s[0],s[0]+3); //reverse是左开右闭
	// printf("%s\n",s[0]);

	// int a[4] = {3,1,2,2};

	// // 测试排序：non-increasing, non-decreasing都不用在cmp中写出=号
	// sort(a,a+4,cmp);
	// for(int i = 0; i < 4; i++)
	// {
	// 	printf("%d ", a[i]);
	// }

	// mp.insert(make_pair(5,6));
	// mp[5] = 6;
	// char id[5] = "1234";
	// int intId = hashID(id);

	// printf("%d\n",mp[5]);

	char str[10];
	int n;
	scanf("%s", str);
	getchar(); // 接收换行符
	scanf("%d",&n);
	printf("%s\n", str);
	return 0;
}