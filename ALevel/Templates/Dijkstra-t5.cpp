#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

const int maxn = 1010;
const int inf = 1 << 30;
int d[maxn] = {0};
bool vis[maxn] = {false};
int n; // 结点数
int weight[maxn] = {0};
int w[maxn] = {0};  // 取最大值为最优
vector<int> pre[maxn] ; // 存储所有最小路径
vector<int> path, tempPath; // 存储最优路径，临时路径
int st,ed;
struct node
{
	int v, dis;
};

vector<node> Adj[maxn];

void Dijkstra(int s)
{
	// 初始化
	fill(d,d + maxn, 0);
	d[s] = 0;

	for(int i = 0; i < n; i++)
	{
		// 寻找u
		int u = -1, MIN = inf;
		for(int j = 0; j < n; j++)
		{
			if(vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return; //找不到满足的结点
		vis[u] = true;

		// 优化距离
		for(int j = 0; j < Adj[u].size(); j++)
		{
			int v = Adj[u][j];
			if(vis[v] == false && d[u] + Adj[u][v].dis < d[v])
			{
				d[v] = d[u] + Adj[u][v].dis;
			}
		}
	}
}

void dfs(int v) // 当前访问结点
{
	if(v == st) // 到达叶子结点
	{
		tempPath.push_back(v);

		int value; // 最优值
		if(optValue < value)
		{
			// 优化最优值
			optValue = value;
			path = tempPath;
		}

		tempPath.pop_back(v);
		return;
	}

	tempPath.push_back(v);

	for(int i = 0; i < pre[v].size(); i++)
	{
		dfs(pre[v][i]);
	}
	tempPath.push_back(v);
}

int main()
{
	return 0;
}