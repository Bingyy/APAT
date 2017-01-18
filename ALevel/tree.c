#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}TNode;
void Init(TNode *root)
{
    root = NULL;// 初始化时root为空
}

void InsertNode(TNode *root, int x)
{
    if(root == NULL)
    {
        root = (TNode*) malloc(sizeof(TNode));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        TNode *temp = root;
        //loop to find th correct spot
        while(1)
        {
            if(x == temp->data)
            {
                // cout << "Error";
                break;
            }
            if(x < temp->data)
            {
                if(temp->left != NULL)//如果左边没有空位，就继续往左走
                {
                    temp = temp->left;
                }
                else //如果左边有空位，就在这里安顿
                {
                    TNode *s = (TNode*)malloc(sizeof(TNode));
                    s->data = x;
                    s->left = NULL;
                    s->right = NULL;
                    temp->left = s;
                    break;
                }
            }
            else //否则，x大于当前结点，往右走
            {
                if(temp->right != NULL) 
                {
                    temp = temp->right;
                }
                else
                {
                    TNode *s = (TNode*)malloc(sizeof(TNode));
                    s->data = x;
                    s->left = NULL;
                    s->right = NULL;

                    temp->right = s;
                    break;
                }
            }
        }
    }
}
void PreTraverse(TNode *root)
{
    if(root != NULL) //前序遍历的内容写在判断语句里面！
    {
        // cout << root->data << " ";
        printf("%d ", root->data );
        PreTraverse(root->left);
        PreTraverse(root->right);
    }
    
}
int main()
{
    TNode * root;
    Init(root);//初始化树
    //插入数据：  9 7 1 3 8 2
    InsertNode(root,9);
    InsertNode(root,7);
    InsertNode(root,1);
    InsertNode(root,3);
    InsertNode(root,8);
    InsertNode(root,2);
    InsertNode(root,10);
    InsertNode(root,11);
    
    //遍历
    PreTraverse(root);
    
    return 0;
}