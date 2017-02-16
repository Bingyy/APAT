#include <stdio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef struct student
{
	int cg,mg,eg,ag;
} student;

map<string,int> cgs;
map<string,int> mgs;
map<string,int> egs;
map<string,int> ags;

map<string,student> stus;

int main()
{
	int m,n;
	scanf("%d %d", &m, &n);

	string id;
	student stu;
	for(int i = 0; i < m; i++)
	{
		scanf("%s %d %d %d",&id, &stu.cg,&stu.mg, &stu.eg);
		stu.ag = (stu.cg + stu.mg + stu.eg)/3;
		stus.insert(pair<string, student>(id,stu));
	}

	printf("%d\n", stus["310103"].mg);

	return 0;
}