#define maxNodes 15
void generateTree(Tree &root, int seq[],int degree[],int n)
{
	Node *p = new Node(maxNodes);结构体数组
	int k;// 跟踪子女结点序号
	for(int i = 0; i < n;i++)
	{
		p[i]= new Node();
		p[i].data = e[i];
		p[i].lchild = p[i].rsibling = NULL; // 初始化
	}

	for(int i = 0; i < n; i++)
	{
		d = degree[i];
		if(d) // 如果度数不为0
		{
			k++;//初始第二个结点是根的孩子结点
			p[i].lchild = p[k]; // i是k的父亲
			for(int j = 2; j <= d; j++)
			{
				p[k-1].rsibling = p[k];
			}
		}
	}
	root = p[0];
	delete p;
}