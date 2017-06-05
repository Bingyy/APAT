#include <stdio.h>
#include <cstring>

// 判断字符串相同的方法：直接遍历即可

int main()
{
	char week[7][5] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char str1[70],str2[70],str3[70],str4[70];

	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);

	int i; //写在外面的原因是为了取得第二对相同的字符，不用从头开始计数
	for(i = 0; i < len1 && i < len2; i++) // 同时游走
	{
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') //限定范围在A~G之间
		{
			printf("%s ",week[str1[i] - 'A']);
			break; //找到第一对就跳出循环
		}
	}
	i++;
	for(; i < len1 && i < len2; i++)
	{
		if(str1[i] == str2[i])
		{
			if(str1[i] >= '0' && str1[i] <= '9')
			{
				printf("%02d:",str1[i] - '0');
				break;
			}
			else if(str1[i] >= 'A' && str1[i] <= 'N')
			{
				printf("%02d:", str1[i] - 'A' + 10);
			}
		}
	}
	// 寻找str3和str4中第一个相同字符的位置
	for(i = 0;i < len3 && i < len4; i++)
	{
		if(str3[i] == str4[i])
		{
			if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))
			{
				printf("%02d",i);
				break;
			}
		}
	}

	printf("\n");

	return 0;
}