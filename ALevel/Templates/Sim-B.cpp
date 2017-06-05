#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


// 这是AC的代码
// 判断两棵BST相等的方式是level,post序列都相同，但是个人认为这不是完全正确的做法


const int maxn = 40;

int seq1[maxn],seq2[maxn];

vector<int> post[2],level[2];
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

void insert(node* &root, int x)
{
	if(root == NULL) // 递归边界
	{
		root = newNode(x);
		return;
	}

	if(x < root->data)
	{
		insert(root->left, x);
	}
	else
	{
		insert(root->right, x);
	}
}

node* createBST(int data[],int n)
{
	node* root = NULL;
	for(int i = 0; i < n; i++)
	{
		insert(root,data[i]);
	}
	return root;
}

void postOrder(node* root,int id)
{
	if(!root) return;
	postOrder(root->left,id);
	postOrder(root->right,id);
	post[id].push_back(root->data);
}

void levelOrder(node* root,int id)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* top = q.front();
		level[id].push_back(top->data); // 数据先存储再说
		q.pop();
		if(top->left) q.push(top->left);
		if(top->right) q.push(top->right);
	}
}

bool flag = true; // 默认认为两棵树是相同的，递归判断过程中改变flag值，一旦有一个不同，就跳出
void judge(node* root1, node* root2)
{
	if(root1 == root2) return; // 这个相等其实是用来判断都为空的，那么不用改变flag
	if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
	{
		flag = false;
		return;
	}

	if(root1->data != root2->data)
	{
		flag = false;
		return;
	}

	judge(root1->left,root2->left);
	judge(root1->right, root2->right);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &seq1[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &seq2[i]);
	}

	node* root1 = createBST(seq1,n);

	node* root2 = createBST(seq2,n);


	postOrder(root1,0);
	levelOrder(root1,0);

	postOrder(root2,1);
	levelOrder(root2,1);


	// if(post[0] == post[1] && level[0] == level[1]) printf("YES\n");
	
	judge(root1, root2);

	if(flag)
	{
		printf("YES\n");
	}

	else printf("NO\n");


	for(int i = 0; i < post[0].size(); i++)
	{
		printf("%d", post[0][i]);
		if(i < post[0].size() - 1)
		{
			printf(" ");
		}
	}

	printf("\n");

	for(int i = 0; i < level[0].size(); i++)
	{
		printf("%d", level[0][i]);
		if(i < level[0].size() - 1)
		{
			printf(" ");
		}
	}

	printf("\n");
	return 0;
}