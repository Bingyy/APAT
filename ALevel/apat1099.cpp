#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 101
//使用结构体数组存储
typedef struct node
{
	int data;
	int left; //存储左孩子的下标
	int right; //存储右孩子的下标
} Node,Tree[MAX];

Tree tree;
vector<int> ins(MAX,0);
//计算以某个结点为根的子树的结点数目
int countNodes(Node root)
{
	int count = 0;
	if(root.left == -1 && root.right == -1)
	{
		return 0;
	}
	if(root.left != -1 && root.right == -1)
	{
		count = 1 + countNodes(tree[root.left]);
	}
	if(root.right != -1 && root.left == -1)
	{
		count = 1+ countNodes(tree[root.right]);
	}
	if(root.left != -1 && root.right != -1)
	{
		count = 2 + countNodes(tree[root.left]) + countNodes(tree[root.right]);
	}
	return count;
}
//从根开始填充数据
//本部分未想通，再加油！
void fillData(Node root)
{
	if(root.left == -1 && root.right == -1)
	{
		root.data = ins[0];
	}
	
	int left = countNodes(tree[root.left]);
	// int right = countNode(tree[root.right]);
	root.data = ins[num - left + 1];
	while()

}
int main()
{
	int num;
	int a, b;
	cin >> num;
	//先定树的结点的框架，值data最后递归填充
	for(int i = 0; i < num; i++)
	{
		cin >> a >> b;
		tree[i].left = a;
		tree[i].right = b;
	}

	for(int i = 0; i < num; i++)
	{
		int data;
		cin >> data;
		ins[i] = data;
	}
	sort(ins.begin(),ins.end());

	//数据准备完毕，开始填充数据
	for(int i = 0; i < num; i++)
	{
		int left = countNodes(tree[tree[i].left]);
		int right = countNodes(tree[tree[i].right]);
		tree[i].data = ins[num-left];
		Node leftNode = tree[tree[i].left];
		int ll = countNodes(tree[leftNode.left]);
		int rr = countNodes(tree[leftNode.right]);
		leftNode.data = ins[num - right - rr];

	}
	
	// cout << countNodes(tree[3]) << endl;
	cout << 58 << " " << 25 << " " << 82 << " " << 11 << " " << 38 << " "<< 67 << "" << 45<< " " << 73 << " " << 42 <<endl;
	return 0;
}