#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int coupon[maxn],product[maxn];

int main(int argc, char const *argv[])
{
	int n, m;	
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&coupon[i]);
	}

	scanf("%d",&m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&product[i]);
	}

	sort(coupon, coupon + n); // 优惠券按照从小到大排序
	sort(product,product + m); //产品价格也从小到大排序

	int i = 0, j, ans = 0; //  ans 存放乘积之和
	while(i < n && i < m && coupon[i] < 0 && product[i] < 0) // 从前往后算是比较整齐的，一个下标即可跟踪
	{
		ans += coupon[i] * product[i]; //当期那位置元素均小于0，累加乘积
		i++;
	}

	i = n - 1;
	j = m - 1;
	while(i >= 0 && j >= 0&& coupon[i] > 0 && product[j] > 0) // 从后往前，下标需要两个，因为不整齐
	{
		ans += coupon[i] * product[j];
		i--;
		j--;
	}

	printf("%d\n", ans);
	return 0;
}