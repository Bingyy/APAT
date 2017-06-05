#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 100010;
int n, p;

vector<int> ins;

// 二分法的思路：有序数列的操作

int binarySearch(int i, LL x)
{
	if(ins[n - 1] <= x)
	{
		return n; // 如果所有数都不大于x，返回x
	}

	int l = i + 1, r = n - 1,mid; // 左右边界

	while(l < r)
	{
		mid = (l + r) / 2;
		if(ins[mid] <= x)
		{
			l = mid + 1;
		}
		else 
		{
			r = mid;
		}
	}
	return l;
}


int main()
{
	int temp;
	scanf("%d%d", &n,&p);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&temp);
		ins.push_back(temp);
	}

	sort(ins.begin(),ins.end()); // 递增排序

	int ans = 1; // 最大长度，初始为1
	for(int i = 0; i < n; i++)
	{
		int j = binarySearch(i,(LL)(ins[i] * p));
		ans = max(ans,j - i);
	}
	printf("%d\n",ans);
	return 0;
}