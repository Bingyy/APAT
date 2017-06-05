#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <string>

// 本题处理逻辑并不复杂，主要是多个映射的组合使用以及细节问题的处理
// 尤其关键的是，何时需要用getchar接收掉换行符

using namespace std;
// 后面需要输出一个信息对应的书的id，因此，建立除id以外的信息对id集合的映射
map<string,set<int> >mpTitle,mpAuthor, mpKey,mpPub, mpYear;

void query(map<string,set<int> > &mp, string &str) // map类型用引用传递加速
{
	if(mp.find(str) == mp.end())
	{
		printf("Not Found\n"); // 找不到
	}
	else // 找到
	{
		for(auto it = mp[str].begin(); it != mp[str].end(); it++)
		{
			printf("%07d\n",*it); // 输出对应信息的所有书的id
		}
	}
}
int main()
{
	int n, m, id, type;
	string title, author, key, pub, year; // 书的查询信息
	scanf("%d", &n);

	// 处理输入的一堆数据
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &id);
		char c = getchar(); // 接收掉id后面的换行

		getline(cin,title); // 读入书名
		mpTitle[title].insert(id);

		getline(cin,author); // string后面不用接收掉换行符号，由换行符表示结束
		mpAuthor[author].insert(id);

		// 读入多个关键词
		while(cin >> key)
		{
			mpKey[key].insert(id);
			c = getchar();
			if(c == '\n') break; //如果是换行符，说明关键词结束
		}

		getline(cin, pub);
		mpPub[pub].insert(id);

		getline(cin, year);
		mpYear[year].insert(id);

	}

	string temp;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;

		if(type == 1)
		{
			query(mpTitle,temp);
		}
		else if(type == 2)
		{
			query(mpAuthor, temp);
		}
		else if(type == 3)
		{
			query(mpKey, temp);
		}
		else if(type == 4)
		{
			query(mpPub, temp);
		}
		else
		{
			query(mpYear, temp);
		}
	}
	return 0;
}