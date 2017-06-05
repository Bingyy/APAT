#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000;
const int INF = 1 << 30;


// 邻接矩阵版本
int n; //顶点数
int G[MAXN][MAXN] = {INF}; //
bool visited[MAXN] = {false}; // 标记是否已经访问
int d[MAXN] = {INF};

void Dijkstra_Matrix(int s) // 起点
{
	// 初始化
	fill(d,d+MAXN,INF);
	d[s] = 0;
	
	
	for(int i = 0; i < n; i++) //循环n次
	{
		// 寻找最小的顶点u
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++)
		{
			if(visited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}

		}
		// 找不到u，就表示已经找完，函数结束
		if(u == -1) return;
		//找到了就标记为已经访问
		visited[u] = true;

		// 优化可达的路径长度，无后效性
		// 需要遍历确定是否有边
		for(int v = 0; v < n; v++)
		{
			if(visited[v] == false && G[u][v] != INF && d[u] + d[u][v] < d[v])
			{
				d[v] = d[u] + d[u][v];
			}
		}
	}
}
// 邻接表版

struct node
{
	int v, dis; // v：顶点表中顶点编号，dis：距离起点距离
};
vector<node> Adj[MAXN];
void Dijkstra_Adj(int s)
{
	fill(d,d+MAXN,INF);
	d[s] = 0;
	for(int i = 0; i < n; i++)//也是循环n次
	{
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++)
		{
			if(visited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		visited[u] = true;

		// 在邻接表中直接确定可以到达的顶点
		for(int j = 0; j < Adj[u].size(); j++) // 横向是邻接表，纵向是顶点表哦
		{
			int v = Adj[u].v; // node中存的才是顶点表中的顶点下标
			if(visited[j] == false && d[u] + Adj[u][j].dis < d[v])
			{
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}
}


// 学会写Shader~

// 算法是可以撞开的，需要你持续投入时间，精力，思考



