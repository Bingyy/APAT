//2017-2-23 20:25
// 统计类似于APAPAT中PAT的个数

#include <stdio.h>
#include <string.h>
const int MAXN = 100010;
const int MOD = 1000000007;

int leftNumP[MAXN] = {0}; // 统计每一位左边（含当前位）P的个数
char str[MAXN];
int main()
{
	gets(str); //读取字符串
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		// 两个if语句均执行判断，这种累加作用的写法还是第一次见到
		if(i > 0)
		{
			leftNumP[i] = leftNumP[i - 1]; // 继承前面的数据，这样其实就是累加作用
		}
		if(str[i] == 'P')
		{
			leftNumP[i]++;
		}
	}

	int ans = 0, rightNumT = 0;
	for(int j = len - 1; j >= 0; j--)
	{
		if(str[j] == 'T')
		{
			rightNumT++; // 遇到T则累加
		}
		else if(str[j] == 'A')
		{
			// 遇到字符是A时，开始计算
			ans = (ans + leftNumP[j] * rightNumT) % MOD; // leftNumP[j]是当前位以前的P的个数
		}
	}

	printf("%d\n", ans);
	return 0;
}
