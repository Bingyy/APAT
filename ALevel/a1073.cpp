#include <stdio.h>
#include <cstring>

// 初步思路是：找到E的位置pos，以及小数点的位置dotPos,pos以后的数据是指数
// 小数点位置作为移动多少的基准

// 本题值得深究，则此类问题可通

char str[10010]; // 数据不超过9999比特

int main()
{
	gets(str); //输入数据
	int len = strlen(str);
	int pos = 0; //记录'E'的位置

	if(str[0] == '-') printf("-"); //先控制正负号输出

	while(str[pos] != 'E') // 当pos指向'E'时结束
	{
		pos++;
	}

	int exp = 0;//计算指数大小,即10^exp
	for(int i = pos + 2; i < len; i++)
	{
		exp = 10 * exp +  str[i] - '0';
	}

	if(exp == 0)
	{
		for(int i = 1; i < pos; i++)
		{
			printf("%c",str[i]); //在E前面的全部输出
		}
	}

	if(str[pos + 1] == '-') //指数为负数时控制输出
	{
		printf("0.");
		for(int i = 0; i < exp - 1; i++)//输出exp-1个0
		{	
			printf("0");
		}
		printf("%c",str[1]); //输出整数部分，科学计数法整数部分就1位
		for(int i = 3; i < pos; i++)//小数点后一位的数字是从下标3开始计数
		{
			printf("%c",str[i]);
		}
	}
	else  //指数部分为正：补0还是控制小数点移位， pos - 3是往右移动小数点位数可以使得数为不含小数点的数
	{
		for(int i = 1; i < pos; i++)
		{
			if(str[i] == '.') continue; //小数点略过去即可，用下标控制输出的小数点位置
			printf("%c",str[i]);
			if(i == exp + 2 && pos - 3 != exp) //如果exp恰好等于E前面的数字位数则不输出小数点
			{
				printf(".");
			}
		}

		for(int i = 0; i < exp - (pos - 3);i++) //pos - 3是小数点和E之间的数据数
		{
			printf("0");
		}
	}

	printf("\n");
	return 0;
}