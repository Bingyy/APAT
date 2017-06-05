#include <stdio.h>
#include <string.h>

const int MAXN = 10005;
char a[MAXN],b[MAXN];

bool HashTable[128] = {false}; // 标记可用ASCII标记字符

int main(int argc, char const *argv[])
{
	gets(a);
	gets(b);
	int len1 = strlen(a);
	int len2 = strlen(b);

	for(int i = 0; i < len2; i++)
	{
		HashTable[b[i]] = true;
	}

	for(int i = 0; i < len1; i++)
	{
		if(HashTable[a[i]] == false)
		{
			printf("%c", a[i]);
		}
	}

	printf("\n");
	return 0;
}