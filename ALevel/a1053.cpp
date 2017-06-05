#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 110;

struct node
{
	int weight;
	vector<int> child; // 指针域
} Node[maxn];

bool cmp(int a, int b) // 用下标标识指针域时，不用结构体作为参数，因为Node数组，是大管家
{
	return Node[a].weight > Node[b].weight;
}

int n, m, S; // 结点数，边数，给定的和

int path[maxn]; //记录路径

// 当前访问结点为index, numNode为当前路径path山上的结点个数

void DFS(int index, int numNode, int sum) // 当前层需要用到的数据
{
	if(sum > S) return; // 当前和大于S，返回  这是一种递归边界
	if(sum == S)
	{
		if(Node[index].child.size() != 0) return; // 还没到叶子结点

		// 否则就是达到叶子结点且恰好为给定值
		for(int i = 0; i < numNode; i++)
		{
			printf("%d", Node[path[i]].weight);
			if(i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return ;
	}

	for(int i = 0; i < Node[index].child.size(); i++)// 枚举所有子结点
	{
		int child = Node[index].child[i]; // 结点index的第i的子结点编号
		path[numNode] = child;//将结点child加到路径path末尾,这种数组是覆盖原有的数据
		DFS(child, numNode + 1, sum + Node[child].weight); //递归进入下一层
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &S);
	for(int i = 0; i < n;i++)
	{
		scanf("%d",&Node[i].weight);
	}

	int id, k, child;


	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&id, &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			Node[id].child.push_back(child);
		}
		sort(Node[id].child.begin(), Node[id].child.end(),cmp);
	}

	path[0] = 0;

	DFS(0,1,Node[0].weight);

	return 0;
}
