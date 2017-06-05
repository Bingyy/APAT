//
//  main.cpp
//  Simu-B
//
//  Created by Wang Bing on 2017/2/28.
//  Copyright © 2017年 Wang Bing. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 40;

int seq1[maxn],seq2[maxn];

vector<int> post,level;
struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int val)
{
    node* Node = new node;
    Node->left = NULL;
    Node->right = NULL;
    Node->data = val;
    return Node;
}

void insert(node* &root, int x)
{
    if(root == NULL) // 递归边界
    {
        root = newNode(x);
        return;
    }
    
    if(x < root->data)
    {
        insert(root->left, x);
    }
    else
    {
        insert(root->right, x);
    }
}

node* createBST(int data[],int n)
{
    node* root = NULL;
    for(int i = 0; i < n; i++)
    {
        insert(root,data[i]);
    }
    return root;
}

void postOrder(node* root)
{
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

void levelOrder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* top = q.front();
        level.push_back(top->data); // 数据先存储再说
        q.pop();
        if(!top->left) q.push(top->left);
        if(!top->right) q.push(top->right);
    }
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &seq1[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &seq2[i]);
    }
    
    node* root = createBST(seq1,n);
    
    levelOrder(root);
    
    for(int i = 0; i < level.size(); i++)
    {
        printf("%d ", level[i]);
    }
    
    printf("\n");
    return 0;
}
