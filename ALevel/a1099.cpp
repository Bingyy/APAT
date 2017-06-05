#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 110;

// 给定输入总数n，结点编号是：0~n-1
struct node
{
	int data;
	int left, right;
} Node[maxn];

int n, nums[maxn], id = 0;

// 通过中序遍历将数据填入二叉树结点
// 这是很重要的思路

void inOrder(int root)
{
	if(root == -1) return; // 递归边界
	inOrder(Node[root].left); // 递归遍历左子树
	Node[root].data = nums[id++]; // 将当前结点值填充进来
	inOrder(Node[root].right); // 递归遍历右子树

}

void BFS(int root)
{
	queue<int> q;
	q.push(root);
	int num = 0;
	while(!q.empty())
	{
		int top = q.front();
		q.pop();
		printf("%d", Node[top].data);
		num++;
		if(num < n)
		{
			printf(" ");
		}
		if(Node[top].left != -1)
		{
			q.push(Node[top].left);
		}
		if(Node[top].right != -1)
		{
			q.push(Node[top].right);
		}
	}
}
int main()
{
	scanf("%d", &n);
	// 建树，打架构，后面根据这个架构填充数据即可
	for(int i = 0; i < n; i++) 
	{
		// 这个i是结点编号
		scanf("%d%d", &Node[i].left, &Node[i].right);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&nums[i]); // 输入n个不同的数字
	}
	sort(nums, nums + n);
	inOrder(0); // 从根开始中序遍历
	BFS(0); // 层序遍历输出
	printf("\n");
	return 0;
}