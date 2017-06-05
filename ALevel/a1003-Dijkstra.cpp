#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxv = 510; // 最大顶点数
const int inf = 1 << 30;

int G[maxv][maxv],weight[maxv]; // 定义图的邻接矩阵存法，点权
int d[maxv] = {inf} ; //记录路基
int n,m,st,ed; // n:顶点数，m:边数
int w[maxv],num[maxv]; // w：记录最大点权之和，num:最短路径条数
bool vis[maxv] = {false}; // 标记是否已经访问


// 最朴素的迪杰斯塔拉就是为了找到最短路径，最终效果是更新了d数组，
// 但是在产生d数组的过程中，有意思的事情正在发生

void Dijkstra(int s) 
{
	// 初始化
	fill(d,d + maxv, inf);
	fill(num,num + maxv, 0);
	fill(w,w + maxv, 0);
	d[s] = 0;
	w[s] = weight[s]; 
	num[s] = 1; 

	// 循环n次
	for(int i = 0; i < n; i++)
	{
		// 找到u和最小值
		int u = -1, MIN = inf;
		for(int j = 0; j < n; j++)
		{
			if(vis[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}

		if(u == -1) return; // 没有找到
		vis[u] = true; // 找到了就标记为已经访问

		// 优化路径长度
		for(int v = 0; v < n; v++)
		{
			if(vis[v] == false && G[u][v] != inf)
			{
				if(d[u] + G[u][v] < d[v]) // 这个条件拿下来用
				{
					d[v] = d[u] + G[u][v]; // 覆盖
					w[v] = w[u] + weight[v]; // 最短路径的权重更大
					num[v] = num[u];
				}
				else if(d[u] + G[u][v] == d[v]) // 最短路径有相同的，这时候就看点权之和
				{
					if(w[u] + weight[v] > w[v])
					{
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}

int main()
{	
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&weight[i]);
	}
	int u, v;
	fill(G[0],G[0] + maxv * maxv, inf);// 初始化二维数组的写法
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);//读入边权
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
}