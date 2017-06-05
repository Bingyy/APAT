#include <stdio.h>
#include <vector>

using namespace std;

int n,k,p;
int maxFacSum = -1;
vector<int> fac, ans, temp;

int power(int x)
{
	// 计算x^p
	int ans = 1;
	for(int i = 0; i < p; i++)
	{
		ans *= x;
	}

	return ans;
}

// 预处理fac数组
void init()
{
	int i = 0, temp = 0;
	while(temp <= n)
	{
		fac.push_back(temp);
		temp = power(++i);
	}
}

// 上面搜索空间已经建立，现在需要进行搜索啦
void DFS(int index,int nowK, int sum, int facSum)
{
	if(sum == n && nowK == k) // 递归边界：找到满足的序列
	{
		if(facSum > maxFacSum) // 如果更大，更新最大的底数之和
		{
			ans = temp;
			maxFacSum = facSum;
		}
		return; //归
	}

	if(sum > n || nowK > k)
	{
		return; // 没有找到答案也往回归
	}

	if(index >= 1)
	{
		temp.push_back(index); // 先加进临时序列中
		DFS(index, nowK + 1,sum + fac[index],facSum + index); // 选择fac[index]的分支
		temp.pop_back(); // 表示要进入不选的分支，把index这个从临时序列中pop掉
		DFS(index - 1, nowK, sum, facSum); // 不选fac[index]的分支
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &n, &k, &p);
	init();// 初始化fac数组
	DFS(fac.size() - 1, 0,0,0); // 从fac数组的最后一位开始往前搜索
	if(maxFacSum == -1) printf("Impossible\n"); // 没找到
	else
	{
		printf("%d = %d^%d",n, ans[0],p);
		for(int i = 1; i < ans.size(); i++)
		{
			printf(" + %d^%d", ans[i],p);
		}
		printf("\n");
	}
	return 0;
}
