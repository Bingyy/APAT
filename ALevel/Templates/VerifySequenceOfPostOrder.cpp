bool VerifySequenceOfPostOrder(int sequence[], int length)
{
	if(sequence == NULL || length <= 0)
	{
		return false;
	}

	int root = sequence[length - 1];

	int i = 0;
	//找到右子树的开始结点
	for(; i < length - 1; i++)
	{
		if(sequence[i] > root) // 结束循环时i指向的左子树后面的元素--右子树第一个元素
		{
			break;
		}
	}

	// 检查右子树看是否每个结点值都大于根结点
	int j = i;
	for(;j < length - 1; j++)
	{
		if(sequence[j] < root)
		{
			return false; // 一旦有任何一个结点值小于根，则不满足，返回false即可
		}
	}

	bool left = true;

	if(i > 0)
	{
		left = VerifySequenceOfPostOrder(sequence, i);//检查的是[0...i-1]
	}

	bool right = true;
	if(i < length - 1)
	{
		right = VerifySequenceOfPostOrder(sequence + i,length - i - 1); //sequence指向的是数组首地址，+i后指向的是右子树的序列首地址
	}
	return (left && right);
}



