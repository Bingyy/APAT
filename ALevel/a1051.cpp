#include <stdio.h>
#include <stack>

using namespace std;
const int maxn = 1010;
int arr[maxn]; //保存题目给的序列

stack<int> st; // 定义栈

int main()
{
	int m, n, T;
	scanf("%d%d%d",&m, &n, &T);
	while(T--)
	{
		while(!st.empty())
		{
			st.pop();//清空栈
		}

		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		int current = 1; // 指向出栈序列的待出栈元素
		bool flag = true;
		for(int i = 1; i <= n; i++)
		{
			st.push(i); // 将i入栈，先入栈再判断是否需要出栈
			if(st.size() > m)
			{
				flag = false;
				break; // 栈的容量大于给定值，则非法，跳出循环
			}
			while(!st.empty() && st.top() == arr[current]) // 栈非空，且栈顶元素等于出栈序列的元素
			{
				st.pop(); //满足条件则反复出栈
				current++;
			}
		}

		if(st.empty() && flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}


	return 0;
}