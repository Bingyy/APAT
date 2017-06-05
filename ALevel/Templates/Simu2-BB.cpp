#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int maxv = 1010;
vector<int> G[maxv]; //邻接表的存储
int inDegree[maxv] = {0}; //记录顶点入度
vector<int> topSeq; //记录拓扑序列
int n, m;

int TopologicalSort()
{	
	int num = 0;
	priority_queue<int,vector<int>, greater<int> > q;

	for(int i = 0; i < n; i++)
	{
		if(inDegree[i] == 0)
		{
			q.push(i); //将顶点编号加入队列，会自动把小的放在堆顶
		}
	}
	while(!q.empty())
	{
		int u = q.top();
		topSeq.push_back(u);
		q.pop();
		for(int i = 0; i < G[u].size(); i++)
		{
			// i只是控制循环次数
			int v = G[u][i];
			inDegree[v]--; // 入度减1
			if(inDegree[v] == 0)
			{
				q.push(v);
			}
		}
		G[u].clear();
		num++; // 加入拓扑序列的个数
	}
	return num;
}

int main()
{
	scanf("%d%d", &n, &m);
	int u,v;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		inDegree[v]++; // 计算入度
	}

	int num = TopologicalSort();
	if(n == num)
	{
		printf("YES\n");
		for(int i = 0; i < topSeq.size(); i++)
		{
			printf("%d", topSeq[i]);
			if(i < topSeq.size() - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
		printf("%d\n", n - num);
	}
	return 0;
}