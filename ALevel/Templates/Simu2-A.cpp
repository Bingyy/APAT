#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 310;

struct node
{
	char id[15];
	int a,b,c,d;
	int sum;
} Node[maxn];

bool cmp(node a, node b)
{
	if(a.sum != b.sum) return a.sum > b.sum;
	else 
	{
		return strcmp(a.id, b.id) < 0;
	}
}

int main()
{
	int a,b,c,d,l;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&l);

	int n;
	scanf("%d",&n);
	int sa,sb,sc,sd,k = 0;
	char id[15];
	for(int i = 0; i < n; i++)
	{
		scanf("%s%d%d%d%d", id,&sa, &sb, &sc, &sd);
		int sum = sa + sb + sc + sd;
		if(sa >= a && sb >= b && sc >= c && sd >= d && sum >= l)
		{
			strcpy(Node[k].id, id);
			Node[k++].sum = sum;
		}
	}

	sort(Node, Node + k, cmp); // 只排序在其中的

	printf("%d\n", k);

	for(int i = 0; i < k; i++) // 这样直接输出的前面k个不保证全部符合要求，所以输出还要控制，或者在求k的过程中取出这些数据
	{
		printf("%s %d\n", Node[i].id,Node[i].sum);
	}
	return 0;
}