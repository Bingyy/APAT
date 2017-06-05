#include <stdio.h>
#include <string.h>


// 因为字符串最长80,所以两轮循环复杂度也不会很高

int main(int argc, char const *argv[])
{
	char str1[100],str2[100];

	bool Hash[128] = {false};// 标记字符是否输出

	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for(int i = 0; i < len1; i++)
	{
		int j;
		char c1, c2;
		for(j = 0; j < len2;j++) // 枚举第二个字符串
		{
			c1 = str1[i];
			c2 = str2[j];
			if(c1 >= 'a' && c1 <= 'z') // 小写字符转化大写
			{
				c1 -= 32;
			}
			if(c2 >= 'a' && c2 <= 'z') 
			{
				c2 -= 32;
			}
			if(c1 == c2) // 如果第一个字符在第二个字符串中出现，跳出
			{
				break;
			}
		}
		if(j == len2 && Hash[c1] == false) // 第二个字符串中未出现且c1未被输出过
		{
			printf("%c", c1);
			Hash[c1] = true; // 字符会被当做数字存储，所以可以放心用作下标
		}
	}

	printf("\n");
	return 0;
}