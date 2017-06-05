// 邻接矩阵版本的BFS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 1000;
const int INF = 1000000000;

int G[maxn][maxn] = {0};//邻接矩阵
bool inq[maxn] = {false}; // 标记是否入队


void BFS(int u) // 遍历u所在的连通块,这里没有
{
	queue<int> q;
	inq[u] = true;
	q.push(u);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v = 0; v < n; v++)
		{
			if(inq[v] == false && G[u][v] != INF) // 通过联合判断G[u][v] != INF
			{
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

// 遍历图
void BFSTraverse()
{
	for(int u = 0; u < n; u++)
	{
		if(inq[u] == false) // 单个连通块访问一定全都入队过，反之，未入队的即为未访问过
		{
			BFS(u);
		}
	}
}

/*邻接表版*/
vector<int> Adj[maxn]; //jagged-array

int n;
bool inq[maxn] = {false};

void BFS(int u)
{
	queue<int> q;
	q.push(u); // 初始点u入队
	inq[u] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < Adj[u].size(); i++)// 查找规模也小于邻接矩阵
		{
			int v = Adj[u][i]; //这个直接是在邻接表里找，更准确
			if(inq[v] == false)
			{
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

// 遍历图
void BFSTraverse()
{
	for(int u = 0; u < n; u++)
	{
		if(inq[u] == false)
		{
			BFS(u);
		}
	}
}

//记录层号版本：借助结构体实现

struct node
{
	int vertex; //结点编号
	int layer; //结点所在层号：根据当前BFS得到，如果BFS不同，则层号相应有区别
};

vector<node> Adj[maxn];

void BFS(int u) //起始顶点编号
{
	queue<node> q;
	node start;
	start.vertex = u;
	start.layer = 0; //起始作为0层
	q.push(start);

	inq[start.vertex] = true; 

	while(!q.empty())
	{
		node topNode = q.front();
		q.pop();
		
		int u = topNode.vertex;

		for(int i = 0; v < Adj[u].size(); v++)
		{
			node next = Adj[u][i];
			next.layer = topNode.layer + 1;

			if(inq[next.vertex] == false) 
			{
				q.push(next);
				inq[next.vertex] = true;
			}
		}
	}
}

int main()
{
	return 0;
}





