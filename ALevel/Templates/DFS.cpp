#include <stdio.h>
#include <vector>

using namespace std;

// 邻接矩阵版
const int maxv = 1000;
const int inf = 1000000000;

int n,G[maxv][maxv]; // n是顶点数

bool visited[maxv] = {false};

void DFS(int u,int depth)
{
	visited[u] = true;
	// 对u的一些操作

	// 对所有从u出发能到达的分支进行遍历
	for(int v = 0; v < n;v++)
	{
		if(visited[v] == false && G[u][v] != INF)
		{
			DFS(v,depth + 1); 
		}
	}
}

void DFSTraverse()
{
	for(int u = 0; u < n; u++) // 对每个顶点u，从u出发
	{
		if(visited[u] == false)
		{
			DFS(u,1); // 1表示第一层
		}
	}
}

// 邻接表版

vector<int> Adj[maxv]; // 每一个Adj[i]是个vector

int n;
bool visited[maxv] = {false};

void DFS(int u, int depth)
{
	visited[u] = true;
	for(int i = 0; i < Adj[u].size(); i++)
	{
		int v = Adj[u][i]; // 获取终点下标
		if(visited[v] == false) //这是在邻接表中找，因此一定是存在的边
		{
			DFS(v,depth + 1);
		}

	}
}

void DFSTraverse()
{
	for(int u = 0; u < n; u++)
	{
		if(visited[u] == false)
		{
			DFS(u,1);
		}
	}
}



int main()
{

	return 0;
}