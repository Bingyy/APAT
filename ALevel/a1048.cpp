#include <stdio.h>

const int MAXN = 1005;

int HashTable[MAXN] = {0}; // 用于标记出现的硬币数量，如果是0表示未出现，每种币可以出现多个

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d%d",&n, &m);

	int coinValue;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&coinValue);
		HashTable[coinValue]++; //记录硬币个数
	}

	for(int i = 1; i < m; i++) // 最大需要支付的数值是m
	{
		if(HashTable[i] > 0) // 从小的数据开始枚举
		{
			HashTable[i]--; // 小的用到了就减1，反正不会再用了，所以可以这么做
			if(HashTable[m - i] > 0) // 如果恰好另外一个数有币可用，直接输出，并跳出函数
			{
				printf("%d %d\n", i, m - i);
				return 0;
			}
		}
	}
	printf("No Solution\n"); // 没有找到才流到这里
	return 0;
}