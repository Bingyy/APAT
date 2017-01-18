#include <iostream>
#include <vector>
using namespace std;
// 题目的意思就是输入一棵树，输入的方式是：告知结点总数N，非叶子结点数M。然后依次输入M行，输入的内容是
// 非叶子结点的编号，孩子个数，孩子的编号

// 解题思路：构造一个结构体数组，按照层序构造树的时候，根结点的level是1，根节点的孩子level是2，类推：
// level为n的孩子level是n+1
// 遍历数组相同level的结点，左右孩子为空的计数一次
typedef struct Node
{
	string index; // 自身结点的编号
	string left; //左孩子结点编号
	string right; // 右孩子结点编号
	int level; // 层序号
}Node;


int main()
{
	int n,m;
	cin  >> n >> m; 
	vector<Node> nodes;
	int level = 1;
	for(int i = 0; i < m; i++)// 非叶子结点
	{
		Node p;
		int k; //孩子数目
		cin >> p.index >> k;
		p.level = 1;
		if(k == 1)
		{
			Node c;
			cin >> c.index;
			p.left = c.index;
			c.level = p.level + 1;
		}
		if(k == 2)
		{
			Node lc,rc;
			cin >> lc.index >> rc.index;
			p.left = lc.index;
			p.right = rc.index;

			lc.level = p.level + 1;
			rc.level = p.level + 1;
		}
		int flag;
		for(int j = 0; j < nodes.size(); j++)
		{
			if(p.index == nodes[j].index)
			{
				flag = 1;
			}
		}
		if(!flag) //未出现过时才输入
		{
			nodes.push_back(p);
		}
	}

	for(int i = 0; i < leaves.size(); i++)
	{
		cout << leaves[i].index << " ";
	}
	cout << endl;
	return 0;
}