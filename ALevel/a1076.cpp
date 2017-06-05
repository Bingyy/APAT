#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1010;
bool inq[maxn] = {false}; //标记是否被访问，下标是结点编号
struct node
{
	int id; //结点编号
	int layer;
};

// 用vector数组存储邻接表
vector<node> Adj[maxn];

int BFS(int s, int L) //s：起始点，L：层数上限
{
	int numFoward = 0; // 转发数目
	queue<node> q;
	node start;
	start.id = s;
	start.layer = 0;
	q.push(start);

	inq[start.id] = true;

	while(!q.empty())
	{
		node topNode = q.front(); // 取出队首
		q.pop();
		int u = topNode.id;
		for(int i = 0; i < Adj[u].size(); i++)
		{
			node next = Adj[u][i]; // 从u出发能到达的结点next
			next.layer = topNode.layer + 1;
			if(inq[next.id] == false && next.layer <= L) // 第二个条件判定是转发层数不超过上限L
			{
				q.push(next);
				inq[next.id] = true;
				numFoward++; // 转发数加1
			}

		}
	}
	return numFoward; // 返回转发数
}

int main()
{
	node user;
	int n, L, numFollowing,idFollow;
	scanf("%d%d", &n, &L); // 输入结点个数，层数上限

	// id从1开始标号
	for(int i = 1; i <= n;i++)
	{
		user.id = i;
		scanf("%d", &numFollowing); // i用户关注的人数
		for(int j = 0; j < numFollowing; j++)
		{
			scanf("%d", &idFollow); // 输入用户i关注的用户编号
			Adj[idFollow].push_back(user); // 存储边idFollow--用户i
		}
	}

	int numQuery,s;
	scanf("%d", &numQuery);
	for(int i = 0; i < numQuery; i++)
	{
		memset(inq, false,sizeof(inq));
		// fill(inq, inq+maxn,false);
		scanf("%d",&s); //起始结点编号
		int numFoward = BFS(s,L); // 通过遍历走一遭，得到这个数据
		printf("%d\n",numFoward);
	}

	return 0;
}