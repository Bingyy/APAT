#include<cstdio>
#include<string>
#include<map>
#include<iostream>
using namespace std;
map<char,int> mp;
int main() {
	string a;
	getline(cin,a);
	int len=a.length();
	cout << "Hello1" << endl;
	for(int i=0; i<len-2; i++) {
		if(a[i]==a[i+1]&&a[i]==a[i+2]) {
			if(mp.count(a[i])==0) {
				mp[a[i]]=1;
			}
		}
		i=i+2;
	}
	cout << "Hello2" << endl;
	map<char,int>::iterator it;
	int i=0;
	while(i<len-2) {
		if(mp.find(a[i])!=mp.end()) {
			if(a[i]!=a[i+1]||a[i]!=a[i+2]) {
				mp[a[i]]=0;
				i++;
			} else {
				i=i+3;
			}
		}
	}
	cout << "Hello3" << endl;
	for(it=mp.begin(); it!=mp.end(); it++) {
		if(it->second==0) {
			mp.erase(it);
		}
	}
	for(int j=0; j<len-2; j++) {
		if(mp.find(a[j])!=mp.end()) {
			a.erase(j,j+2);
			len=len-2;
		}
	}
	for(it=mp.begin(); it!=mp.end(); it++) {
		printf("%c",it->first);
	}
	printf("\n");
	cout<<a<<endl;
	return 0;
}