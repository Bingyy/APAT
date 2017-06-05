#include <stdio.h>
#include <algorithm>

using namespace std;

struct Student
{
	int GE, GI,sum;
	int r, stuID; // 排名，考生编号
	int cho[6]; //K个选择学校的编号
} stu[40010];

struct School
{	
	int quota; // 招生名额
	int stuNum;// 实际招生数
	int id[40010];// 招收的学生编号
	int lastAdmit; // 记录最后一个招的学生编号,用于比较rank,破格录取
} sch[110];

bool cmpStu(Student a, Student b)
{
	if(a.sum != b.sum)
	{
		return a.sum > b.sum;
	}
	else return a.GE > b.GE; // 这里的else可以不用写
}

bool cmpID(int a, int b)
{
	return stu[a].stuID < stu[b].stuID; // 按照学生编号从小到大排序
}

int main(int argc, char const *argv[])
{
	int n, m,k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&sch[i].quota);
		sch[i].stuNum = 0;
		sch[i].lastAdmit = -1; // 最后一个招生的编号初始化为不存在
	}

	for(int i = 0; i < n; i++)
	{
		stu[i].stuID = i;
		scanf("%d%d",&stu[i].GE, &stu[i].GI);
		stu[i].sum = stu[i].GE + stu[i].GI;
		for(int j = 0; j < k; j++)
		{
			scanf("%d", &stu[i].cho[j]); // k个申请学校编号
		}
	}

	sort(stu, stu + n, cmpStu); // 给考生按照成绩排序
	for(int i = 0; i < n; i++)
	{
		// 每个都与前面一个进行比较
		if(i > 0 && stu[i].sum == stu[i - 1].sum && stu[i].GE == stu[i - 1].GE)
		{
			stu[i].r = stu[i - 1].r;
		}
		else
		{
			stu[i].r = i;
		}
	}

	// 选校流程模拟
	for(int i = 0; i < n; i++) // 对于每位考生，判断其被哪所学校录取
	{
		for(int j = 0; j < k; j++) // 枚举考生的k个选择
		{
			int choice = stu[i].cho[j]; // 考生i的第k个选择
			int num = sch[choice].stuNum; // 当前学校的招生人数
			int last = sch[choice].lastAdmit; // 选择学校的最后一位录取编号
			// 如果人数未满或该学校最后一个录取学生的排名与当前考生相同
			if(num < sch[choice].quota || (last != -1 && stu[i].r == stu[last].r))
			{
				sch[choice].id[num] = i;
				sch[choice].lastAdmit = i; // 该学校最后（最近）一个录取的学生变为i
				sch[choice].stuNum++; // 当前招生人数加1
				break; // 录取了就跳出循环，表示选校结束
			}
		}
	}

	// 控制输出

	for(int i = 0; i < m; i++)
	{
		if(sch[i].stuNum > 0)
		{
			// 按照学生id从小到大排序，id是学校招生的录取名单（数组）
			sort(sch[i].id,sch[i].id + sch[i].stuNum,cmpID);

			for(int j = 0; j < sch[i].stuNum; j++)
			{
				printf("%d", stu[sch[i].id[j]].stuID);
				if(j < sch[i].stuNum - 1)
				{
					printf(" "); // 控制最后no extra space
				}
			}
		}
		printf("\n");
	}
	return 0;
}