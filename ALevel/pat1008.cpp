#include <stdio.h>
#include <vector>

using namespace std;

// 2017-2-10 10:40
// Rick HZ

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> ins(n);
	vector<int> res;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &ins[i]); //input number
		i > 0 ?  res.push_back(ins[i] - ins[i-1]) : res.push_back(ins[0]);
		// printf("%d\n", res[i]);
	}

	for(int i = 0; i < n; i++)
	{
		if(res[i] > 0)
		{
			sum += 6 * res[i];
		}
		else if(res[i] < 0)
		{
			sum += 4 * (-res[i]);
		}
	}
	sum += 5 * n;
	printf("%d\n", sum);
 	return 0;
}