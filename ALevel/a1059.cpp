#include <stdio.h>
#include <cmath>

const int maxn = 100010;

struct factor 
{
	int x, cnt; // x是质因子，cnt是个数
} fac[10];

int prime[maxn], pNum = 0;

bool isPrime(int n)
{
	if(n <= 1) return false;
	int sqr = (int) sqrt(n);
	for(int i = 2; i <= sqr; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void Find_Prime()
{
	//  求出素数表
	for(int i = 1; i < maxn; i++)
	{
		if(isPrime(i) == true)
		{
			prime[pNum++] = i;
		}
	}
}

int main(int argc, char const *argv[])
{
	Find_Prime();// 构造素数表
	int n, num = 0;
	scanf("%d", &n);
	if(n == 1)
	{
		printf("1=1\n");
	}
	else
	{
		printf("%d=",n);
		int sqr = (int) sqrt(n);
		// 枚举sqr以内的质因子
		for(int i = 0; i < pNum && prime[i] <= sqr; i++)
		{
			if(n % prime[i] == 0)
			{
				fac[num].x = prime[i];// 记录该质因子
				fac[num].cnt = 0; // 次数为0是因为本次的会在while循环重新用一遍，也会更新数字n
				// 这个循环很有启发性：是实际操作的过程的真实模拟
				while(n % prime[i] == 0) // 加一层循环判断是否可以持续除这个质因子
				{
					fac[num].cnt++; // 更新出现的次数
					n /= prime[i]; // 更新n的值，以便下轮for循环使用已经除过因子的值
				}
				num++;	
			}
			if(n == 1) // 被sqr以内的因子除尽
			{
				break;
			}
		}

		if(n != 1) // 未被sqr以内的因子除尽，那么一定有一个大于sqr的质因子
		{
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		// 按照格式输出
		for(int i = 0; i < num; i++) // 存在fac表中的数据
		{
			if(i > 0) printf("*");
			printf("%d", fac[i].x);
			if(fac[i].cnt > 1)
			{
				printf("^%d", fac[i].cnt);
			}
		}
		printf("\n");
	}
	return 0;
}