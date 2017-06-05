#include <stdio.h>

// 输出男生最低分与女生最高分的差值
struct node
{
	char name[11];
	// char gender;
	char id[11];
	int grade;
}M,F,temp; // 只需要记录最高/低分，所以在输入时即可处理数据

void init() //记录的是男生最低分，不妨初始化为101，女生最高分，初始化为-1
{
	M.grade = 101;
	F.grade = -1;
}

// 输入时处理数据

int main()
{
	init();
	int n;
	char gender;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %c %s %d",temp.name,&gender,temp.id,&temp.grade);

		if(gender == 'M' && temp.grade < M.grade)
		{
			M = temp; //记录男性最低分即可
		}
		else if(gender == 'F' && temp.grade > F.grade)
		{
			F = temp;
		}
	}

	if(F.grade == -1) printf("Absent\n"); //没有女生
	else printf("%s %s\n",F.name,F.id);

	if(M.grade == 101) printf("Absent\n");
	else printf("%s %s\n",M.name, M.id);

	if(F.grade == -1 || M.grade == 101) 
	{
		printf("NA\n");
	}
	else printf("%d\n",F.grade - M.grade );
	return 0;
}