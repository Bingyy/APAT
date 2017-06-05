#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 110;

// 树的静态写法：这里不用谢data域，因为在nodes数组中下标即结点编号
struct node
{
	int left, right; // 左右孩子结点的下标
} nodes[maxn];

bool notRoot[maxn] = {false} ;// 标记非根结点，初始全部是根节点

int n, num = 0; // n是结点个数，num是当前输出结点个数，用于控制最后的空格

void print(int id)
{
	printf("%d",id);
	num++;
	if(num < n)
	{
		printf(" ");
	}
	else
	{
		printf("\n");
	}
}

// 中序遍历
void inOrderTraverse(int root) // 从中序序列中根的下标开始
{
	if(root == -1)
	{
		return; // 如果是空的则直接返回
	}
	inOrderTraverse(nodes[root].left);
	print(root);
	inOrderTraverse(nodes[root].right);
}

// 层序遍历
void BFS(int root)
{
	queue<int> q;
	q.push(root); // 将下标入队
	while(!q.empty())// 队列非空
	{
		int front = q.front(); // 取出队首
		q.pop();
		print(front);
		if(nodes[front].left != -1)
		{
			q.push(nodes[front].left);
		}
		if(nodes[front].right != -1)
		{
			q.push(nodes[front].right);
		} 
	}
}

// 后序遍历，反转二叉树
void postOrderTraverse(int root)
{
	if(root == -1)
	{
		return;
	}
	postOrderTraverse(nodes[root].left);
	postOrderTraverse(nodes[root].right);
	swap(nodes[root].left,nodes[root].right); // 交换左右孩子结点	
}

int strToNum(char c)
{
	if(c == '-') return -1;
	else
	{
		notRoot[c - '0'] = true;
		return c - '0'; // 返回及诶单编号
	}
}

// 寻找根结点编号
int findRoot()
{
	for(int i = 0; i < n; i++)
	{
		if(notRoot[i] == false)
		{
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	char left, right;
	scanf("%d", &n); //输入结点个数
	for(int i = 0; i < n; i++)
	{
		getchar();// 接收掉换行符
		scanf("%c %c",&left, &right);
		nodes[i].left = strToNum(left);
		nodes[i].right = strToNum(right);
	}
	int root = findRoot();

	postOrderTraverse(root); // 反转二叉树
	BFS(root); // 层序遍历

	num = 0;//  层序遍历后将num重置为0

	inOrderTraverse(root);
	return 0;
}