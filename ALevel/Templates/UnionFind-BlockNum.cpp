#include <stdio.h>
#include <vector>

using namespace std;

const int maxn = 100010;
vector<int> G[maxn]; // 邻接表存储图

bool isRoot[maxn] = {false}; // 标记是否访问
int pre[maxn];
int Find(int x)
{
	int r = x;
	while(x != pre[x])
	{
		x = pre[x];
	}

	// 路径压缩:此时x已经是老大
	int j;
	while(r != pre[r])
	{
		j = r;
		r = pre[r];
		pre[j] = x;
	}

	return x;
}

void Union(int a, int b)
{
	int preA = Find(a);
	int preB = Find(b);
	if(preA != preB)
	{
		pre[preA] = preB;
	}
}

int calculateBlockNum(int n)
{
	int block = 0;
	for(int i = 1; i <= n; i++) // 枚举所有顶点
	{
		isRoot[Find(i)] = true;// 这样同样的数字只计算一次
	}
	for(int i = 1; i <= n; i++)
	{
		block += isRoot[i]; //true当1用，false当0用
	}
	return block;
}

void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		pre[i] = i;
	}
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	init(n); // 很重要很重要！
	for(int i = 1; i < n; i++) // n - 1条边
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
		Union(a,b); // 合并顶点a,b所在的集合
	}

	int block = calculateBlockNum(n);

	printf("%d\n",block);
}