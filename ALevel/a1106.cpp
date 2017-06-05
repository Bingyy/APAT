#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

const int maxn = 100010;
const int INF = 1<<30;
// 这里不用存储任何其他的结点信息，值关注结点编号，深度，所以不用写结构体
vector<int> Node[maxn]; // 这种写法是邻接表的思路，因为这里是一般树

int minDepth = INF;

int num = 0; // 记录最小深度结点数

void DFS(int index, int depth) 
{
	// 递归边界：遍历过程中计算minDepth
	if(Node[index].size() == 0) // 叶子结点
	{
		if(depth < minDepth)
		{
			minDepth = depth;
			num = 1; //重置为1
		}
		else if(depth == minDepth)
		{
			num++;
		}
		return;
	}

	// 递归式
	for(int i = 0; i < Node[index].size(); i++)
	{
		DFS(Node[index][i],depth + 1); //孩子结点的深度比父结点少1
	}
}

// 仍然是用静态数组解题
int main()
{
	int n;// n是结点总数，编号是从0~n-1
	double p, r; // p：price, r:rate
	scanf("%d%lf%lf",&n, &p, &r);

	// 输入数据建树
	for(int i = 0; i < n; i++) // 这个循环i也是结点的编号
	{
		int k,child;
		scanf("%d", &k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &child);
			Node[i].push_back(child); // 将孩子结点编号存入Node[i]中
		}
	}
	DFS(0,0);
	// 数据输入完毕，建树完毕

	printf("%.4f %d\n",p * pow( (1 + r / 100),minDepth), num);

	return 0;
}