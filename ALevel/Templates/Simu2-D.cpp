#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 40;

vector<int> layer;
int in[maxn];

int n; // 结点数

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

node* create(vector<int> vec,int inL, int inR)
{
	//递归边界
	if(vec.size() == 0) return NULL;

	node* root = newNode(vec[0]); //根结点

	int k;//中序根下标

	for(k = inL; k <= inR; k++)
	{
		if(vec[0] == in[k])
		{
			break;
		}
	}

	vector<int> leftLayer;
	vector<int> rightLayer;

	// 遍历层序序列划分出左右子树的层序遍历序列
	
	for(int i = 1; i < vec.size(); i++)
	{
		bool flag = false;
		for(int j = inL; j < k; j++)
		{
			if(vec[i] == in[j])
			{
				flag = true;
				break; //找到就跳出来
			}
		}
		if(flag) 
		{
			leftLayer.push_back(vec[i]);
		}
		else
		{
			rightLayer.push_back(vec[i]);
		}
	}

	root->left = create(leftLayer, inL, k - 1);
	root->right = create(rightLayer,k + 1, inR);

	return root;
}

int num = 0;
void preOrder(node* root)
{
	if(!root) return;
	printf("%d", root->data);
	num++;
	if(num < n) printf(" ");
	preOrder(root->left);
	preOrder(root->right);
}

int numPost = 0;
void postOrder(node* root)
{
	if(!root) return;
	postOrder(root->left);
	postOrder(root->right);

	printf("%d", root->data);
	numPost++;
	if(numPost < n) printf(" ");
}

// 从右往左看：计算层高即可
// 正确
int maxLevel = -1;
void dfs(node* root,int level) 
{
	if(!root) return; //如果为空直接返回即可
	if(level > maxLevel)
	{
		maxLevel = level;
	}
	dfs(root->left,level + 1);
	dfs(root->right,level + 1);
}


// 这几种遍历就站在每个结点上往左右想即可：问：往左会对宏观的数据有什么影响，往右呢？

// 从右上往左下看：极左、极右的最大值
int maxNum = -1;
void findLeftRightDFS(node* root,int num)
{
	if(!root) return;
	if(num > maxNum)
	{
		maxNum = num;
	}
	findLeftRightDFS(root->left,num);
	findLeftRightDFS(root->right,num + 1); //往右走加1
}
// 从上往下看：极左+极右+根的总数
int left = 0, right = 0;
void topDownDFS(node* root, int balance)
{
	if(!root) return;
	if(balance < left) left = balance;
	if(balance > right) right = balance;
	topDownDFS(root->left, balance - 1);
	topDownDFS(root->right, balance + 1);
}

int main()
{
	scanf("%d", &n);
	int temp;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&temp);
		layer.push_back(temp); 
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&in[i]);
	}
	node* root = create(layer, 1, n);


	preOrder(root);
	printf("\n");
	postOrder(root);
	printf("\n");

	dfs(root,1);
	findLeftRightDFS(root,1);
	topDownDFS(root,0);

	printf("%d\n",maxLevel);
	printf("%d\n",maxNum);
	printf("%d\n",right - left + 1);

	
	return 0;
}