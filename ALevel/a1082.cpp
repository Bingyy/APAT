#include <iostream>
#include <string.h>

char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"}; // wei[0] = Shi
int main()
{
	char str[15];
	gets(str);
	
	int len = strlen(str);
	int left = 0,right = len - 1;//分别指向首尾元素
	if(str[0] == '-')
	{
		printf("Fu");
		left++; // left右移
	}

	while(left + 4 <= right)
	{
		right -= 4; // 将right每次左移4位，直到left与right在同一节
	}

	while(left < right)
	{
		bool flag = false;
		bool isPrint = false;
		// while(left <= )
		// 未完待续。。。
	}


	return 0;
}