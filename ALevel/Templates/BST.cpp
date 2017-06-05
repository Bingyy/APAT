#include <stdio.h>

// 查找结点
// 插入结点
// 建造二叉树
// 删除结点

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

// 查询并返回的写法
node* search(node* root,int x)
{
	if(root == NULL) 
	{
		printf("Not found!\n");
		return NULL; //查找失败
	}

	if(root->data == x)
	{
		return root;
	}
	else if(root->data > x)
	{
		search(root->left, x);
	}
	else
	{
		search(root->right, x);
	}
}

// 插入数据：需要对指针变量进行引用，直接修改

void insert(node* &root, int x)
{
	if(root == NULL) // 查找失败处即插入处
	{
		root = newNode(x);
		return; // 递归边界
	}

	if(x == root->data) return; //已存在数据，返回

	else if(x < root->data) // 往左子树插入
	{
		insert(root->left, x);
	}
	else
	{
		insert(root->right,x);
	}
}

node* createBST(int data[], int n)
{
	node* root = NULL;
	for(int i = 0; i < n; i++)
	{
		insert(root,data[i]);
	}
	return root;
}

// 返回左子树的最大结点：前驱
node* findMax(node* root)
{
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root;
}

//返回右子树的最小结点：后继
node* findMin(node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
// 删除数据

void deleteNode(node* &root, int x)
{
	// **两层递归
	if(root == NULL)
	{
		return;
	}
	// 找到了待删除的结点
	if(root->data == x)
	{
		// 叶子结点
		if(root->left == NULL && root->right == NULL)
		{
			root = NULL;
		}
		// 存在左子树
		else if(root->left != NULL)
		{
			node* pre = findMax(root->left); //寻找前驱
			root->data = pre->data; // 用前驱覆盖此待删除数据
			deleteNode(root->left, pre->data); //在左子树中删除
		} 
		else
		{
			node* next = findMin(root->right);
			root->data = next->data;
			deleteNode(root->right, next->data);
		}
	} 
	else if(root->data > x)
	{
		deleteNode(root->left,x);
	}
	else
	{
		deleteNode(root->right,x);
	}
	// 存在右子树
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
	int data[5] = {3,1,2,4,5};

	node* root = createBST(data, 5);
	preTraverse(root);
	printf("\n");

	deleteNode(root,3);
	preTraverse(root);
	printf("\n");

	insert(root,6);
	preTraverse(root);
	printf("\n");
	return 0;
}