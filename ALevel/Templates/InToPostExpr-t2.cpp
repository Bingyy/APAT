#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
using namespace std;

string str;

struct node
{
	double num;
	char op;// 存储操作符
	bool flag; // true: 数字 false:操作符
};
stack<node> s;
queue<node> q; // 存储后缀表达式

map<char, int> op = {{'(',0},{')',0},{'+',1},{'-',1},{'*',2},{'/',2}}; // 存储操作符优先级

void change() // 将中缀变后缀
{
	node temp;
	for(int i = 0; i < str.length();) // 从左到右扫描中缀表达式
	{
		// 每一层判断后都需要控制i++
		if(str[i] >= '0' && str[i] <= '9') // 如果字符是个数字
		{
			temp.flag = true; // 先立flag
			temp.num = str[i++] - '0'; // 先计算一个数位
			while(i < str.length() && str[i] >= '0' && str[i] <= '9') // 还是数位
			{
				temp.num = 10 * temp.num + (str[i] - '0');
				i++;
			}
			q.push(temp);
		}
		else if(str[i] == '(')// 如果是个操作符
		{
			temp.flag = false;
			temp.op = str[i];
			s.push(temp);
			i++; 
		}
		else if(str[i] == ')')
		{
			while(!s.empty() && s.top().op != '(')
			{
				q.push(s.top());
				s.pop();
			}
			s.pop(); //弹出左括号
			i++;
		}
		else 
		{
			temp.flag = false; // 操作符
			while(!s.empty() && op[str[i]] <= op[s.top().op]) // 如果优先级决定了还不能进入，就先处理
			{
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
}
 
double cal() // change完栈是空的了
{
	node cur, temp;
	double t1, t2; // 存储两个操作数
	
	while(!q.empty()) // 队列还不空时
	{
		cur = q.front();
		q.pop();
		if(cur.flag == true) s.push(cur); // 如果是操作数加进栈中
		else // 如果是操作符：取出两个操作数
		{
			t2 = s.top().num;
			s.pop();
			t1 = s.top().num;
			s.pop();
			temp.flag = true;// 标记量个操作数之和也是个数

			if(cur.op == '+') temp.num = t1 + t2;
			else if(cur.op == '-') temp.num = t1 - t2;
			else if(cur.op == '*') temp.num = t1 * t2;
			else temp.num = t1 / t2;
			s.push(temp); //加进栈中
		}
	}
	return s.top().num; // 最终栈中只留下一个操作数：最终计算结果
}

int main()
{
	getline(cin,str);
	change(); // 中缀变后缀
	printf("%.2f\n", cal()); // 输出后缀表达式的值
	return 0;
}