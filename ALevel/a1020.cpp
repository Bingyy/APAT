#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

// 后序+中序遍历构造一棵树，输出层序遍历序列
vector<int> post;
vector<int> in;

struct node
{	
	int data;
	node* left = NULL;
	node* right = NULL;
};

node* newNode(int val)
{
	node* Node = new node;
	Node->data = val;
	return Node;
}

node* createFromPostInOrder(int postL, int postR, int inL, int inR)
{
	// 递归边界
	if(postL > postR)
	{
		return NULL;
	}

	// 处理当前层次的问题
	node* root = new node;
	root->data = post[postR];

	// k为中序序列中根的下标
	int k,numLeft;
	for(k = inL; k <= inR; k++)
	{
		if(in[k] == post[postR])
		{
			break;
		}
	}

	numLeft = k - inL;

	// 递归式
	
	root->left = createFromPostInOrder(postL,postL + numLeft - 1, inL,k - 1);
	root->right = createFromPostInOrder(postL + numLeft, postR - 1, k + 1, inR);

	return root;

}

int cnt = 0;

void levelTraverse(node* root)
{
	queue<node*> q; // 存储地址型
	q.push(root);
	while(!q.empty())
	{
		node* now = q.front();
		q.pop();
		cnt++;
		printf("%d", now->data);
		if(cnt < post.size())
		{
			printf(" ");
		}
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
	int num,temp;
	scanf("%d", &num);
	// 输入后序，中序序列
	for(int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		post.push_back(temp);
	}

	for(int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		in.push_back(temp);
	}

	node* root = createFromPostInOrder(0,num - 1,0,num - 1);

	levelTraverse(root);

	printf("\n");

	return 0;
}