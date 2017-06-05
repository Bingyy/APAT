#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 110;

// 使用BFS时，level需要记录在结点自己的信息中，而DFSlevel可以因为每深入一层自增
// 这个代码自己实现完，表示自己对BFS的运用才真的有了自己的理解
struct node
{
	int level; // 存储结点的层号
	vector<int> children; // 存储子结点的编号
} Node[maxn];

int hashTable[maxn] = {0};// 记录每一层的结点数

// BFS的目的也是为了计算hashTable
void BFS(int root) 
{
	queue<int> q; // 存储结点编号
	q.push(root);
	while(!q.empty()) //队列非空时
	{
		int topIndex = q.front(); //取出队首
		//取出队首队首时该层顶点数加1
		hashTable[Node[topIndex].level]++; // level的信息结点自带
		q.pop();
		// 在二叉树中，这里只用判断左右子树非空即可，这里的判断是根据子结点的编号是否为空
		for(int i = 0; i < Node[topIndex].children.size(); i++)
		{
			q.push(Node[topIndex].children[i]); //将子结点编号加入
			// 注意这句的写法：想了很久才想通把level的赋值写在这里
			Node[Node[topIndex].children[i]].level = Node[topIndex].level + 1;
		}
	}
}

int main()
{
	int n,m, parent, k, child;
	scanf("%d%d",&n, &m); // n是结点总数，m是有孩子结点的结点总数
	for(int i = 0; i < m; i++) // 控制循环次数
	{
		scanf("%d%d", &parent, &k); // k是下标为parent的结点的子结点数
		for(int j = 0; j < k; j++) // 控制循环次数
		{
			scanf("%d", &child);
			Node[parent].children.push_back(child); // 建树
		}
	}

	Node[1].level = 1; //为根结点level赋初值值
	
	BFS(1); // 根结点编号为1

	// 只用找到最大的值，所以不用排序
	int maxLevel = -1, maxValue = 0;
	for(int i = 1; i < maxn; i++) // 层数从1开始计算
	{
		if(hashTable[i] > maxValue)
		{
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}

	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}
