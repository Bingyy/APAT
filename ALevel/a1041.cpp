#include <stdio.h>
#include <vector>
using namespace std;

int Hash[10001] = {0}; // 使用的下标是1~10000
vector<int> ins;
int main(int argc, char const *argv[])
{
	int n,temp;
	int res;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&temp);
		ins.push_back(temp);
		Hash[temp]++;
	}

	for(int i = 0; i < ins.size(); i++)
	{
		if(Hash[ins[i]] == 1)
		{
			res = ins[i]; // 暂存
			break;
		}
	}
	if(res == 0) 
	{
		printf("None\n");
	}
	else
	{
		printf("%d\n", res);
	}
	return 0;
}