#include <stdio.h>
#include <cstring>

int main()
{
	char str[100],ans[40][40];
	gets(str);//输入字符串

	int N = strlen(str);
	int n1 = (N+2)/3,n3 = n1, n2 = N + 2 - n1 - n3;// 推导出来的公式
	for(int i = 1; i <= n1; i++) //二维数组以n1为行数，以n2为列数
	{
		for(int j = 1; j <= n2;j++)
		{
			ans[i][j] = ' ';
		}
	}

	int pos = 0;
	for(int i = 1; i <= n1; i++)
	{
		ans[i][1] = str[pos++]; // 先为第一列赋值
	}

	for(int j = 2; j <= n2; j++) // 挖去最左端
	{
		ans[n1][j] = str[pos++]; // 再为行赋值
	}

	for(int i = n3 - 1; i >= 1; i--)
	{
		ans[i][n2] = str[pos++]; // 从下往上为右侧赋值
	}

	for(int i = 1; i <= n1; i++)
	{
		for(int j = 1; j <= n2; j++)
		{
			printf("%c", ans[i][j]); // 输出整个二维数组
		}
		printf("\n");// 每一行输出一个换行符
	}

	
}
