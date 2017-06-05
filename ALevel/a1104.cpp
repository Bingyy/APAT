#include <stdio.h>

int main()
{
	int n = 0;
	double v, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf", &v);
		ans += v * i * (n + 1 - i);
	}
	printf("%.2f\n", ans);
	return 0;
}