#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int n,m, col;
	scanf("%d%d", &n, &m);
	map<int,int> count;

	// 处理输入数据
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &col);
			if(count.find(col) != count.end())
			{
				count[col]++;
			}
			else
			{
				count[col] = 1; // 首次出现，赋值为1
			}
		}
	}

	// 处理输出
	int k = 0, MAX = 0;
	for(auto it = count.begin(); it != count.end(); it++)
	{
		if(it->second > MAX)
		{
			k = it->first; // 记录数字
			MAX = it->second;  // 更新最大次数
		}
	}

	printf("%d\n", k);
	return 0;
}