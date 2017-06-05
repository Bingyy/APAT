#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int> >adjlist;
int record[101]={0};

void DFS(int id,int level){
	if(adjlist[id].empty()){
		++record[level];
		return;
	}

	vector<int>::iterator ite = adjlist[id].begin();
	for(;ite!=adjlist[id].end();++ite){
		DFS(*ite,level+1);
	}
}

int main(){

	//freopen("in.txt","r",stdin);
	int n,m,id,k,sid,i,cle,cnt;

	scanf("%d %d",&n,&m);
	cle = n-m;
	while(m--){
		scanf("%d %d",&id,&k);
		while(k--){
			scanf("%d",&sid);
			adjlist[id].push_back(sid);
		}
	}

	DFS(1,0);

	printf("%d",record[0]);
	cnt = record[0];
	for(i=1;cnt<cle;++i){
		printf(" %d",record[i]);
		cnt += record[i];
	}
	printf("\n");
	return 0;
}