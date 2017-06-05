#include <stdio.h>

int pre[5] = {1,2,4,5,3};
int in[5] = {4,2,5,1,3};

struct node
{
	int data;
	node* left;
	node* right;
};

node* newNode(int val)
{
	node* Node = new node;
	Node->data = val;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

node* createFromPreInOrder(int preL, int preR, int inL,int inR) // 分别是先序序列和中序序列下标
{
  	// 递归边界
  	if(preL > preR) // 
  	{
  		return NULL;
  	}
  	// 处理当前层问题
  	node* root = newNode(pre[preL]); // 新建结点

  	int k; //是中序中的切割下标
  	for(int k = inL; k < inR; k++)
  	{
  		if(pre[preL] == in[i])
  		{
  			break; //找到就跳出循环
  		}
  	}

  	int numLeft = k - inL; //左子树的数量

  	// 递归式
  	root->left = createFromPreInOrder(preL + 1, preL + numLeft,inL, k - 1);
  	root->right = createFromPreInOrder(preL + numLeft + 1, preR, k + 1,inR);
	return root;
}

int main()
{

	return 0;
}