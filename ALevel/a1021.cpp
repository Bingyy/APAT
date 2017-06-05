#include <stdio.h>
#include <algorithm>
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

int maxH = 0; // 最大高度
vector<int> temp, ans; // temp临时存放DFS的最远结点结果，ans保存答案

// 这个递归函数就是求从一个顶点出发遍历求得最大深度的顶点集合
void dfs_max_height(int u, int height,int pre)
{
	// u : 当前访问结点编号， height:当前树高，pre:u的父结点
	if(height > maxH)
	{
		temp.clear();
		temp.push_back(u);
		maxH = height;
	}
	else if(height == maxH)
	{
		temp.push_back(u);
	}

	for(int i = 0; i < G[u].size(); i++)
	{
		if(G[u][i] == pre) continue; //无向图，跳过回去的边
		dfs_max_height(G[u][i],height + 1, u); // 访问子结点
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
	if(block != 1)
	{
		printf("Error: %d components\n", block);
	}
	else
	{
		dfs_max_height(1,1,-1); // 从1号结点开始遍历：随便一个即可，初始高度为1
		ans = temp; // 将第一次遍历的结果赋给ans
		dfs_max_height(ans[0],1,-1); //从ans集合中随便选一个开始遍历
		for(int i = 0; i < temp.size(); i++)
		{
			ans.push_back(temp[i]);
		}
		sort(ans.begin(), ans.end());
		// 控制输出
		printf("%d\n",ans[0]);
		for(int i = 1; i < ans.size(); i++)
		{
			if(ans[i] != ans[i - 1]) // 重复的不输出
			{
				printf("%d\n", ans[i]);
			}
		}
	}
}