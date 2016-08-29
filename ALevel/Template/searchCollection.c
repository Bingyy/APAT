#define MAXV 100
typedef int InfoType;
//定义邻接矩阵类型
typedef struct 
{
	int no; //顶点编号
	InfoType info;//顶点其他信息
}VertexType; //顶点类型

typedef struct 
{
	int edges[MAVX][MAVX]; //邻接矩阵
	int vexnum, arcnum;//顶点数和边数
	VertexType vexs[MAXV];//存储顶点
}MGraph;

//定义邻接表类型
typedef struct ANode
{
	int adjvex;//指示弧结点在顺序表中的位置
	struct ANode *nextarc;//指向下一个结点
	InfoType info;
}ArcNode; //定义弧结点类型

typedef int Vertex;

typedef struct VNode //邻接表头结点的类型（顺序存储）
{
	Vertex data; //顶点信息
	ArcNode *firstarc;//指向第一条弧	
}VNode,AdjList[MAXV];

typedef struct 
{
	AdjList adjlist;//邻接表
	int n,e; //顶点结点数目和边数目
}ALGraph;


