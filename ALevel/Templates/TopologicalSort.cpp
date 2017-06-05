#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int maxv = 1 << 30;
vector<int> G[maxv]; // 以邻接表的方式存储图:这样很容易就找到以某个顶点开始的边的另一个端点，因此很容易更新入度
int n,m, inDegree[maxv]; // 记录顶点数，入度表
bool topologicalSort()
{
	int num = 0; // 记录加入拓扑序列的个数，在外层更新
	queue<int> q;
	for(int i = 0; i < n; i++)
	{
		if(inDegree[i] == 0)
		{
			q.push(i); // 将所有入度为0的顶点入队
		}
	}
	while(!q.empty()) // 队列非空
	{
		int u = q.front();// 取队首顶点
		// printf("%d ", u); // 此处可以输出顶点u，作为拓扑序列中的顶点，先取的就先解脱
		q.pop(); // 弹出

		// 这个循环目的是为了更新取出这个顶点后造成的影响
		for(int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i]; // 取出从u出发的边的另一个端点
			inDegree[v]--;
			if(inDegree[v] == 0)
			{
				q.push(v); //因为上面更新v的入度了，所以这里判断是否需要入队
			}
		}
		G[u].clear(); // 清空顶点u的所有出边，并非非常必要，因为入度表已经更新
		num++;
	}

	if(num == n) return true; // 拓扑排序成功
	else return false; // 表示拓扑排序失败
}