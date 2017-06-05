#include <stdio.h>
#include <vector>

using namespace std;

/*  
	题目意思就是根据输入的序列，判断是不是树的先序/镜像先序，后序/镜像后序序列
	如果是，则输出其后序
*/
vector<int> origin,pre,preM,post,postM;

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

void insert(node* &root, int x)
{
	if(root == NULL) // 递归边界，所以需要return，往回归
	{
		root = newNode(x);
		return;
	}
	// 允许重复时，这句可以删掉
	// if(x == root->data)
	// {
	// 	return;
	// }

	else if(x < root->data)
	{
		insert(root->left, x);
	}
	else
	{
		insert(root->right,x);
	}
}

node* createBST(vector<int> ins)
{
	node* root = NULL;
	for(int i = 0; i < ins.size(); i++)
	{
		insert(root,ins[i]);
	}

	return root;
}

void preOrder(node* root,vector<int> &vi) //要修改vi,所以用引用
{
	if(root == NULL) // 虽然是void返回类型，但是在递归中，需要设定返回边界
	{
		return; 
	}

	vi.push_back(root->data); //暂存而不访问
	preOrder(root->left, vi);
	preOrder(root->right, vi);
}

void preMOrder(node* root, vector<int> &vi)
{
	if(root == NULL)
	{
		return;
	}

	vi.push_back(root->data);
	preMOrder(root->right,vi);
	preMOrder(root->left, vi);
}

void postOrder(node* root, vector<int> &vi)
{
	if(root == NULL)
	{
		return;
	}
	postOrder(root->left, vi);
	postOrder(root->right, vi);
	vi.push_back(root->data);
}

void postMOrder(node* root,vector<int> &vi)
{
	if(root == NULL)
	{
		return;
	}
	postMOrder(root->right, vi);
	postMOrder(root->left, vi);
	vi.push_back(root->data);
}


int main(int argc, char const *argv[])
{
	int n,temp;
	scanf("%d", &n);
	
	// 处理输入的原始数据
  	for(int i = 0; i < n; i++)
  	{
  		scanf("%d", &temp);
  		origin.push_back(temp);
  	}

  	node* root = createBST(origin);

  	preOrder(root,pre);
  	preMOrder(root,preM);
  	postOrder(root, post);
  	postMOrder(root, postM);


  	if(origin == pre)
  	{
  		printf("YES\n");
  		for(int i = 0; i < post.size(); i++)
  		{
  			printf("%d", post[i]);
  			if(i < post.size() - 1)
  			{
  				printf(" "); // 控制最后不输出空格
  			}
  		}
  		printf("\n");
  	}

  	else if(origin == preM)
  	{
  		printf("YES\n");
  		for(int i = 0; i < postM.size(); i++)
  		{
  			printf("%d", postM[i]);
  			if(i < postM.size() - 1)
  			{
  				printf(" "); // 控制最后不输出空格
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