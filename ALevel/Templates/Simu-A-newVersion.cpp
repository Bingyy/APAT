#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

map<string,int> mp = {
						{"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},
						{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}
					};
int strToNum(vector<string> str)
{
	int ans = 0;
	for(int i = 0; i < str.size(); i++)
	{
		ans = 10 * ans + mp[str[i]];
	}
	return ans;
}

 int main()
 {

	string s,word;

	int arr[3] = {0};
	int k;

	for(int i = 0; i < 3; i++)
	{	
		vector<string> str;
		getline(cin, s);
		istringstream stream(s); //绑定到istringstream对象上
		while(stream >> word)
		{
			str.push_back(word);
		}

		arr[i] = strToNum(str);
	}

	if(arr[0] + arr[1] > arr[2] && arr[0] + arr[2] > arr[1] && arr[1] + arr[2] > arr[0])
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
 }