#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
const int maxv = 510;
const int inf = 1 << 30;

int n,m,Cmax,Sp,numPath = 0, G[maxv][maxv],weight[maxv];

int d[maxv],minNeed = inf, minRemain = inf;
bool vis[maxv] = {false};
vector<int> pre[maxv]; // 存放前驱
vector<int> tempPath,path; // 临时路径以及最优路径

void Dijkstra(int s)
{
	fill(d,d + maxv, inf);
	d[s] = 0;
	for(int i = 0; i < n; i++)
	{
		int u = -1, MIN = inf;
		for(int j = 0; j <= n; j++)
		{
			if(!vis[j] && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		if(u == -1) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++)
		{
			if(!vis[v] && G[u][v] != inf)
			{
				if(d[u] + G[u][v] < d[v])
				{
					d[v] = d[u] + G[u][v];
					pre[v].clear(); //
					pre[v].push_back(u);
				}
				else if(d[u] + G[u][v] == d[v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}


void DFS(int v)
{
	if(v == 0) // 递归边界，叶子结点
	{
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--)
		{
			int id = tempPath[i];
			if(weight[id] > 0)
			{
				remain += weight[id];
			}
			else
			{
				if(remain > abs(weight[id]))
				{
					remain -= abs(weight[id]);
				}
				else
				{
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if(need < minNeed)
		{
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		}
		else if(need == minNeed && remain < minRemain)
		{
			// 携带数目相同但是带回数目更少
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}


int main()
{
	scanf("%d%d%d%d", &Cmax, &n, &Sp, &m);
	int u, v;
	fill(G[0], G[0] + maxv * maxv, inf);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &weight[i]);
		weight[i] -= Cmax / 2; // 点权减去容量的一半
	}
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	// Dijkstra + DFS : 标准模板写法
	Dijkstra(0); //
	DFS(Sp);
	printf("%d ", minNeed);
	for(int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d", path[i]);
		if(i > 0) printf("->");
	}
	printf(" %d",minRemain);
	printf("\n");
	return 0;
}