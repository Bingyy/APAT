#include <stdio.h>

// 这类属于数学问题，需要总结出规律来

int main()
{
	int n, a = 1, ans = 0;
	int left, right, now;
	scanf("%d",&n);
	while( n / a != 0)
	{
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0)
		{
			ans += left * a;
		}
		else if (now == 1)
		{
			ans += left * a + right + 1;
		}
		else
		{
			ans += (left + 1) * a;
		}
		a *= 10;
	}
	printf("%d\n",ans);
	return 0;
}