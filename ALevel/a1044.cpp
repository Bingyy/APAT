#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,S, nearS = 100000010;
int sum[N]; // 处理数据计算得到一个严格递增数列，由此用二分法解决问题

int main()
{
	scanf("%d%d",&n,&S);
	sum[0] = 0;
	for(int i = 1; i <=n; i++)
	{
		scanf("%d",&sum[i]);
		sum[i] += sum[i - 1];// 部分和
	}

	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(sum + i, sum + n + 1, sum[i - 1] + S) - sum; // 返回的不是int型的下标，而是指针，需要减掉数组首地址才能得到正确的下标
		if(sum[j - 1] - sum[i - 1] == S)
		{
			nearS = S; // 最接近S的值
			break;
		}
		else if(j <= n && sum[j] - sum[i - 1] < nearS)
		{
			nearS = sum[j] - sum[i - 1];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		int j = upper_bound(sum + i, sum + n + 1, sum[i - 1] + nearS) - sum;
		{
			if(sum[j - 1] - sum[i - 1] == nearS)
			{
				printf("%d-%d\n",i,j - 1);
			}
		}
	}
	return 0;
}