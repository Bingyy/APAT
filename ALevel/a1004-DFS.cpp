#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;
const int maxn = 110;

int hashTable[maxn] = {0}; //记录每层叶子结点个数

vector<int> Node[maxn]; // 存储图的结构

// 需要记录level的最大值
int maxLevel = 1;

void DFS(int index, int level) // 如果用DFS需要用到两个参数：结点编号，层号
{
	maxLevel = max(maxLevel, level); // 取最大的层数
	if(Node[index].size() == 0)
	{
		hashTable[level]++; // 只有当叶子结点时才统计才往该层加1
	}
	
	for(int j = 0; j < Node[index].size();j++) // 处理递归式，这也是个循环处理
	{
		DFS(Node[index][j],level + 1); // 孩子结点的编号，层数
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int parent,k; //父结点编号，每个结点有多少子结点
		int child;
		scanf("%d%d", &parent,&k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			Node[parent].push_back(child); //将子结点加入树中
		}
	}

	// 处理输入数据完毕

	DFS(1,1); // 题中固定root是从1开始编号
	printf("%d", hashTable[1]);
	for(int i = 2; i <= maxLevel; i++) // 注意下标从1开始编号
	{
		printf(" %d", hashTable[i]);
	}
	printf("\n");
	return 0;
}