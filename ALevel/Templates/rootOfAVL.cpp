#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int v, height;
    node *left, *right;
};

node* newNode(int v) {
    node* t = new node;
    t->v = v;
    t->height = 1;
    t->left = t->right = NULL;
    return t;
}
int getHeight(node* root)
{
	// 注意判断空树时的情况
	if(root == NULL)
	{
		return 0;
	}
	return root->height;
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
void L(node* &root) {

    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    updateHeight(root);
    updateHeight(temp);

    root = temp;
}
void R(node* &root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
int getBalanceFactor(node* root)
{
	return getHeight(root->left) - getHeight(root->right);
}
void insert(node* &root, int v) {
    if(root == NULL) {
        root = newNode(v);
        return;
    }
    if(v < root->v) 
    {
        insert(root->left, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2) 
        {
            if(getBalanceFactor(root->left)==1) {
                R(root);
            } else if(getBalanceFactor(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    } 
    else 
    {
        insert(root->right, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) 
        {
            if(getBalanceFactor(root->right) == 1) 
            {
                R(root->right);
                L(root);
            } else if(getBalanceFactor(root->right) == -1) 
            {
                L(root);
            }
        }
    }
}

int main() {
    // init();
    node* root = NULL;
    int n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d\n", root->v);
    return 0;
}
