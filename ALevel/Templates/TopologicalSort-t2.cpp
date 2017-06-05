#include <vector>
#include <queue>

using namespace std;
const int maxn = 1 << 30;
vector<int> G[maxn]; 

int n; //顶点数
int inDegree[maxn]; // 入度表

bool TopologicalSort()
{
	int num = 0; // 记录拓扑序列数
	for(int i = 0; i < n; i++)
	{
		if(inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	// 加入以后需要用while循环处理
	while(!q.empty())
	{
		// i是顶点的编号
		int u = q.top(); // 取出队首
		// 可以在此处输出or存储拓扑序列
		q.pop();

		for(int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			if(inDegree[v] == 0)
			{
				q.push(v);
			}
		}
		G[u].clear(); //清空从u出发的边
		num++;
	}
	if(num == n) return true;
	else return false;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}