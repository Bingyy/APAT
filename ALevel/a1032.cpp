#include <stdio.h>
#include <string.h>

const int maxn = 100010;

// 需要复习静态链表的使用细节
// 有些题目需要强行使用静态链表


struct Node
{
	char data;
	int next;
	bool flag; // 结点是否在第一条链表中出现
} node[maxn];

int main()
{
	for(int i = 0; i < maxn; i++)
	{
		node[i].flag = false; // 全部初始化为未出现在第一条链表中
	}

	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);

	int address, next;
	char data;

	for(int i = 0; i < n; i++)
	{
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next; 
	}
	int p;
	for(p = s1; p != -1; p = node[p].next)
	{
		node[p].flag = true;
	}

	for(p = s2; p != -1; p = node[p].next)
	{
		if(node[p].flag == true) break; // 找到第一个已经在第一个链表中出现的结点
	}

	if(p != -1) // 如果在第二条链表中还没到达结尾，则说明找到了共同点
	{
		printf("%05d\n",p);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}