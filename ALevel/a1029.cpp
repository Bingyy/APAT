#include <stdio.h>

const int maxn = 1000010;
const int INF = 0x7fffffff;

int s1[maxn], s2[maxn];

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &s1[i]);
	}
	s1[n] = INF;

	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&s2[i]);
	}
	s2[m] = INF;

	int medianPos = (n + m - 1) / 2;
	int i = 0, j = 0, count = 0; // i, j跟踪两个数组中下标，count计数
	while(count < medianPos) // 当恰好为中位数的位置时停止循环
	{	
		if(s1[i] < s2[j])
		{
			i++; // 如果s1[i]更小则i++
		}
		else
		{
			j++;
		}
		count++; // 个数无论如何，一次循环一定自增
	}

	if(s1[i] < s2[j])
	{
		printf("%d\n",s1[i]);
	}
	else
	{
		printf("%d\n",s2[j]);
	}

	return 0;
}