#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

// 简直神奇，完成了这样的DFS编写！
// 2017-2-27
const int maxn = 110;
struct node
{
	int weight;
	vector<int> child; // 定义一个邻接表形式的树形存储结构
} Node[maxn];

// 根的ID固定为00，因此这里还是用下标来表示结点,下标是0 ~ n - 1
vector<int> path;
// 参数有：结点编号，根到叶子上的路径之和, 给定的权重之和
void DFS(int index, int sum, int nodeNum,int s)
{
	// 进来先加入，路径加入的顺序就是从根到叶子结点
	path.push_back(index);

	if(sum > s)// 如果和已经大于s了则直接返回
	{
		return; 
	}
	if(sum == s && Node[index].child.size() != 0) // 如果等于s了但是还没到叶子结点，往回归
	{
		return;
	}
	if(Node[index].child.size() == 0 && sum == s) // 叶子结点且恰好路径之和是s
	{
		for(int i = 0; i < nodeNum; i++)
		{
			printf("%d",Node[path[i]].weight);
			if(i < nodeNum - 1)
			{
				printf(" ");
			}
			if(i == nodeNum - 1)
			{
				printf("\n");
			}	
		}
		return;
	}

	for(int i = 0; i < Node[index].child.size(); i++) // 递归访问子结点
	{
		DFS(Node[index].child[i], sum + Node[Node[index].child[i]].weight, nodeNum + 1,s);
		path.pop_back(); // 往回归时这里用的是vector，注意需要pop掉路径中不需要的结点
	}
}

bool cmp(int a, int b) // 用下标标识指针域时，不用结构体作为参数，因为Node数组，是大管家
{
	return Node[a].weight > Node[b].weight;
}

int main()
{
	int n, m,s; // n:结点总数，m：非叶子结点，s:给定的权重之和
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < n; i++)
	{
		//输入n个结点的权重
		scanf("%d",&Node[i].weight);
	}

	for(int i = 0; i < m; i++)
	{
		int parent,k;
		scanf("%d%d", &parent, &k);
		for(int j = 0; j < k; j++)
		{
			int child;
			scanf("%d", &child);
			Node[parent].child.push_back(child); // 将子结点编号存入树
		}
		sort(Node[parent].child.begin(), Node[parent].child.end(),cmp); // 这样处理，会优先遍历大的子结点

	}
	// 上面输入完毕，建树完毕
	DFS(0,Node[0].weight,1,s);

	return 0;
}