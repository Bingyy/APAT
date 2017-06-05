#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	set<int> st;

	for(int i = 0; i <= 3; i++)
	{
		st.insert(i);
	}
	//find(value) 函数, 返回迭代器
	auto it = st.find(2);
	printf("%d\n", *it);
	//erase(迭代器)，set这里需要结合find使用
	
	return 0;
}