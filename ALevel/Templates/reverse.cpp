#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// 翻转数组
	int a[10] = {1,2,3,4,5};

	reverse(a,a+5);


	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	// 翻转字符串
	string str = "abcdef";
	reverse(str.begin(), str.end());

	printf("%s", str.c_str());
	
	printf("\n");

	// 翻转容器：指定首尾迭代器，左开右闭
	vector<int> ins = {1,2,3,4,5};
	reverse(ins.begin(), ins.end());
	for (int i = 0; i < ins.size(); ++i)
	{
		printf("%d ", ins[i]);
	}
	printf("\n");
}