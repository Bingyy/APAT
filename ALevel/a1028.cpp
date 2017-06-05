#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct node
{
	char id[10];
	char name[10];
	int grade;
} stu[100010];

int c;

bool cmp(node a, node b)
{
	if(c == 1) //按照id排序
	{
		int res = strcmp(a.id, b.id);
		return  res < 0;// id不同时按照id递减排序
	}
	else if(c == 2) // 按照名字排序
	{
		int res = strcmp(a.name,b.name); //非递排序
		if(res != 0)
		{
			return res < 0;
		} 
		else
		{
			return strcmp(a.id, b.id) < 0;
		} 
	
	}
	else// 按照成绩排序
	{
		if(a.grade != b.grade)
		{
			return a.grade < b.grade;
		}
		else // 成绩相同按照id递增排序
		{
			return strcmp(a.id, b.id) < 0;
		}	
	}
}

int main()
{
	int n; //n:记录数， c:列号， 1，2，3
	scanf("%d%d", &n,&c);

	for(int i = 0; i < n;i++)
	{
		scanf("%s %s %d", stu[i].id, stu[i].name,&stu[i].grade);
	}

	sort(stu,stu + n,cmp);

	for(int i = 0; i < n; i++)
	{
		printf("%s %s %d\n",stu[i].id,stu[i].name, stu[i].grade);
	}

	return 0;
}