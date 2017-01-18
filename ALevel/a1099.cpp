#include<cstdio>
#include<cstring> 
// a positive integer N (<=100) 
int num=0,node[100][3]={{0,0,0}},keys[100]={0},keyloc=0;
void levelprint()
{
     int level[100]={0},start=0,len=0;
     level[start]=0,len++;
     while(len)
     {
         if(node[level[start]][1]!=-1)//左子树
             level[start+len]=node[level[start]][1],len++;
         if(node[level[start]][2]!=-1)//左子树
             level[start+len]=node[level[start]][2],len++;
             
         if(start) printf(" ");
         printf("%d",node[level[start]][0]);
         start++,len--;
     }
     
}
void inorder(int rootloc)
{
     if(node[rootloc][1]!=-1)//左子树
         inorder(node[rootloc][1]);
     node[rootloc][0]=keys[keyloc],keyloc++;  //本节点 
    // printf("\n %d  %d  %d  %d",rootloc,node[rootloc][0],node[rootloc][1],node[rootloc][2]);
     if(node[rootloc][2]!=-1)//右子树
         inorder(node[rootloc][2]);
}
void keyssort()
{
     for(int i=1;i<num;i++)
     {
             int key=keys[i],loc=i-1;
             for(;loc>=0;loc--) if(keys[loc]<=key) break;
             loc++;
             for(int j=i;j>loc;j--) keys[j]=keys[j-1];
             keys[loc]=key;
     }
}
int main()
{    
   scanf("%d",&num);
   for(int i=0;i<num;i++) scanf("%d%d",&node[i][1],&node[i][2]);
   for(int i=0;i<num;i++) scanf("%d",keys+i);   
   keyssort();//keys排序 升序
   inorder(0);//中序遍历，keys归位
   levelprint();//层序输出     
   return 0;
}