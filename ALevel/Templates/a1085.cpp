#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ins;

int main()
{
	int n, p;
	int temp;
	scanf("%d%d", &n,&p);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&temp);
		ins.push_back(temp);
	}

	sort(ins.begin(),ins.end()); // 递增排序

	long long M = ins[n - 1];
	long long m = ins[0];

	long long res;

	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		res = m * p;
		if(M <= res)
		{
			cnt++;
		}
	}

	printf("%lld\n",M );
	return 0;
}