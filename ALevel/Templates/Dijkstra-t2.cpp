#include <stdio.h>
#include <vector>

using namespace std;

int MAXN = 1000;
int INF = 1 << 30;

int n; // 顶点数
int d[MAXN] = {INF}; 
bool visited[MAXN] = {false};

struct node
{
	int v, dis; // v是顶点编号，dis是距离起始点距离
};

vector<node> Adj[MAXN]; // 用vector数组表示邻接表

// 邻接表版
void Dijkstra_Adj(int s)// 起点
{
	// 初始化
	fill(d,d+MAXN,INF);
	d[s] = 0;
	//寻找最小的顶点下标u
	for(int i = 0; i < n; i++) // 控制循环n次，目的是为了n次从V-S中找到距离起始点最小的下标，S初始为空集
	{
		int u = -1, MIN = INF; //找u，自然需要初始化，MIN是辅助变量
		for(int j = 0; i < n; i++)
		{
			if(visited[j] == false && d[j] < MIN) // 起始d[s] = 0作为奠基，j也是从0开始
			{
				u = j;
				MIN = d[j];
			}
		}
		// 找到u了吗？
		if(u == -1) return; //没有找到，结束

		visited[u] = true;//找到了！

		for(int j = 0; j < Adj[u].size();j++)// 在u的邻接表中操作
		{
			int v = Adj[u][j].v;//注意区别顶点表下标和邻接表下标：v是顶点表下标，j是邻接表下标
			if(visited[j] == false && d[u] + Adj[u][j].dis < d[v])
			{
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}
}

int G[MAXN][MAXN];

void Dijkstra_Matrix(int s)
{
	//初始化
	fill(d,d+MAXN, INF);
	d[s] = 0; //这句也非常关键

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

		//u是否已经找到？
		if(u == -1) return;
		visited[u] = true;
		for(int j = 0; j < n;j++)
		{
			if(visited[j] == false && G[u][j] != INF && d[u] + G[u][j] < d[j]) // 邻接表中确定是相连的，这里需要再循环找到邻接的以确定修改
			{
				d[j] = d[u] + G[u][j];
			}
		}
	}
}
int main()
{

	return 0;
}