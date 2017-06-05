#include <stdio.h>

int main()
{
	char str[15];
	for (int i = 0; i < 3; ++i)
	{
		/* code */
		str[i] = getchar();
	}

	puts(str);
	
	return 0;
}