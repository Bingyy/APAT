#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

 int main()
 {
	 string line,word;

	 vector<string> s1;

	 getline(cin,line); // 输入一行数据

	 // 将一行数据绑定在一起istringstream对象上
	 istringstream stream(line); 

	 while(stream >> word)
	 {
		 s1.push_back(word);
	 }

	 for(auto it = s1.begin(); it != s1.end(); it++)
	 {   		 
		cout << *it << " " << flush; // 将缓冲区的内容马上送进cout，并把输出缓冲区刷新	 
	 }
	 cout << endl;
	 return 0;
 }