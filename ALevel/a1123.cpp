#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
	int data, height;
	node* left;
	node* right;
};

node* newNode(int val)
{
	node* nd = new node;
	nd->height = 1;
	nd->data = val;
	nd->left = nd->right = NULL;

	return nd;
}

int getHeight(node* root)
{
	if(root == NULL)
	{
		return 0;
	}

	return root->height;
}

int getBalanceFactor(node* root)	
{
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node* root)
{
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

// LL型
void R(node* &root)
{
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);

	root = temp;
}

// RR型
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
	if(root == NULL) //递归边界插入
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

bool isComplete = true,after = false;

void levelTraverse(node* root,int n)
{
	int cnt = 1;
	queue<node*> q;
	q.push(root);
	
	while(!q.empty())
	{
		node* now = q.front();
		if(cnt < n)
		{
			printf("%d ", now->data);
		}
		if(cnt == n)
		{
			printf("%d", now->data);
		}
		q.pop();

		cnt++;

		if(now->left != NULL)
		{
			if(after) // 结点
			{
				isComplete = false;
			}
			q.push(now->left);
		} 
		else
		{
			after = true;
		}

		if(now->right != NULL)
		{
			if(after)
			{
				isComplete = false;
			}
			q.push(now->right);
		}	else
		{
			after = true;
		}
	}
}
int main()
{	
	node* root = NULL;
    int n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v);
        insert(root, v);
    }
    levelTraverse(root,n);
    printf("\n");
    if(isComplete)
    {

    	printf("YES\n");
    }
    else
    {
    	printf("NO\n");
    }
    return 0;
}