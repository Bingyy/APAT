#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct bign // 大数类型
{
	int d[1000];
	int len;
	bign()
	{
		memset(d,0, sizeof(d));
		len = 0;
	}
};

bign change(char str[])
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0'; // 反向存储
	}

	return a;
}

bign add(bign a, bign b) // 大数加法
{
	bign c;
	int carry = 0; // 进位
	for(int i = 0; i < a.len || i < b.len; i++)
	{
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10; // 加法只会往上进位一次
	}

	if(carry != 0)
	{
		c.d[c.len++] = carry;
	}
	return c;
}
// 判断是否是回文数（回文序列）
bool judge(bign a)
{
	for(int i = 0; i <= a.len / 2; i++)
	{
		if(a.d[i] != a.d[a.len - 1 - i])
		{
			return false;
		}
	}
	return true;
}

void print(bign a)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main()
{
	char str[1000];
	int T, k = 0;
	scanf("%s %d", str, &T);
	bign a = change(str);
	while(k < T && judge(a) == false)
	{
		// k是次数上限，不超过次数上限且a并非回文序列时
		bign b = a;
		reverse(b.d,b.d + b.len); // 倒置
		a = add(a,b); // 大数相加
		k++; 
	}

	print(a);
	printf("%d\n", k);
	return 0;
}