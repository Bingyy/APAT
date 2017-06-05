#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1010;

vector<int> G[maxn]; // 邻接表存储图：注意本题是无向图
int currentPoint; // 当前需要删除的点
bool vis[maxn] = {false};

void dfs(int v) // 从编号为v的顶点开始深度遍历：记住深度遍历需要做什么
{
	// dfs的目的是标记该连通块下的顶点全部被标记

	// 递归边界
	if(v == currentPoint) return; //如果是删除的顶点，则直接返回

	// 处理当前层:标记该顶点已经被访问
	vis[v] = true;

	// 递归式
	for(int i = 0; i < G[v].size(); i++)
	{
		// 遍历v所有的邻接点：前提是未访问才进入访问
		if(vis[G[v][i]] == false)
		{
			dfs(G[v][i]); 
		}
	}
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int a,b;
	// 根据输入的数据建立图
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&a, &b);
		G[a].push_back(b); // b是a可达的点
		G[b].push_back(a); // a是b可达的点
	}

	// 处理查询
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &currentPoint);
		fill(vis,vis + maxn, false);
		int block = 0; // 计算连通块数
		for(int j = 1; j <= n; j++) // 枚举每个顶点
		{
			if(j != currentPoint && vis[j] == false)
			{
				dfs(j); // 从该顶点深度遍历该顶点所在的连通块
				block++; // 连通块数自增，能进到这块执行的，表示这个是单独的连通块
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}