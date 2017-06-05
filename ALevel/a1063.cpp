#include <stdio.h>
#include <set>
using namespace std;
const int N = 51;
set<int> st[N]; // n个集合

void compare(int x, int y)
{
	// 比较集合st[x]和st[y]
	int totalNum = st[y].size(), sameNum = 0;
	// 遍历集合st[x]
	for(auto it = st[x].begin(); it != st[x].end(); it++)
	{
		if(st[y].find(*it) != st[y].end())
		{
			sameNum++; // 如果st[y]中有st[x]中的元素，find函数返回的是迭代器
		}
		else
		{
			totalNum++; // 找不到就意味着这是st[x]独有的，因此总数要++
		}
	}
	printf("%.1f%\n",sameNum * 100.0 / totalNum);
	
}

int main()
{
	int n, k, q,v,st1, st2;
	scanf("%d", &n);

	// 处理输入的数据：输入的数据有重复，需要打入set进行过滤
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &v);
			st[i].insert(v);
		}
	}

	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		scanf("%d%d", &st1, &st2);
		compare(st1, st2);
	}
	return 0;
}