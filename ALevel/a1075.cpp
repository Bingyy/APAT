#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010;
struct Student
{
	int id; // 准考证号
	int score[6]; // 每道题的得分
	bool flag; // 是否有通过编译的提交
	int score_all; // 总分
	int solve; // 完美解题数
} stu[maxn];

int n,k,m; // n是学生总数
int full[6]; // 每道题的满分

bool cmp(Student a, Student b)
{
	if(a.score_all != b.score_all)
	{
		return a.score_all > b.score_all; //递减排序
	}
	else if(a.solve != b.solve)
	{
		return a.solve > b.solve;
	}
	else return a.id < b.id; //否则就按照id递增排序
}
// 初始化
void init()
{
	for(int i = 1; i <= n; i++)
	{
		stu[i].id = i; //准考证号为1~n
		stu[i].score_all = 0;
		stu[i].solve = 0;
		stu[i].flag = false;
		fill(stu[i].score,stu[i].score + 6, -1);
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i = 1; i <= k;i++)
	{
		scanf("%d",&full[i]);
	}
	int u_id,p_id, score_obtained; // 用户id, 题目id， 获得分数
	for(int i = 0; i < m; i++)
	{
		// 输入时处理数据
		scanf("%d%d%d",&u_id, &p_id, &score_obtained);
		if(score_obtained != -1) // 非编译错误，即有通过编译的题目
		{
			stu[u_id].flag = true;
		}
		if(score_obtained == -1 && stu[u_id].score[p_id] == -1)
		{
			stu[u_id].score[p_id] = 0; // 某题第一次编译错误记作0分
		}
		if(score_obtained == full[p_id] && stu[u_id].score[p_id] < full[p_id])
		{
			stu[u_id].solve++; //第一次获得满分，则完美解题数加1
		}
		if(score_obtained > stu[u_id].score[p_id])
		{
			stu[u_id].score[p_id] = score_obtained; // 某题获得更高分则更新为新的分数
		}
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= k; j++) // k是题目总数
		{
			if(stu[i].score[j] != -1)// 计算总分
			{
				stu[i].score_all += stu[i].score[j];
			}
		}
	}

	sort(stu+1, stu+n+1,cmp);// 从标号1开始排序，排序规则已经写好

	// 处理排名情况：这个也是PAT特色，总分相同排名相同，但是后面的人排名要记总人数，比如 1 2 2 2 5这样的名次
	int r = 1; // 当前排名
	for(int i = 1; i <= n && stu[i].flag == true; i++)
	{
		if(i > 1 && stu[i].score_all != stu[i - 1].score_all)
		{
			r = i; //1 2 2 2 5这样的排名就是这么处理得到的，如果当前考生成绩低于前面一位的成绩，那么他的排名就是自己的序号，否则不更新r就表示自己排名与前一名相同
		}
		printf("%d %05d %d", r,stu[i].id,stu[i].score_all);

		for(int j = 1; j <= k; j++)
		{
			if(stu[i].score[j] == -1)
			{
				printf(" -"); // 没有提交过
			}
			else
			{
				printf(" %d",stu[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
