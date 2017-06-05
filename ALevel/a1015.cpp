#include <stdio.h>
#include <cmath>

bool isPrime(int n) // 判断一个数是否是素数的方法这个算好记且挺快的
{
	if(n <= 1) return false; // 最小的素数是2
	int sqr = (int) sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) // 注意是小于等于
	{
		if(n % i == 0)
		{
			return false;
		}
	}

	return true;
}
int d[111];

int main(int argc, char const *argv[])
{
	int n, radix;
	while(scanf("%d", &n) != EOF)
	{
		if(n < 0) break;
		scanf("%d", &radix);
		if(isPrime(n) == false)
		{
			// 不是素数
			printf("No\n");
		}
		else
		{
			int len = 0;
			do
			{
				d[len++] = n % radix;
				n = n / radix; // 除留余数法：十进制数转为任意进制 
			} while(n != 0);

			for(int i = 0; i < len; i++) // 恰好从左到右就是逆序的
			{
				n = n * radix + d[i];
			}
			if(isPrime(n) == true)
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}