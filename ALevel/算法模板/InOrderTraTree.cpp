// 树的中序遍历的非递归算法实现
#include <iostream>
#include <stack>
using namespace std;
#define MAXSIZE 1000

void InOrderTraversal(BiTree root)
{
	BiTree t = root;
	stack<int> s();
	while(t || !stack.isempty())
	{
		while(t) //一路向左并将沿途结点压入栈
		{
			s.push(t);
			t = t->left;
		}
		t = s.pop(); //弹出栈顶
		cout << t->data;
		t = t->right;
	}
}
int main()
{

	return 0;
}