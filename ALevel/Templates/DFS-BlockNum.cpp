#include <stdio.h>
#include <vector>

using namespace std;

const int maxn = 100010;
vector<int> G[maxn]; // 邻接表存储图

bool vis[maxn] = {false}; // 标记是否访问

void dfs(int v)
{
	vis[v] = true;
	for(int i = 0; i < G[v].size(); i++)
	{
		if(vis[G[v][i]] == false)
		{
			dfs(G[v][i]); // 如果该顶点未访问，深度遍历之
		}
	}
}

int main()
{
	int n, a, b;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) // n - 1条边
	{
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int block = 0;
	// 枚举所有顶点
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == false)
		{
			dfs(i);
			block++;
		}
	}

	printf("%d\n",block );
}