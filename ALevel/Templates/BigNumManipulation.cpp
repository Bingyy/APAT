#include <stdio.h>
#include <string.h>

// 定义大整数用到的结构体

struct bign
{
	int d[1000];// 假设数据位数最大1000位
	int len; // 记录实际的数据位数
	bign()
	{
		// 默认构造函数中进行初始化
		memset(d,0,sizeof(d));
		len = 0; 
	}
};

bign change(char str[])
{
	bign res;
	// 将输入的字符数组逆序存储为实际数字位
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		res.d[i] = str[len - 1 - i] - '0'; // i + len - 1 - i = len - 1, 表示对称，用这种公式反推更顺畅
	}
	res.len = len; // 我更喜欢这种写法，虽然浪费了一个变量的空间，但是这样更舒服
	return res;
}

int compare(bign a, bign b)
{
	// 两个大整数的比较
	if(a.len > b.len) // 各位自带长度属性
	{
		return 1; // a大
	}
	else if(a.len < b.len)
	{
		return -1; // b大
	}
	else
	{
		// 一样长度时，比较每一位：从高往低比较,注意数组中前面存的是个位，所以从后往前枚举
		for(int i = a.len - 1; i >= 0; i--)
		{
			if(a.d[i] > b.d[i])
			{
				return 1;
			}
			else if(a.d[i] < b.d[i])
			{
				return -1; 
			}
		}
		return 0; // b大
	}
}

bign add(bign a, bign b)
{
	// 处理大数相加的逻辑：加法过程的模拟
	bign c;
	int carry; // 存储进位
	for(int i = 0; i < a.len || i < b.len; i++) // 用或连接，表示取较大者
	{
		int temp = a.d[i] + b.d[i] + carry; // 由于上面逆序存储，这里是从左到右恰好是个位在前
		c.d[c.len++] = temp % 10; // 结果的个位需要取余，这里的c.len++有值得思考的地方是：一方面标记d数组元素下标，，标完之后呢，自增表示数组元素的个数，巧妙！
		carry = temp / 10; //进位需要取整
	}

	if(carry != 0) // 最后进位不为0，直接付给结果的最高位，上面的for循环结束时
	{
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b)
{
	// 处理大数相减的逻辑：减法过程的模拟
	// 调用减法函数时，需要先比较两个数的大小（调用compare函数），如果a小，则先swap一下
	bign c;
	for(int i = 0; i < a.len || i < b.len; i++) // 用或连接，表示取较大者
	{
		if(a.d[i] < b.d[i]) // 不够减需要借位
		{
			a.d[i + 1]--;// 高一位自减去
			a.d[i] += 10; // 借来就变大为10
		}
		// 处理正常的减法
		c.d[c.len++] = a.d[i] - b.d[i];
	}

	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) // 去除高位的0，同时至少保留一位最低位
	{
		c.len--;
	}

	return c;
}

bign mul(bign a, int b)
{
	// 高精度乘法：大整数 * 一般的整数
	bign c;
	int carry = 0; // 进位
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	// 最后的进位可能一直不停往前进
	while(carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

bign div(bign a, int b, int &r)
{
	bign c;
	c.len = a.len;// 被除数的每一位和商的每一位一一对应，先令长度相等，与加减乘不同，这里要先定长度
	for(int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.d[i];
		if(r < b)	
		{
			// 不够除
			c.d[i] = 0;
		}
		else
		{
			c.d[i] = r / b;
			r = r % b;
		}
	}

	// 去除高位的0, 且至少保留一位
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
	{
		c.len--; // 不是清除数位，而是只取len长度的数字
	}
	return c;
}

void print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d",a.d[i]);
	}
}

int main()
{
	char an[1000], bn[1000];
	scanf("%s", an);
	bign a = change(an);
	// bign b = change(bn);

	int r = 0;
	print(div(a,7,r));
	printf("\n");
	return 0;
}