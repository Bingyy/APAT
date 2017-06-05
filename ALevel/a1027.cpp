#include <stdio.h>

char radix[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};// 0 ~ 12

int digits[2],cnt;

void convertToBase13(int n) //返回一个0~12的数据
{
	cnt = 0;
	do
	{
		digits[cnt++] = n % 13;
		n = n / 13;
	} while(n != 0);
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);

	convertToBase13(a);
	printf("#%c%c", radix[digits[1]],radix[digits[0]]);

	convertToBase13(b);
	printf("%c%c", radix[digits[1]],radix[digits[0]]);

	convertToBase13(c);
	printf("%c%c\n", radix[digits[1]],radix[digits[0]]);

	return 0;
}