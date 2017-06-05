#include <stdio.h>
#include <vector>
using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

// 邻接矩阵版适合点数小于1000左右的问题

int n, G[MAXV][MAXV];// n是顶点数，这里可能会觉得G[n][n]就可以，但是注意n还是没确定的数
int d[MAXV]; // 起点到各顶点的最短路径长度
int pre[MAXV];//记录从起点到顶点v的最短路径v的前一个顶点
bool visited[MAXV] = {false}; // 标记数组，visited[i] == true表示已经访问

void Dijkstra(int s) // s是起始顶点
{
	// 初始化
	fill(d,d+MAXV,INF); // 左开右闭，还是老规矩
	d[s] = 0; // 顶点到自身的距离是0
	for(int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF; // u是需要确定的最小距离的且未访问的标号
		for(int j = 0; j < n;j++) // 这个循环就是为了找到未访问的顶点中距离起点最小的
		{
			if(visited[j] == false && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if(u == -1) // 找不到最小的顶点了，表示剩下的顶点和s不通
		{ 
			return;
		}

		// 标记u已经被访问
		visited[u] = true;

		for(int v = 0; v < n; v++)
		{
			// v未访问且u能到达v，且以u为中介可以优化使得d[v]更小
			// 值得注意的是G[i][j]是输入时就已经搞定的
			if(visited[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v])
			{
				d[v] = d[u] + G[u][v]; // G[u][v]标记u到v的距离
				pre[v] = u;//记录v的前驱结点u
			}
		}
	}
}

// 邻接表版
struct node
{
	int v, dis; // v是目标顶点，dis是边权
};

vector<node> Adj[MAXV]; // Adj[u] 存放从顶点u出发可以到达的所有顶点,Adj[u]也是个vector

int n;
int d[MAXV];
bool visited[MAXV] = {false};

void Dijkstra(int s)
{
	// 初始化
	fill(d, d+MAXV, INF);
	d[s] = 0; // 开始也是d[s] = INF,这里征服以后记为0

	// 找到使得d[u]最小的且未被访问的顶点标号
	for(int i = 0; i < n;i++)
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
		visited[u] = true;//标记为已访问

		// 以上均是通用的写法，下面是有别于矩阵写法的
		for(int j = 0; j < Adj[u].size(); j++) //控制循环次数,且下标j是邻接表的下标
		{
			int v = Adj[u][j].v; // 直接拿到u可以到达的顶点
			if(visited[v] == false && d[u] + Adj[u][j].dis < d[v])
			{
				d[v] = d[u] + Adj[u][j].dis; //如果经过u这个顶点可以优化原来的距离，果断优化之
			}
		}
	}
}



