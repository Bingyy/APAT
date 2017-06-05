#include <cstring>
#include <stdio.h>


int main()
{
	int a[5] = {1,2,3,4,5};

	memset(a,0,sizeof(a));

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	memset(a,1,sizeof(a));

	for (int i = 0; i < 5; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
	return 0;
}