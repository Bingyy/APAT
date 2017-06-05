#include <stdio.h>
#include <vector>

using namespace std;

const int maxn = 1010;

vector<int> G[maxn]; // 邻接表法存储图

int pre[maxn];
int n; // n是结点总数
bool vis[maxn]; // 记录结点是否被访问

int Find(int x) // 找到下标为x的元素的老大，含路径压缩
{
	int r = x;
	while(x != pre[x])
	{
		x = pre[x]; //x一路往上
	}

	// 路径压缩:此时x已经是大boss
	int j;
	while(r != pre[r])
	{
		j = r; // 暂存
		r = pre[r]; // 为下一步循环做准备
		pre[j] = x; // 从原有的下标x开始一直往上全都赋值为大boss直接管辖

		// 这样写是妥妥的错解
		// pre[r] = x;
		// r = pre[r]; 
	}
	return x;
}

void Union(int a, int b)
{
	int preA = Find(a);
	int preB = Find(b);
	if(preA != preB)
	{
		pre[preA] = preB; //后面是老大，这样
	}
}

void init()
{
	for(int i = 1; i < maxn; i++)
	{
		pre[i] = i;
		vis[i] = false;
	}
}

int main()
{
	int m,k;
	scanf("%d%d%d",&n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int currentPoint; // 当前需要删除的顶点号
	for(int query = 0; query < k; query++)
	{
		scanf("%d",&currentPoint);
		init();// 初始化数组，准备用并查集
		for(int i = 1; i <= n; i++) // 枚举每条边
		{
			for(int j = 0; j < G[i].size(); j++)
			{
				int u = i, v = G[i][j]; // 边的端点
				if(u == currentPoint || v == currentPoint)
				{
					// 如果任何一个顶点是删除的顶点，则与之相关的点都不参与并查集
					continue;
				}
				Union(u,v);
			}
		}
		int block = 0;
		for(int i = 1; i <= n; i++) // 遍历所有顶点
		{
			if(i == currentPoint) continue;
			int pre_i = Find(i);// 找到i所在的连通块的根
			if(!vis[pre_i])
			{
				block++;
				vis[pre_i] = true; //标记为已经访问
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}