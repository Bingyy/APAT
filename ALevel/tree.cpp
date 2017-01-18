#include <iostream>
#include <queue>
using namespace std;

typedef struct Node
{
    int data;
    Node *left;
    Node *right;
}TNode;
queue<TNode*> que;
void Init(TNode * &root)
{
    root = NULL;// 初始化时root为空
}

void InsertNode(TNode * &root, int x)
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
//前序遍历，中序遍历，后序遍历只是改变一下访问结点的次序
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
//研究一下层序遍历，使用一个queue结构,queue是个adapter
void LevelTraverse(TNode *root)
{
    // int last = 0,level = 1;
    //进队
    que.push(root);
    while(!que.empty())
    {
        //队头元素出队
        TNode *p = que.front();
        que.pop();
        // 访问
        cout << p->data << " ";

        if(p->left != NULL) //结点左右孩子进队
        {
            que.push(p->left);
        }
        if(p->right != NULL)
        {
            que.push(p->right);
        }
    }
    
}

int rob(TreeNode* root) {
        //每一层插-1的方法
        queue<TreeNode*> que;
        vector<int> vec;
        vector<int> res;
        que.push(root);
        TreeNode *p = que.front();
        que.pop();
        vec.push_back(p->val);
        while(!que.empty())
        {
            if(p->left != NULL)
            {
                que.push(p->left);
                vec.push_back(p->left->val);
                if(p == root->right)
                {
                    root = root->right;
                    vec.push_back(-1);
                }
            }
            if(p->right != NULL)
            {
                que.push(p->right);
                vec.push_back(p->right->val);
                if(p == root->right)
                {
                    root = root->right;
                    vec.push_back(-1);
                }
            }
        }
        int i = 0;
        for(auto it = vec.begin();it != vec.end(); it++)
        {
            if(*it != -1)
            {
                res[i] +=  *it;
            }
            if(*it == -1)
            {
                i++;
            }
        }
        int oddCount = 0,evenCount = 0;
        for(int j = 0;j <= res.size(); j+=2)
        {
            oddCount += res[j];
        }
        for(int k = 1; k <= res.size(); k+=2)
        {
            oddCount += res[k];
        }
        return max(oddCount, evenCount);
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
    cout << endl;
    // 层序遍历
    LevelTraverse(root);
    cout << endl;
    
    return 0;
}