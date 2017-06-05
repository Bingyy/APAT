#include <cstdio>
#include <cstring>

// 反向输出单词
// "Hello World" -> "World Hello"
int main(int argc, char const *argv[])
{
	char str[90];
	char ans[90][90];

	scanf("%s",str);

	int length = strlen(str);

	int row = 0, col = 0;
	for(int i = 0; i < length; i++)
	{
		if(str[i] == ' ')
		{
			ans[row][col] = '\0'; // 每一个单词是一个字符数组，字符数组需要以'\0'结尾
			row++;
			col = 0;
		}
		else 
		{
			ans[row][col++] = str[i];
		}
	}

	for(int i = row; i >= 0 ; i--)
	{
		printf("%s ",ans[i]);
		if(i > 0) printf(" ");
	}
	return 0;
}