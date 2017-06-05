#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

// 因子分解问题:不是质因子

int main(int argc, char const *argv[])
{
	ll n;
	scanf("%lld",&n);
	ll sqr = (ll)sqrt(n), ansI = 0, ansLen = 0;

	for(ll i = 2; i <= sqr; i++)
	{
		// 遍历连续的第一个整数
		ll temp = 1,j = i; // temp存储当前连续整数的乘积
		while(1)
		{
			temp *= j;
			if(n % temp != 0) break; // 不能整除n，跳出循环
			if(j - i + 1 > ansLen)
			{
				ansI = i; // 更新第一个整数
				ansLen = j - i + 1;
			}
			j++; // 下一个整数
		}
	}

	if(ansLen == 0)
	{
		printf("1\n%lld\n", n);
	}
	else
	{
		printf("%lld\n", ansLen);
		for(ll i = 0; i < ansLen; i++)
		{
			printf("%lld", ansI + i);
			if(i < ansLen - 1)
			{
				printf("*");
			}
		}
		printf("\n");
	}

	return 0;
}