#include <stdio.h>
#include <string.h>

int hash[62] = {0};
int miss = 0; 

int change(char c) // 转换到hash中的下标范围：0~61
{
	if(c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if(c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 10;
	}
	else if(c >= 'a' && c <= 'z')
	{
		return c - 'a' + 36;
	}
}

int main(int argc, char const *argv[])
{
	char str1[1010];
	char str2[1010];

	gets(str1);
	gets(str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for(int i = 0; i < len1; i++) // 读取第一个字符串中的字符，如果遇到则相应的加1
	{
		hash[change(str1[i])]++;
	}

	for(int j = 0; j < len2; j++)
	{
		 int id = change(str2[j]); // 计算在hash中的下标
		 hash[id]--; // 出现了则颜色个数减1
		 if(hash[id] < 0) // 计算缺失个数
		 {
		 	miss++;
		 }
	}

	if(miss > 0)
	{
		printf("No %d\n", miss);
	}

	else 
	{
		printf("Yes %d\n", len1 - len2);
	}

	return 0;
}