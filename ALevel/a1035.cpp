#include <stdio.h>
#include <string.h>

struct node
{
	char name[20],password[20];
	bool isChanged; //true表示已经修改，如果修改了，修改行为直接作用在原数据上，输出即可
} T[1005]; //结构体数组

void change(node &t, int &cnt)
{
	int len = strlen(t.password); // 取得password的长度
	for(int i = 0; i < len; i++)
	{
		// 枚举password中的每一位
		if(t.password[i] == '1')
		{
			t.password[i] = '@';
			t.isChanged = true; //修改了就标记出来
		}
		else if(t.password[i] == '0')
		{
			t.password[i] = '%';
			t.isChanged = true;
		}
		else if(t.password[i] == 'l')
		{
			t.password[i] = 'L';
			t.isChanged = true;
		}
		else if(t.password[i] == 'O')
		{
			t.password[i] = 'o';
			t.isChanged = true;
		}
	}

	if(t.isChanged) //如果修改了一个就自增
	{
		cnt++;
	}
}
int main()
{
	int n,cnt = 0;
	scanf("%d",&n);
	for(int i = 0; i < n;i++)
	{
		scanf("%s %s",T[i].name,T[i].password);//字符数组不用取址符号
		T[i].isChanged = false;
	}

	for(int i = 0; i < n;i++) //针对每一个结构体进行检验修改，修改直接作用在原数据
	{
		change(T[i],cnt);
	}

	if(cnt == 0)
	{
		if(n == 1)
		{
			printf("There is %d account and no account is modified\n",n);
		}
		else
		{
			printf("There are %d accounts and no account is modified\n",n);
		}
	}
	else
	{
		printf("%d\n",cnt);
		for(int i = 0; i < n;i++)
		{
			if(T[i].isChanged)
			{
				printf("%s %s\n",T[i].name,T[i].password);
			}
		}
	}
	return 0;
}