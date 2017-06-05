#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;

// 这道题我理解了大概的意思，但是具体编码自己动手还不一定编得来

// 这种是判断语句的嵌套需要仔细梳理
struct Node
{
	int address, data, next;
	int order; //结点在链表上的序号，无效结点序号是maxn
} node[maxn];

bool cmp(Node a, Node b)
{
	return a.order < b.order; //递增排序
}

int main(int argc, char const *argv[])
{
	for(int i = 0; i < maxn; i++)
	{
		node[i].order = maxn; // 初始化全部为无效结点
	}	

	int begin, n, K, address;
	scanf("%d%d%d", &begin, &n, &K); // 起始地址，结点个数，步长
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	int p = begin, count = 0; // count是有效结点的数目
	while(p != -1) // 遍历链表找到单链表的所有有效结点
	{
		node[p].order = count++;
		p = node[p].next;
	}
	sort(node,node + maxn, cmp);

	n = count;
	// 单链表已经形成

	for(int i = 0; i < n / K; i++) // 枚举完整的n / K 块
	{
		for(int j = (i + 1) * K - 1; j > i * K; j--)
		{
			printf("%05d %d %05d\n", node[j].address, node[j].data,node[j-1].address);
		}
		printf("%05d %d ",node[i * K].address,node[i * K].data );
		if(i < n / K - 1)
		{
			printf("%05d\n", node[(i + 2) * K - 1].address);
		}
		else
		{
			if(n % K == 0)
			{
				printf("-1\n");
			}
			else
			{
				printf("%05d\n",node[(i + 1) * K].address);
				for(int i = n / K * K; i < n; i++)
				{
					printf("%05d %d ",node[i].address, node[i].data);
					if(i < n - 1)
					{
						printf("%05d\n", node[i + 1].address);
					}
					else
					{
						printf("-1\n");
					}
				}
			}
		}

	}
	return 0;
}