#include <stdio.h>
#include <vector>

using namespace std;

const int MAXN = 1000;
const int INF = 1 << 30;
int d[MAXN] = {INF};
int G[MAXN][MAXN];
int n; // 顶点数

bool visited[MAXN] = {false};

void Dijkstra_Matrix(int s)
{
	fill(d,d+MAXN,INF);
	d[s] = 0;
	for(int i = 0; i < n; i++)
	{
		// 先找u
		int u = -1, MIN = INF;
		for(int j = 0; j < n;j++)
		{
			if(visited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) return;
		visited[u] = true;

		for(int v = 0; v < n; v++)
		{
			if(visited[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
			{
				d[v] = d[u] + G[u][v];
			}
		}
	}
}

struct node
{
	int v, dis; // v是顶点表中结点编号，dis是顶点到起始点的距离
};
vector<node> Adj[MAXN];

void Dijkstra_Adj(int s)
{
	fill(d, d+MAXN, INF);
	d[s] = 0;

	for(int i = 0; i < n; i++)
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
		for(int j = 0; j < Adj[u].size();j++) // j是邻接表下标
		{
			int v = Adj[u][j].v;//v是顶点表的下标
			if(visited[j] == false && d[u] + Adj[u][j].dis < d[v])// d数组用的是顶点表中下标
			{
				d[v] = d[u] + Adj[u][j].dis; 
			}
		}
		
	}
}

int main()
{
	return 0;
}