#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int result[205];
struct Node
{
    int level;//当前节点所在的等级
    int flag;//0没有孩子，1是有孩子
    int father;//父节点
};

int main()
{
    struct Node nodes[205];
    int n,m,i,j;
    int nowNode,nowNodeNumber,childNode;
    int maxLevel=1;
    cin>>n>>m;

    //初始化
    for (i = 0; i <= n; i++)
    {
        nodes[i].level = 0;
        nodes[i].flag = 0;
        nodes[i].father = 0;
    }
    nodes[1].level = 1;

    //输入并保存关系
    while (m--)
    {
        cin>>nowNode;
        cin>>nowNodeNumber;

        if(nowNodeNumber != 0)
        nodes[nowNode].flag = 1;

        while (nowNodeNumber--)
        {
            cin>>childNode;
            //保存自己的父亲是谁
            nodes[childNode].father = nowNode;
        }
    }
    
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            //如果有一个点的父亲标识是自己，那么它就是你的儿子，那么他的等级，应该是你的等级+1
             if(nodes[j].father == i)
             {
                 nodes[j].level = nodes[i].level + 1;
             }
        }
    }

    //查询每一个等级有多少个没有孩子的点，记录在result数组中
    for (i = 1; i <= n; i++)
    {
        if(nodes[i].flag != 1 && nodes[i].level > 0)
            result[nodes[i].level]++;
        //记录最大的等级，用于最后的输出
        if(nodes[i].level > maxLevel)
            maxLevel = nodes[i].level;
    }
    for (i = 1; i < maxLevel; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<result[i];
    
    return 0;  
}