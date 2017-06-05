#include <stdio.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

struct Fraction
{
	ll up, down;
}a,b;


Fraction reduction(Fraction res) // 化简函数
{
	if(res.down < 0) // 保障分母是正的
	{
		res.up = -res.up;
		res.down = -res.down;
	}

	if(res.up == 0) //分子为0，则令分母为1
	{
		res.down = 1;
	}
	else // 否则进行约分
	{
		int d = gcd(abs(res.up), abs(res.down));
		res.up /= d;
		res.down /= d;
	}
	return res;
}

Fraction add(Fraction a, Fraction b)
{
	Fraction res;
	res.up = a.up * b.down + a.down * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

Fraction sub(Fraction a, Fraction b)
{
	Fraction res;
	res.up = a.up * b.down - a.down * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

Fraction mul(Fraction a, Fraction b)
{
	Fraction res;
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	return reduction(res);
}

Fraction div(Fraction a, Fraction b)
{
	Fraction res;
	res.up = a.up * b.down;
	res.down = a.down * b.up;
	return reduction(res);
}

void showResult(Fraction res) // 输出分数
{
	res = reduction(res); //这步是为了处理没有经过加减乘除的分式的输出

	if(res.up < 0)
	{
		printf("(");
	}
	if(res.down == 1) // 
	{
		printf("%lld",res.up);
	}
	else if(abs(res.up) > abs(res.down)) // 假分数的判断需要用绝对值来看
	{
		printf("%lld %lld/%lld", res.up / res.down, abs(res.up) % res.down, res.down);
	}
	else
	{
		printf("%lld/%lld", res.up, res.down);
	}
	if(res.up < 0)
	{
		printf(")");
	}
}


int main(int argc, char const *argv[])
{
	scanf("%lld/%lld %lld/%lld",&a.up, &a.down, &b.up, &b.down);
	// 加法
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a,b));
	printf("\n");

	// 减法
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(sub(a,b));
	printf("\n");

	// 乘法
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(mul(a,b));
	printf("\n");

	// 除法
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up == 0)
	{
		printf("Inf");
	}
	else
	{
		showResult(div(a,b));
	}

	printf("\n");
	return 0;
}