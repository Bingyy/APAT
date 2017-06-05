#include <stdio.h>
#include <string.h>
#include <stack>
#include <vector>

using namespace std;

// 根据先序，中序建树，再根据后序输出

struct node
{
	int data; 
	node *left;
	node* right;
};
vector<int> pre;
vector<int> in; // 存储先序，中序遍历序列
stack<int> temp;// 临时存储

node* newNode(int val)
{
	// 建立一个新结点
	node* Node = new node;
	Node->left = NULL;
	Node->right = NULL;
	Node->data = val;

	return Node;
}

node* createFromPreInOrder(int preL, int preR, int inL, int inR)
{
	if(preL > preR)
	{
		return NULL; // 递归边界
	}
	// 处理当前层问题
	node* root = newNode(pre[preL]); // preL就是先序中根结点的下标

	int k; // 根结点在中序中的下标
	for(k = inL; k <= inR; k++)
	{
		if(in[k] == pre[preL])
		{
			break; // 找到了就退出，此时k即为根结点在中序序列中下标
		}
	}

	// 计算左子树的结点个数
	int leftNum = k - inL;
	// 递归建树
	root->left = createFromPreInOrder(preL + 1, preL + leftNum, inL, k - 1);
	root->right = createFromPreInOrder(preL + leftNum + 1, preR, k + 1, inR);

	return root;
}

int num = 0; //控制最后不输出空格
void postTraverse(node* root)
{
	if(root == NULL)
	{
		return; // 递归边界
	}
	postTraverse(root->left);
	postTraverse(root->right);
	printf("%d",root->data);
	num++;
	if(num < pre.size())
	{
		printf(" ");
	}
}

int main()
{
	// 主函数处理输入，构建pre, in数列
	int n; // 结点个数
	int data; 
	scanf("%d",&n);
	char str[5]; //用于存储push or pop
	for(int i = 0; i < 2 * n; i++)
	{
		scanf("%s", str); // 以空格、换行作为结束
		if(strcmp(str, "Push") == 0)
		{
			// 如果是Push,表示这是先序的
			scanf("%d", &data);
			pre.push_back(data);
			temp.push(data);
		}
		else if(strcmp(str,"Pop") == 0)
		{
			int top = temp.top();
			temp.pop(); // 栈删除数据
			in.push_back(top); 
		}
	}

	// 数据已经准备好，建树开始
	node* root = createFromPreInOrder(0,n - 1,0,n - 1);
	postTraverse(root);
	
	printf("\n");
	return 0;
}