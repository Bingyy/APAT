#include <stdio.h>
#include <string.h>


// 未想通的版本
// 2017-2-23
char tem[63] = {'0','1','2','3','4','5','6','7','8','9',
		    'A','B','C','D','E','F','G','H','I','J',
		    'K','L','M','N','O','P','Q','R','S','T',
		    'U','V','W','X','Y','Z',
		    'a','b','c','d','e','f','g','h','i','j',
		    'k','l','m','n','o','p','q','r','s','t',
		    'u','v','w','x','y','z',
		    '_'
		   };  // 0~9, A~Z, a~z, _
int flags[63] = {0};

void change(char * str,int len)
{
	for(int i = 0; i < len; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			flags[str[i] - '0']++;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			flags[str[i] - 'A' + 10]++;
			flags[str[i] -'A' + 36]++;
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			flags[str[i] - 'a' + 36]++;
			flags[str[i] - 'a']++;
		}
		else if(str[i] == '_')
		{
			flags[62]++;
		}
	}
}
int main()
{
	char str[90];
	gets(str); // 输入字符串
	int len = strlen(str);

	change(str,len);

	char str2[90];
	gets(str2);

	int len2 = strlen(str2);
	change(str2,len2);

	for(int i = 0; i < 63; i++)
	{
		if(flags[i] == 1)// 当值为1时表示输入了，但是键盘坏了
		{
			printf("%c", tem[i]);
		}
	}
	printf("\n");
	return 0;
}