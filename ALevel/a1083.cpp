#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct node
{
	char name[11];
	char id[11];
	int grade;
} stu[100];

bool cmp(node a, node b)
{
	return a.grade > b.grade; // 按照分数递减排序
}

int main()
{
	int n, left, right; // [left,right]: 分数区间
	// 处理输入数据
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %s %d",stu[i].name, stu[i].id,&stu[i].grade);
	}

	scanf("%d%d",&left,&right);
	sort(stu, stu + n, cmp);
	bool flag = false;
	for(int i = 0; i < n;i++)
	{
		if(stu[i].grade >= left && stu[i].grade <= right) // 通过判断语句筛选，是更加快速的方式
		{
			printf("%s %s\n",stu[i].name, stu[i].id);
			flag = true;
		}
	}

	if(flag == false)
	{
		printf("NONE\n");
	}

	return 0;
}