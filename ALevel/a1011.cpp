#include <stdio.h>
#include <map>
using namespace std;

// 2017-2-10 20:43
// Rick HZ.

int max(double a[3])
{
	double index;
	if(a[0] > a[1] && a[0] > a[2])
	{
		index = 0;
	} 
	else if(a[1] > a[0] && a[1] > a[2])
	{
		index = 1; 
	}
	else
	{
		index = 2;
	}
	return index;
}

map<int, char> ha = {{0,'W'}, {1,'T'}, {2,'L'}};

int main()
{
	double a[3], b[3], c[3];

	for(int i = 0; i < 3; i++)
	{
		scanf("%lf",&a[i]);
	}

	int aMax = max(a);

	for(int i = 0; i < 3; i++)
	{
		scanf("%lf",&b[i]);
	}

	int bMax = max(b);

	for(int i = 0; i < 3; i++)
	{
		scanf("%lf",&c[i]);
	}

	int cMax = max(c);

	double res = (a[aMax] * b[bMax] * c[cMax] * 0.65 - 1 ) * 2;

	printf("%c %c %c ", ha[aMax],ha[bMax],ha[cMax]);

	printf("%.2lf\n", res);
	return 0;
}