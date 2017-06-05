#include<stdio.h>
#define maxint 1<<28
int N,M,C1,C2;
int map[510][510],vst[510],dis[510],hel[510];
int pathcnt[510],pathhel[510];
void init(){
	int i,j;
	for(i=1;i<=N;i++){
		vst[i]=0;
		hel[i]=0;
		dis[i]=maxint;
		pathcnt[i]=0;
		pathhel[i]=0;
		for(j=1;j<=N;j++){
			map[i][j]=map[j][i]=maxint;
		}
	}
}
void Dijstra(){
	int i,j,k;
	dis[C1]=0;
	pathcnt[C1]=1;
	pathhel[C1]=hel[C1]; 
	for(i=1;i<=N;i++){
		int imin=maxint;
		for(j=1;j<=N;j++){
			if(!vst[j]&&dis[j]<imin){
				imin=dis[j];
				k=j;
			}
		}
		vst[k]=1;
		for(j=1;j<=N;j++){
			if(vst[j]==0){ 
				if(dis[j]>dis[k]+map[k][j]){
					dis[j]=dis[k]+map[k][j];
					pathhel[j]=pathhel[k]+hel[j];
					pathcnt[j]=pathcnt[k];
				}
				else if(dis[j]==dis[k]+map[k][j]){
					pathcnt[j]+=pathcnt[k];
					if(pathhel[j]<pathhel[k]+hel[j]){
						pathhel[j]=pathhel[k]+hel[j];	
					}
				}	
			}
			
		}
		if(imin==maxint||k==C2) return;
	}

}
int main(){
	int i,j,from,to,dist;
	scanf("%d %d %d %d",&N,&M,&C1,&C2);
	C1++;
	C2++;
	init();
	for(i=1;i<=N;i++){
		scanf("%d",&hel[i]);	
	}
	for(i=1;i<=M;i++){
		scanf("%d %d %d",&from,&to,&dist);
		map[from+1][to+1]=map[to+1][from+1]=dist;
	}
	Dijstra();
	printf("%d %d\n",pathcnt[C2],pathhel[C2]);
	return 0;
}