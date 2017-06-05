#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct student
{
	char id[10];
	int grade[4];
} stu[2010];

char courses[4] = {'A','C','M','E'};

// 因为需要比较考生的四个成绩排名取最好，所以考生的四个成绩排名都需要保存


// 如果id是字符数组型，可以考虑计算为整数
int hashID(char id[])
{
	int len = strlen(id);
	int intID = 0;

	for(int i = 0; i < len; i++)
	{
		intID = 10 * intID + id[i] - '0';
	}

	return intID;
}

int ranks[10000000][4] = {0}; //key:将考生的id进行散列,ranks[intId]:存储该生的四个成绩

int now; // 0~3标记按哪个来排序

bool cmp(student a, student b)
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	int n,m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
	{
		// 输入时处理数据：grade[0]~grade[3]:A,C,M,E
		scanf("%s %d%d%d",stu[i].id, &stu[i].grade[1],&stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3;
	}

	//把index放在外面，这样就可以复用且可以跟踪哪个成绩
	for(now = 0; now < 4; now++)//天然按照权重比较：A,C,M,E
	{	
		sort(stu,stu + n,cmp);
		ranks[hashID(stu[0].id)][now] = 1; // 
		for(int i = 1; i < n; i++)
		{
			if(stu[i].grade[now] == stu[i-1].grade[now])
			{
				ranks[hashID(stu[i].id)][now] = ranks[hashID(stu[i - 1].id)][now];
			} 
			else
			{
				ranks[hashID(stu[i].id)][now] = i + 1;//1，2，3，3，5这种排名是正确的
			}
		}

	}

	char id[10];

	for(int i = 0; i < m; i++)// n次查询
	{
		scanf("%s",id);
		int intID = hashID(id);
		if(ranks[intID][0] == 0)
		{
			printf("N/A\n");
		}
		else
		{
			int k = 0; 
			for(int j = 0; j < 4; j++)
			{
				if(ranks[intID][j] < ranks[intID][k])
				{
					k = j;
				}
			}
			printf("%d %c\n",ranks[intID][k],courses[k]);
		}
	}
	
	return 0;
}