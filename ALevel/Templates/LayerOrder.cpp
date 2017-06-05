
#include <cstdio>
#include <queue>

using namespace std;

struct node
{
	int data;
	int layer;
	node* left = NULL;
	node* right = NULL;
};

node* newNode(int val)
{
	node* Node = new node;
	Node->data = val;
	Node->left = Node->right = NULL; // 可以不用这一步了，因为在结构体定义中已经设为NULL了
	return Node; // 返回的是分配好的内存区域地址
};

void LayerOrder (node* root) // 传参是地址，这样才能真正访问此树
{
	queue<node*> q; // 存储的也是地址，如果存储的是node，则只是副本，不操作树的结点

	// 根入队
	// 队列非空时访问

	q.push(root);
	root->layer = 1; // 根的层次是1
	
	while(!q.empty())
	{
		node* now = q.front(); // 取出队首元素
		printf("%d\n", now->data);
		q.pop(); // 弹出队首
		if(now->left != NULL)
		{	
			now->left->layer = now->layer + 1;
			q.push(now->left); // 层序遍历不是递归写法，所以这里是用队列存储
		} 
		if(now->right != NULL)
		{
			now->right->layer = now->layer + 1;
			// LayerOrder(now->right);
			q.push(now->right); //
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}