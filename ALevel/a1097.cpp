#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 100005;
const int TABLE = 1000010;

struct Node
{
	int address, data, next;
	int order; // 数据信息
} nodes[maxn];

bool isExist[TABLE] = {false}; // 绝对值是否已经出现

bool cmp(Node a, Node b)
{
	return a.order < b.order;// 按照order递增排序
}

int main()
{
	memset(isExist,false,sizeof(isExist));
	for(int i = 0; i < maxn; i++)
	{
		nodes[i].order = 2 * maxn;// 初始化时均为无效结点，移出的放在从maxn开始编号
	}

	int n, begin, address;
	scanf("%d%d", &begin, &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d",&nodes[address].data, &nodes[address].next);
		nodes[address].address = address;
	}

	// 以上全是标准的模板
	int countValid = 0, countRemoved = 0, p = begin;
	while(p != -1)
	{
		if(!isExist[abs(nodes[p].data)])
		{
			// data的绝对值不存在
			isExist[abs(nodes[p].data)] = true; // 标记为已存在
			nodes[p].order = countValid++;
		}
		else
		{
			nodes[p].order = maxn + countRemoved++; // 被删除，编号从maxn开始算起
		}
		p = nodes[p].next;
	}
	sort(nodes, nodes + maxn, cmp);
	//输出结果
	int count = countValid + countRemoved;
	for(int i = 0; i < count; i++)
	{
		if(i != countValid - 1 && i != count - 1)
		{
			printf("%05d %d %05d\n",nodes[i].address, nodes[i].data, nodes[i + 1].address );
		}
		else
		{
			printf("%05d %d -1\n",nodes[i].address, nodes[i].data);
		}
	}
}


