//
//  main.cpp
//  PostInOrder.cpp
//
//  Created by Wang Bing on 2017/2/19.
//  Copyright © 2017年 Wang Bing. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

// 后序+中序遍历构造一棵树，输出层序遍历序列
vector<int> post;
vector<int> in;

struct node
{
    int data;
    node* left = NULL;
    node* right = NULL;
};

node* newNode(int val)
{
    node* Node = new node;
    Node->data = val;
    return Node;
}

node* createFromPostInOrder(int postL, int postR, int inL, int inR)
{
    // 递归边界
    if(postL > postR)
    {
        return NULL;
    }
    
    // 处理当前层次的问题
    node* root = new node;
    root->data = post[postR];
    
    // k为中序序列中根的下标
    int k,numLeft;
    for(k = inL; k <= inR; k++)
    {
        if(in[k] == post[postR])
        {
            break;
        }
    }
    
    numLeft = k - inL;
    
    // 递归式
    
    root->left = createFromPostInOrder(postL,postL + numLeft - 1, inL,k - 1);
    root->right = createFromPostInOrder(postL + numLeft, postR - 1, k + 1, inR);
    
    return root;
    
}

void preTraverse(node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preTraverse(root->left);
    preTraverse(root->right);
}

int main()
{
    int num,temp;
    scanf("%d", &num);
    // 输入后序，中序序列
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        in.push_back(temp);
    }
    
    node* root = createFromPostInOrder(0,num - 1,0,num - 1);
    
    preTraverse(root);
    
    // printf("%d\n", post[]);
    return 0;
}
