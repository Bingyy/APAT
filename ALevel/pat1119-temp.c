#include <cstdio>
#include <vector>
using namespace std;

int *pre, *post;

struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

//新建结点函数
node *newNode(int data)
{
	struct node* nd = (struct node*)malloc(sizeof(struct node));
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

int mapIndex[256];

void mapToIndices(int inorder[], int n)
{
	for(int i = 0; i < n; i++)
	{
		mapIndex[inorder[i]] = i;
	}
}

node* buildInOrderPreorder(int pre[], int n, int offset)
{
	// pre : 数组，虽然pre表示的地址也是第一个元素，但是和offset类型不同
	// n: 数组元素个数
	// offset：标记的是在中序遍历树中的树的起始
	if(n == 0)
	{
		return NULL;
	}
	int rootVal = pre[0];
	int i = mapIndex[rootVal] - offset; // 左子树的个数
	node* root = newNode(rootVal); //新建一个结点：根是确定的

	root->left = buildInOrderPreorder(pre+1,i, offset);
	root->right = buildInOrderPreorder(pre+i+1,n-i-1,offset+i+1)
}

node* buildInOrderPostOrder(int post[], int n,int offset) //特别注意offset是用在中序遍历序列中的左右子树划分
{
	if(n == 0)
	{
		return NULL;
	}

	int rootVal = post[n-1];
	int i = mapIndex[rootVal] - offset;

	node* root = newNode(rootVal);

	root->left = buildInOrderPostOrder(post,i, offset);
	root->right = buildInOrderPostOrder(post+i,n-i-1, offset+i+1);
}

