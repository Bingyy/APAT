#include <stdio.h>

// 进制转换：存储digits
// 判断是否为回文数列
int digits[40],cnt = 0;

void convertToBaseB(int n,int base)
{
	do
	{
		digits[cnt++] = n % base;
		n /= base;
	}while(n != 0);
}

bool isPalindromic(int digits[], int cnt) // 判断是否为回文数
{
	for(int i = 0; i < cnt / 2; i++)
	{
		if(digits[i] != digits[cnt - 1 - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n, base;
	scanf("%d%d",&n,&base);

	convertToBaseB(n,base);

	bool flag = isPalindromic(digits,cnt);
	
	if(flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	for(int i = cnt - 1; i >=0; i--)
	{
		printf("%d",digits[i]);
		if(i != 0 )
		{
			printf(" ");
		}
	}
	// printf("\n");
	return 0;
}