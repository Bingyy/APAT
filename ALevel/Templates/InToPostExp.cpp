#include <stack>
#include <stdio.h>
#include <map>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct node
{
	double num; // 操作数
	char op; // 操作符
	bool flag; // true:操作数，false：操作符
};

string str;
stack<node> s; // 操作符栈
queue<node> q; // 后缀表达式序列
map<char,int> op;

void change() // 将中缀表达式变为后缀表达式
{
	double num;
	node temp;
	for(int i = 0; i < str.length();) // 将i的增长放在下面
	{
		// 从左到右扫描字符串
		// 如果是操作数
		if(str[i] >= '0' && str[i] <= '9') // 操作数不止一位，所以需要用一个while循环继续判定
		{
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i < str.length() && str[i] >= '0' && str[i] <= '9')
			{
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else if(str[i] == '(') 
		{    // 如果是左括号
            temp.op = str[i];
            s.push(temp);    // 直接入操作符栈
            i++;
        } 
        else if(str[i] == ')') 
        {    // 如果是右括号
            while(!s.empty() && s.top().op != '(') {    // 只要还没有到达左括号
                q.push(s.top());    // 将操作符栈顶不断弹出到后缀表达式的队列中
                s.pop();
            }
            s.pop();    // 弹出左括号，不入队
            i++;
        }
		else // 如果是操作符
		{
			temp.flag = false;
			// 只要操作符栈的栈顶元素比该操作符优先级高，就把操作符栈顶元素弹出到后缀表达式队列
			while(!s.empty() && op[str[i]] <= op[s.top().op])
			{
				q.push(s.top());
				s.pop();
			}
			// 否则就将其压入栈中
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	// 扫描完后
	// 如果操作栈中还有操作符，就把它弹出到后缀表达队列中
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}

// 计算后缀表达式
double cal()
{
	double temp1, temp2;
	node cur, temp;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		if(cur.flag == true) s.push(cur); // 如果是操作数就压入栈
		else // 如果是操作符
		{
			temp2 = s.top().num; // 取出第二操作数
			s.pop();
			temp1 = s.top().num; // 取出第一操作数
			s.pop();
			temp.flag = true; 
			if(cur.op == '+') temp.num = temp1 + temp2;
			else if(cur.op == '-') temp.num = temp1 - temp2;
			else if(cur.op == '*') temp.num = temp1 * temp2;
			else temp.num = temp1 / temp2;
			s.push(temp); // 把该操作数压入栈
		}
	}
	return s.top().num;
}

int main()
{
	op['('] = op[')'] = 0;
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;

	getline(cin,str);

	// for(auto it = str.end(); it != str.begin(); it--)
	// {
	// 	if(*it == ' ') str.erase(it); // 去掉表达式中的空格
	// }
	// while(!s.empty())
	// {
	// 	s.pop();
	// }
	change();
	printf("%.2f\n", cal());

	return 0;
}




