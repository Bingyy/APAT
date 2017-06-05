#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

//逐个字符比较的应用
// 比较后缀，则是不等长字符串，不好比较，反转后则变为公共前缀
// 运用algorithm头文件下的reverse函数翻转字符串

// 运用二维字符串数组
char s[100][257];//最多100个字符串
//寻找公共前缀，要以最短的字符串长度为界限，否则会越界
int n,minLen = 257;
int ans = 0;

void rever(char *s) 
{
	int len = strlen(s);
	for(int i = 0; i < len / 2; i++)
	{
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}

int main()
{
	scanf("%d",&n);
	getchar(); //因为下面输入的是字符串，所以换行符需要接收掉（忽略掉）

	for(int i = 0; i < n;i++)
	{
		gets(s[i]); //输入字符串
		int len = strlen(s[i]);
		if(len < minLen)
		{
			minLen = len; //输入时候更新minLen
		}
		// reverse(s[i],s[i]+len); //左开右闭，翻转字符串
		rever(s[i]);
	}

	for(int i = 0; i < minLen; i++) //i是列下标
	{
		char c = s[0][i]; //取得第一个字符串的第i个字符
		bool same = true;
		for(int j = 1; j < n; j++) //n行字符串，如果某列全都相等，则可以得到一个
		{
			if(c != s[j][i]) //按照列优先比较
			{
				same = false; //如果有一个不相等就停止比较
				break;//跳出循环
			}
		}
		if(same) ans++; //如果相等，公共字符串长度++
		else break; //如果same为false，跳出外部大循环
	}

	if(ans)
	{
		for(int i = ans - 1; i >= 0; i--)
		{
			printf("%c",s[0][i]);//输出公共字符串，注意这里的前缀需要按照反向输出为后缀
		}
	}
	else
	{
		printf("nai");
	}

	printf("\n");
	return 0;
}