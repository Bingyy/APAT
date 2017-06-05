#include <stdio.h>
#include <string.h>

struct bign
{
	int d[21];
	int len; // 整数长度
	bign() // 重写默认构造函数：初始化
	{
		memset(d,0,sizeof(d));
		len  = 0; 
	}
};
// 返回值类型是bign
bign change(char str[])
{
	// 将大整数转化为bign型
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0'; // 个位存在数组前面
	}
	return a;
}

// 这种大整数乘以一个正常整数的可以用作模板，也可以用作大整数*大整数的模板

bign mul(bign a, int b) 
{
	// 高精度乘法写法
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10; // 个位走位该位结果
		carry = temp / 10;
	}
	while(carry != 0) // 可能连续进位，因此用while循环处理
	{
		c.d[c.len++] = carry % 10;
		carry = carry / 10;
	}

	return c;
}


int hashTableOri[10] = {0}; // 标记这些全都没有出现
int hashTableRes[10] = {0};


int main(int argc, char const *argv[])
{
	char str[21];
	gets(str);

	int len = strlen(str);

	for(int i = 0; i < len; i++)
	{
		hashTableOri[str[i] - '0']++;
	}

	// 计算double以后的值
	bign a = change(str); //转化为bign型
	bign m = mul(a,2); // 计算double值

	for(int i = 0; i < m.len; i++)
	{
		hashTableRes[m.d[i]]++;
	}

	bool flag = true;
	for(int i = 0;i < 10; i++)
	{
		if(hashTableOri[i] != hashTableRes[i])
		{
			flag = false;
		}
	}

	if(flag)
	{
		printf("Yes\n");
	} else
	{
		printf("No\n");
	}

	for(int i = m.len - 1; i >= 0; i--)
	{
		printf("%d", m.d[i]);
	}
	printf("\n");
	return 0;
}