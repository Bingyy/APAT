#define N 100
typedef struct node
{
	int data;//结点对应人的编号
	int rank; //结点对应秩
	int parent;//结点对应双亲下标
}UFSTree;

void MAKE_SET(UFSTree t[])
{
	//初始化并查集树
	int i;
	for(i = 1; i<=N;i++)
	{
		t[i].data = i;
		t[i].rank = 0;
		t[i].parent = i;
	}
}

int FIND_SET(UFSTree t[],int x)
{
	//在x所在的子树种查找集合编号
	if(x!=t[x].parent)//双亲不是自己,递归在双亲中找x
		return(FIND_SET(t,t[x].parent));
	else
		return x;
}

void UNION(UFSTree t[],int x, int y)
{
	//将x,y所在的子树合并
	x = FIND_SET(t,x);
	y = FIND_SET(t,y);
	if(t[x].rank > t[y].rank)
		t[y].parent = x;
	else
	{
		t[x].parent = y;
		if(t[x].rank == t[y].rank)
			t[y].rank++;
	}
}