#include <stdio.h>

struct node
{
	int data;
	node* left = NULL;
	node* right = NULL;
};

int pre[5] = {1,2,4,5,3};
int in[5] = {4,2,5,1,3};

node* newNode(int val)
{
	node* Node = new node;
	Node->data = val;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

node* createFromPreInOrder(int preL, int preR, int inL, int inR)
{
	// 递归边界:先序序列已经为空了，这里通过下标判别
	if(preL > preR)
	{
		return NULL;
	}

	//处理当前层问题

	// 等同于node* root = newNode(pre[preL]);
	node* root = new node; 
	root->data = pre[preL];

	// 尤其注意这里的k，在for循环中，不要再 int k = preL, 否则会内存溢出
	int k;
	// 找到划分中序序列中的根结点
	for(k = inL; k <=inR; k++)
	{
		if(pre[preL] == in[k])
		{
			break;
		}
	}

	int numLeft = k - inL;
	// 递归处理
	root->left = createFromPreInOrder(preL+1, preL+numLeft,inL, k - 1);
	root->right = createFromPreInOrder(preL+numLeft+1, preR, k+1, inR);

	return root;
}

void preTraverse(node* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	preTraverse(root->left);
	preTraverse(root->right);
}

int main()
{
	// node* root = newNode(3);
	node* root = createFromPreInOrder(0,4,0,4);

	preTraverse(root);

	printf("\n");
	return 0;
}