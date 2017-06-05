#include <stdio.h>
#include <stack>
#include <map>

using namespace std;

// 两个优先级
// 这个还是没想明白，未完待续。
map<char,int> isp = {{'#',0},{'(',6},{')',1},{'+',2},{'-',2},{'*',4},{'/',4}};
map<char,int> icp = {{'#',0},{'(',1},{')',6},{'+',3},{'-',3},{'*',5},{'/',5}};

stack<char> temp; // 暂时存储符号，用于辅助将中缀变为后缀

// 先写将中缀表达式变为后缀表达式的方法
char* InToPost(char str[])
{
	temp.push('#');
	char* res;
	int len = strlen(str);
	// 扫描中缀表达式
	for(int i = 0; i < len; i++)
	{

		if(str[i] >= '0' && str[i] <= '9')
		{
			res += str[i]; // 如果是数字字符就加到后缀表达式 
		}
		else if(icp[str[i]] > isp[temp.top()]) // 扫描的字符优先级大于栈顶则可以进入
		{
			temp.push(str[i]);
		}
		else if(icp[str[i]] < isp[temp.top()]) // 退栈并输出
		{
			res += temp.top(); // 取栈顶输出到后缀表达式
			temp.pop(); // 栈顶出栈
		}
		else if(icp[str[i]] == isp[temp.top()])
		{
			while(temp.top() != '(')
			{
				res += temp.top();
				temp.pop();
			}
		}	
	}
	return res;
}

int main()
{
	char exp[50];
	scanf("%s",exp);
	char* res = InToPost(exp);

	printf("%s\n",res);
	return 0;
}