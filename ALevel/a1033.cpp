#include <stdio.h>
#include <algorithm>

// 2017-2-24 17:40
// 本题思路明白，但是转化为代码还欠缺一点功夫
using namespace std;

const int maxn = 510;
const int INF = 1 << 30;
struct station
{
	double price, dis; //价格，与起点的距离
} st[maxn];

bool cmp(station a, station b)
{
	return a.dis < b.dis; //按照距离排序
}

int main(int argc, char const *argv[])
{
	int n;
	double Cmax,D,Davg;
	scanf("%lf%lf%lf%d", &Cmax,&D,&Davg,&n);

	for(int i = 0; i < n;i++)
	{
		scanf("%lf%lf",&st[i].price,&st[i].dis);
	}

	st[n].price = 0; // 数组最后面放置终点，价格是0
	st[n].dis = D; // 终点距离为D

	sort(st,st+n,cmp);

	if(st[0].dis != 0)
	{
		// 排在第一的加油站距离不是0，表示无法启程，因为初始油箱是空的
		printf("The maximum travel distance = 0.00\n");
	}
	else 
	{
		int now = 0; // 当前所处的加油站编号
		double ans = 0, nowTank = 0, MAX = Cmax * Davg; // 总花费，当前油量和满油行驶距离
		while(now < n)
		{
			// 每次循环找出下一个需要到达的加油站
			int k = -1; // 最低油价的加油站编号
			double priceMin = INF; // 最低油价
			for(int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				if(st[i].price < priceMin)
				{
					priceMin = st[i].price;
					k = i;
					// 如果找到第一个油价低于当前油价的加油站，直接中断循环
					if(priceMin < st[now].price)
					{
						break;
					}
				}
			}

			if(k == -1) break; // 满油状态下找不到加油站，退出循环输出结果

			// 能找到可到达的加油站k，计算转移花费
			double need = (st[k].dis - st[now].dis) / Davg;
			if(priceMin < st[now].price)
			{
				// 如果加油站k的油价低于当前油价
				// 只卖足够到达加油站k的油量
				if(nowTank < need)
				{
					ans += (need - nowTank) * st[now].price; //当前油量不足need,不足need
					nowTank = 0;// 到达加油站k后邮箱内油量为0
				}
				else
				{
					nowTank -= need; // 当前油量超过need，直接到达加油站k
				}
			}
			else
			{
				ans += (Cmax - nowTank) * st[now].price; // 将油箱加满
				nowTank = Cmax - need; // 到达加油站k后油箱内油量为Cmax - need
			}
			now = k;
		}
		if(now == n)
		{
			printf("%.2f\n",ans);
		}
		else
		{
			printf("The maximum travel distance = %.2f\n",st[now].dis + MAX);
		}
	}
	return 0;
}