int pre[1000];//记录每个点的前导点是什么
int find(int x) //查找根节点
{
	int r = x;
	while(pre[r] != r) //返回根节点r
		r = pre[r];

	int i = x,j;//路径压缩
	while(i != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}
void join(int x, int y)
{
	//判断x,y是否连通，如果连通就啥也不做，否则就把这个两个分支合并起来
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		pre[fx] = fy;
}