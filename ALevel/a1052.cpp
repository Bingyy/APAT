#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 100005;

struct Node
{
	int address; // 标记本结点在结构体数组中的下标
	int data, next; // next是下一个结点在数组中的下标
	bool flag; // 结点是否在链表上
} nodes[maxn];

bool cmp(Node a, Node b)
{
	if(a.flag == false || b.flag == false)
	{
		return a.flag > b.flag; // 把无效结点放到后面去
	}
	else
	{
		return a.data < b.data;
	}
}

int main()
{
	for(int i = 0; i < maxn;i++)
	{
		nodes[i].flag = false;
	}

	int n, begin, address;

	scanf("%d%d", &n, &begin); // begin是起始结点的下标
	for(int i = 0; i < n; i++) // 只是控制循环n次
	{
		scanf("%d",&address);
		scanf("%d%d", &nodes[address].data, &nodes[address].next);
		nodes[address].address = address; //这句意思就是下标为address的结点的address是输入的address
	}

	int count = 0, p = begin;
	// 枚举链表，对flag进行标记，同时计数有效结点的个数
	while(p != -1) // 没到最后一个结点
	{
		nodes[p].flag = true;
		count++;
		p = nodes[p].next;
	}

	if(count == 0) printf("0 -1\n"); // 如果没有结点，输出0 -1
	else
	{
		sort(nodes, nodes + maxn, cmp);
		// 输出结果
		printf("%d %05d\n",count, nodes[0].address);
		for(int i = 0; i < count; i++)
		{
			if(i != count - 1)
			{
				printf("%05d %d %05d\n",nodes[i].address, nodes[i].data, nodes[i + 1].address );
			}
			else
			{
				printf("%05d %d -1\n",nodes[i].address, nodes[i].data );
			}
		}
	}
	return 0;
}