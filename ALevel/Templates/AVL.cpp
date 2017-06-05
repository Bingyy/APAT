#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

// 之前少了一句更新结点高度，加上就好了
const int maxn = 100;
struct node
{
	int data,height;
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

	return Node; // 注意返回
}

//获取结点当前高度
int getHeight(node* root)
{
	// 注意判断空树时的情况
	if(root == NULL)
	{
		return 0;
	}
	return root->height;
}

// 获取结点root的平衡因子
int getBalanceFactor(node* root)
{
	return getHeight(root->left) - getHeight(root->right);
}

// 更新结点root的高度
void updateHeight(node* root)
{
	//只是更新root指向的地址的内容，所以不用引用传递
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

// AVL树的基本操作

// 1. 查找，基本与普通二叉树相同
void search(node* root, int x) // 查找到x输出
{
	if(root == NULL)
	{
		printf("Search failed\n");
		return;
	}
	if(x == root->data)
	{
		printf("%d\n", root->data);
	}
	else if(x < root->data) // 访问左子树
	{
		search(root->left, x);
	}
	else
	{
		search(root->right, x);
	}
}

// 2. 插入操作:需要特别考虑旋转,四种类型，都是左旋右旋的组合

// 左旋
void L(node* &root)
{
	node* temp = root->right; //左旋即root的右孩子想上位，右孩子上位需要出让自己的左孩子
	root->right = temp->left; // 根接收右孩子的左孩子
	temp->left = root; // 右孩子左孩子换为现在的根

	// 更新两个结点的高度
	updateHeight(root);
	updateHeight(temp);

	root = temp; //右孩子如愿成为根，修改了原来的root这个指针
}


void R(node* &root)
{
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;

	updateHeight(root);
	updateHeight(temp);
	//因为这句的存在，所以需要用引用传递
	root = temp;
}

void insert(node* &root, int x)
{
	if(root == NULL) // 递归边界处插入
	{
		root = newNode(x);
		return; // 注意return作为"递"的尽头
	}

	if(x < root->data)
	{
		insert(root->left, x);

		updateHeight(root);
		if(getBalanceFactor(root) == 2)
		{
			if(getBalanceFactor(root->left) == 1) // LL型
			{	
				R(root);
			} 
			else if(getBalanceFactor(root->left) == -1)
			{
				L(root->left);
				R(root);
			}
		} 
	}
	else
	{
		insert(root->right,x);
		updateHeight(root);// 缺少了这句更新所以导致出错
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

void levelTraverse(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* now = q.front();
		printf("%d ", now->data);

		q.pop();
		if(now->left != NULL)
		{
			q.push(now->left);
		}
		if(now->right != NULL)
		{
			q.push(now->right);
		}
	}
}
int main()
{
	// int data[maxn];

	// int n;
	// scanf("%d", &n);
	// for(int i = 0; i < n; i++)
	// {
	// 	scanf("%d",&data[i]);
	// }

	// node* root = createAVL(data,n);

	// preTraverse(root);
	// printf("\n");

	// inTraverse(root);
	// printf("\n");

	// levelTraverse(root);

	// printf("%d\n",root->data);
	// printf("\n");

	// node* root = NULL;
    // int n, v;
    // scanf("%d", &n);
    // for(int i = 0; i < n; i++) {
    //     scanf("%d", &v);
    //     insert(root, v);
    // }
    int data[4] = {1,2,3,4};
	node* root = createAVL(data,4);

	preTraverse(root);
    // printf("%d\n", root->v);
	return 0;
}