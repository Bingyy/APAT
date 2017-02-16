#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

float polA[1001] = {0.0};
float polB[1001] = {0.0};
float polC[2001] = {0.0};
int main()
{
	int m,n;
	scanf("%d ",&m);

	int exponent;
	float coefficient;

	for(int i = 0; i < m; i++) // process input
	{
		scanf("%d %f", &exponent, &coefficient);
		polA[exponent] = coefficient;
	}


	scanf("%d ",&n);

	for(int i = 0; i < n; i++) // process input
	{
		scanf("%d %f", &exponent, &coefficient);
		polB[exponent] = coefficient;
	}


	for(int i = 0; i < 1001; i++) // calcuate
	
		for(int j = 0; j < 1001; j++)
		{
			polC[i + j] += polA[i] * polB[j];
		}
	}

	int cnt = 0;
	for(int i = 0; i < 2001; i++)
	{
		if(polC[i]) cnt++;
	}

	printf("%d",cnt);

	for(int i = 2000; i >=0; i--)
	{
		if(polC[i])
		{
			printf(" %d %.1f", i,polC[i]);
		}
	}
	
	printf("\n");
	return 0;

}