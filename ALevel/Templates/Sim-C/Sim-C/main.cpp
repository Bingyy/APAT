#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 40;

int in[maxn];
vector<int> layer;

vector<int> pre,post; // 先存再输出也行，但是耗费一点时间

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


void preOrder(node* root)
{
    if(!root) return;
    pre.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root)
{
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    post.push_back(root->data);
}

node* createFromLevelInOrder(vector<int> layer, int inL, int inR)
{
    if(layer.size() == 0) // 如果层序用完了，表示递归边界，可以往回归
    {
        return NULL;
    }
    // 处理当前层的问题
    node* root = newNode(layer[0]);
    int k; //在中序中划分
    for(k = inL; k <= inR; k++)
    {
        if(layer[0] == in[k])
        {
            break; //找到就跳出循环
        }
    }
    
    vector<int> leftLayer; // 左子树层序遍历序列
    vector<int> rightLayer; // 右子树层序遍历序列
    
    for(int i = 1; i < layer.size(); i++) // 遍历当前层序，划分左右存储起来
    {
        bool isLeft = false;
        for(int j = inL; j < k; j++)
        {
            if(layer[i] == in[j])
            {
                isLeft = true;
                break; //确定一个就跳出来，当前是在外层的大循环下
            }
        }
        if(isLeft)
        {
            leftLayer.push_back(layer[i]);
        }
        else
        {
            rightLayer.push_back(layer[i]);
        }
    }
    
    // 尤其需要注意这里需要用root的左右指针去接下一层的构造
    root->left = createFromLevelInOrder(leftLayer,inL, k - 1);
    root->right = createFromLevelInOrder(rightLayer,k + 1, inR);
    
    return root;
}

int main()
{
    int n;
    scanf("%d", &n);
    int temp;
    // 控制输入
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        layer.push_back(temp); //输入层序遍历序列
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]); // 输入中序遍历序列
    }
    
    node* root = createFromLevelInOrder(layer,0,n - 1);
    
    preOrder(root);
    postOrder(root);
    
    // 控制输出
    for(int i = 0; i < pre.size(); i++)
    {
        printf("%d", pre[i]);
        if(i < pre.size() - 1)
        {
            printf(" ");
        }
    }
    
    printf("\n");
    
    for(int i = 0; i < post.size(); i++)
    {
        printf("%d", post[i]);
        if(i < post.size() - 1)
        {
            printf(" ");
        }
    }
    
    printf("\n");
    return 0;
}
