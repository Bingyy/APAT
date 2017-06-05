#include <stdio.h>
#include <algorithm>
using namespace std;

 // upper_bound函数：返回第一个大于该元素的位置或者迭代器

const int maxn = 100010;

int n, p, a[maxn];

int main(int argc, char const *argv[])
{
	scanf("%d%d",&n, &p);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}

	sort(a,a+n); // 递增排序
	int ans = 1;
	for(int i = 0; i < n; i++)
	{
		int j = upper_bound(a + i + 1, a + n,(long long) a[i] * p) - a;
		ans = max(ans, j - i);
	}

	printf("%d\n", ans);

	return 0;
}