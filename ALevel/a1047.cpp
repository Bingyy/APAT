#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 40010;
const int maxc = 2510;

char name[maxn][5]; // maxn 学生个数
vector<int> course[maxc]; // course[i]:存放第i门课所有学生的编号，类似邻接表的思路,在图论哪那里用过这种方式实现

bool cmp(int a, int b) // 给出下标
{
	return strcmp(name[a], name[b]) < 0; //  名字按照字典序从小到大排序
}

int main(int argc, char const *argv[])
{
	int n,k,c,courseID;
	scanf("%d%d",&n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d", name[i],&c); // 学生姓名以及选课数
		for(int j = 0; j < c; j++)
		{
			scanf("%d", &courseID);
			course[courseID].push_back(i);//将学生i加入第courseID门课中
		}
	}

	for(int i = 1; i <= k; i++)
	{
		printf("%d %d\n",i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for(int j = 0; j < course[i].size(); j++)
		{
			printf("%s\n",name[course[i][j]]);
		}
	}
	return 0;
}
