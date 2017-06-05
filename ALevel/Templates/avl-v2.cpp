#include <stdio.h>
#include <algorithm>

using namespace std;

struct node
{
	int data,height; // 记录结点的高度值
	node* left;
	node* right;
};

node* newNode(int val)
{
	node* Node = new node;
	Node->data = val;
	Node->left = NULL;
	Node->right = NULL;
	Node->height = 1;

	return Node;
}

int getHeight(node* root)
{ 
	if(root == NULL) // 递归边界
	{
		return 0;
	}
	return root->height;
}

void updateHeight(node* root) // 不是修改指针本身，而是修改指针指向内容
{
	root->height =  max(getHeight(root->left),getHeight(root->right)) + 1;// 递归式
}

int getBalanceFactor(node* root)
{
	return getHeight(root->left) - getHeight(root->right);
}


void R(node* &root) // 2,1右旋
{
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;

	updateHeight(root);
	updateHeight(temp);

	root = temp;
}

void L(node* &root)
{
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;

	updateHeight(root);
	updateHeight(temp);

	root = temp;
}

// 最难写的就是插入操作

void insert(node* &root, int x)
{
	if(root == NULL) // 递归边界：在边界时候插入
	{
		root = newNode(x);
		return; // 注意在递归边界返回
	}
	if(x < root->data)
	{
		insert(root->left,x); //往左子树插
		updateHeight(root); 
		if(getBalanceFactor(root) == 2)
		{
			if(getBalanceFactor(root->left) == 1) // LL型--R
			{
				R(root);
			}
			else if(getBalanceFactor(root->left) == -1)
			{
				L(root->left); // 先小旋转
				R(root); // 再大旋转
			}
		}
	}

	else
	{
		insert(root->right,x);
		updateHeight(root);
		if(getBalanceFactor(root) == -2)
		{
			if(getBalanceFactor(root->right) == -1)
			{
				L(root);
			}
			else if(getBalanceFactor(root->right) == 1)
			{
				R(root->right);
				L(root);
			}
		}
	}
}

node* createAVL(int data[], int n)
{
	node* root = NULL;
	for(int i = 0; i < n; i++)
	{
		insert(root,data[i]);
	}
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
	int data[4] = {1,2,3,4};
	node* root = createAVL(data,4);

	preTraverse(root);

	return 0;
}