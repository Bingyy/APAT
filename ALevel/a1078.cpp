#include <stdio.h>
#include <cmath>
#include <vector>

const int N = 11111;
// hashing
using namespace std;

bool isPrime(int n) // 判断素数基本已经成为模板
{
	if(n <= 1)
	{
		return false;
	}
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
bool hashTable[N] = {0};// 0表示false,即表示未被占用

int main(int argc, char const *argv[])
{
	int n, TSize,a;
	scanf("%d%d", &TSize, &n);
	while(isPrime(TSize) == false) // 当TSize不是素数时
	{
		TSize++; //往上自增，直到为素数为止，一定会找到，且一般用时不会很长，相隔不远
	}

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		int M = a % TSize; // 根据公式计算哈希的位置
		if(hashTable[M] == false)
		{
			hashTable[M] = true; // 该位置还未被占用时，占用之
			if(i == 0) printf("%d",M); // 控制输出的格式：最后不要空格
			else printf(" %d",M);
		}
		else // 否则这里处理冲突:学习这里处理冲突的格式
		{
			int step; //  二次探测的步长
			for(step = 1; step < TSize; step++) // 为什么step小于TSize是界限可以证明
			{
				M = (a + step * step) % TSize; // 处理冲突的公式
				if(hashTable[M] == false)
				{
					hashTable[M] = true;
					if(i == 0) printf("%d", M);
					else printf(" %d", M);
					break;
				}
			}
			if(step >= TSize)
			{
				// 找不到插入的地方
				if(i > 0) printf(" ");
				printf("-");
			}
		}
	}
	printf("\n");
	return 0;
}