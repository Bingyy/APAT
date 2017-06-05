#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int height; // 加一个域表示高度
};

node* newNode(int val)
{
	node* Node = new node;
	Node->left = NULL;
	Node->right = NULL;
	Node->data = val;
	return Node;
}


int getHeight(node* root) // 获取结点高度
{
	if(!root) return 0;
	return root->height;
}
void updateHeight(node* root) // 更新的是指针指向的内容，不是root本身
{
	if(!root) return;
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1; // 根据左右子树的高度更新
}

int getBalanceFactor(node* root)
{
	return getHeight(root->left) - getHeight(root->right);
}

void R(node* &root)
{
	node* temp = root->left;
	root->left = temp->right; //待上位的结点的右孩子给root左手拿着
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

void insert(node* &root, int x)
{
	if(!root)
	{
		root = newNode(x);
		return;
	}
	if(x < root->data)
	{
		insert(root->left,x);
		updateHeight(root);

		if(getBalanceFactor(root) == 2)
		{
			if(getBalanceFactor(root->left) == 1)
			{
				// LL型，右旋
				R(root);
			}
			else if(getBalanceFactor(root->left) == -1)
			{
				// LR型
				L(root->left); // 先小旋转
				R(root);
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
				// RR型，左旋
				L(root);
			}
			else if(getBalanceFactor(root->right) == 1)
			{
				// RL型
				R(root->right); // 先小旋转
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

void inTraverse(node* root)
{
	if(root == NULL)
	{
		return;
	}
	preTraverse(root->left);
	printf("%d ", root->data);
	preTraverse(root->right);
}

bool flag = true;
void isBalanced(node* root)
{
	if(!root) return; // 这是很重要的边界

	if(abs(getBalanceFactor(root)) > 1)
	{
		flag = false;
		return; // 只要有一个不满足就不满足
	}
	isBalanced(root->left);
	isBalanced(root->right);
}

int main()
{
	int data[9] = {1,2,3,4,5,6,7,8,9};
	node* root = createAVL(data,9);
	preTraverse(root);
	printf("\n");

	inTraverse(root);
	printf("\n");

	// int bf = getBalanceFactor(root);
	// 判断是否是平衡树
	isBalanced(root);
	if(flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;

}

