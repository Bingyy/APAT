#include <stdio.h>
#include <vector>

using namespace std;

vector<int> ori,pre, preM, post, postM;

struct node
{
	int data;
	node* left;
	node* right;
};

node* newNode(int val)
{
	node* Node = new node;
	Node->left = NULL;
	Node->right = NULL;
	Node->data = val;
	return Node;
}
// 根据输入序列构造BST
void insert(node* &root, int x)
{
	// 递归边界
	if(!root) // 根为空，插入
	{
		root = newNode(x);
		return; //插入完就返回 
	}
	if(x < root->data)
	{
		insert(root->left,x);// 往左子树插入
	}
	else 
	{
		insert(root->right, x); // 往右子树插入
	}
}

node* createBST(vector<int> nums)
{
	node* root = NULL;
	for(int i = 0; i < nums.size(); i++)
	{
		insert(root, nums[i]); 
	}
	return root;
}

void preTraverse(node* root)
{
	if(!root) return;
	pre.push_back(root->data); // 将数据存储在先序遍历序列中
	preTraverse(root->left);
	preTraverse(root->right);
}

void preMTraverse(node* root)
{
	if(!root) return;
	preM.push_back(root->data);
	preMTraverse(root->right);
	preMTraverse(root->left);
}

void postTraverse(node* root)
{
	if(!root) return;
	postTraverse(root->left);
	postTraverse(root->right);
	post.push_back(root->data);
}

void postMTraverse(node* root)
{
	if(!root) return;
	postMTraverse(root->right);
	postMTraverse(root->left);
	postM.push_back(root->data);
}

int main()
{
	int n,temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		ori.push_back(temp);
	}

	node* root = createBST(ori);
	preTraverse(root);
	preMTraverse(root);
	postTraverse(root);
	postMTraverse(root);

	if(ori == pre)
	{
		printf("YES\n");
		for(int i = 0; i < n; i++)
		{
			printf("%d", post[i]);
			if(i < n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	else if(ori == preM)
	{
		printf("YES\n");
		for(int i = 0; i < n; i++)
		{
			printf("%d", postM[i]);
			if(i < n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}


	return 0;
}