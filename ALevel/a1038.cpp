#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b)
{
	return a + b < b + a; // 拼接后看字典序
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	sort(str,str + n, cmp);
	string ans; // 结果字符串
	for(int i = 0; i < n; i++)
	{
		ans += str[i];
	}

	while(ans.size() != 0 && ans[0] == '0')
	{
		ans.erase(ans.begin()); // 清除前导0的写法
	}

	if(ans.size() == 0) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}