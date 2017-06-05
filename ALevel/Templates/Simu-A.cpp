#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> mp = {
						{"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},
						{"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}
					};
int main()
{
	string s;

	int arr[3] = {0};
	int k;

	for(int i = 0; i < 3; i++)
	{
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			cin >> s;
			arr[i] = 10 * arr[i] + mp[s];
		}
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