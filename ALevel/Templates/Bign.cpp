#include <stdio.h>
#include <string.h>


// 考虑用桩子记忆法 ： loci

struct bign
{
	int d[100];
	int len;
	bign()
	{
		memset(d,0,sizeof(d));
		len = 0; 
	};
};

bign change(char str[]) // 将数据转化为逆序存储的数位
{
	bign res; // 转化结果
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		res.d[i] = str[len - i - 1] - '0'; //个位存在前面
	}
	res.len = len;
	return res;
}

int compare(bign a, bign b)
{
	if(a.len > b.len)
	{
		return 1; // a大
	}
	else if(a.len < b.len)
	{
		return -1; // b大
	}
	else // 长度相同，比较位数大小
	{
		for(int i = a.len - 1; i >= 0; i--)
		{
			if(a.d[i] > b.d[i])
			{
				return 1; // a大
			}
			else if(a.d[i] < b.d[i])
			{
				return -1;
			}
		}
		return 0;
	}
}
bign add(bign a, bign b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) // 注意这里用或连接，较短位者也可以访问，因为为0
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	// 如果进位还有直接加到最高位即可
	if(carry != 0)
	{
		c.d[c.len++] = carry;
	}
	return c;
}

bign sub(bign a, bign b)
{
	bign c; // 减法的劫夺
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		if(a.d[i] < b.d[i])
		{
			a.d[i + 1]--; // 高位借1
			a.d[i] += 10; // 
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	// 去除高位的0
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) // 注意这句当长度为2时还可以进入将长度变为1
	{
		c.len--;
	}
	return c;
}

bign mul(bign a, int b)
{
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry)
	{
		c.d[c.len++] = carry;
		carry /= 10;
	}
	return c;
}

bign div(bign a, int b, int &r)
{
	bign c;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.d[i];

		if(r < a.d[i])
		{
			c.d[c.len++] = 0;
		}
		else
		{
			c.d[c.len++] = r / 10;
			r = r % 10;
		}
	}
	// 去除高位的0
	while(c.len - 1 >= 1 && c.d[c.len--] >= 0)
	{
		c.len--;
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
	char str1[50],str2[50];
	scanf("%s%s",str1,str2);
	bign a = change(str1);
	bign b = change(str2);
	int r = 0;
	print(div(a,3,r));
	printf("\n");
	return 0;
}