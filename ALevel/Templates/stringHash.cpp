#include <cstdio>

int hashFunc(char S[],int len)
{
	int id = 0;
	for(int i = 0; i < len; i++)
	{
		id = id * 26 + (S[i] - 'A'); // 相比进制转换，这里不用剥离出digit，更简单了些
	}

	return id;
}

int main(int argc, char const *argv[])
{
	/* code */
	char str[12] = "Hello World";
	int res = hashFunc(str,10);

	printf("%d\n", res);
	return 0;
}