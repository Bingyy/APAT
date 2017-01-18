#include <iostream>
#include <vector>
using namespace std;


int BinarySearch(vector<int> ins, int key)
{
	int low = 0,high = ins.size() - 1, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(ins[mid] == key)
		{
			return mid;
		}
		else if(ins[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1; 
		}
	}

	return -1;
}


int main()
{
	vector<int> ins;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ins.push_back(a); 
	}
	int key;
	cin >> key;
	cout << BinarySearch(ins,key) << endl;
}