#include <stdio.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	ll res = (b == 0 ? a : gcd(b, a % b));
	return res;
}
struct Fraction
{
	ll up, down;
};

Fraction reduction(Fraction result)
{
	// 化简分式
	// 若分母为负数，则分子分母同时变为相反数
	if(result.down < 0)
	{
		result.up = -result.up;
		result.down = -result.down;
	}

	if(result.up == 0)
	{
		result.down = 1; // 分子为0 直接令分母为1即可
	}

	else
	{
		ll d = gcd(abs(result.up),abs(result.down));
		result.up /= d;
		result.down /= d;
	}
	return result;
}
Fraction add(Fraction a, Fraction b)
{
	Fraction res;
	res.up = a.up * b.down + a.down * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

void showRes(Fraction res)
{
	reduction(res);
	if(res.down == 1)
	{
		printf("%lld\n",res.up);
	}
	else if(abs(res.up) > res.down)
	{
		printf("%lld %lld/%lld\n",res.up / res.down, abs(res.up) % res.down, res.down);
	}
	else
	{
		printf("%lld/%lld\n",res.up, res.down);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	Fraction sum, temp;
	sum.up = 0;
	sum.down = 1;
	for(int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	}

	showRes(sum);
	return 0;
}