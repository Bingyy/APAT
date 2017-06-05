#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int n,number[maxn],CBT[maxn]; // number存放结点权值，CBT存放完全二叉树

int id = 0;

void inOrder(int root)
{
	// 中序遍历BST得到的是递增的数列，那么运用这个性质：
	// 中序遍历时将数据填充进来即可
	if(root > n) return; // 递归边界：root大于编号n时，表示已经遍历完
	// 递归问题仍然是关注顶层设计
	inOrder(root * 2);
	CBT[root] = number[id++];
	inOrder(root * 2 + 1);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
	}
	// 将数组排序
	sort(number, number + n);
	inOrder(1); // 中序遍历时将数据填充
	for(int i = 1; i <= n; i++)
	{
		printf("%d", CBT[i]);
		if(i < n)
		{
			printf(" ");
		}
	}

	printf("\n");
	return 0;
}