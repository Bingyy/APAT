#include <stdio.h>

int main()
{
	int T, tcase = 1;
	scanf("%d",&T);
	while(T--)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long res = a + b; // 正负相加不溢出
		bool flag;
		if(a > 0 && b > 0 && res < 0) flag = true; //正溢出
		else if(a < 0 && b < 0 && res >= 0) flag = false; // 负溢出,注意两个负数为之和为0时也是溢出
		else if(res > c) flag = true;
		else flag = false;

		if(flag == true)
		{
			printf("Case #%d: true\n", tcase++);
		}
		else 
		{
			printf("Case #%d: false\n",tcase++);
		}
	}
	return 0;
}
