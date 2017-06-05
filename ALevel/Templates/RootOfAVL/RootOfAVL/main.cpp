//#include <cstdio>
//#define max(a, b) (((a) > (b)) ? (a) : (b))
//struct node {
//    int val;
//    struct node *left, *right;
//};
//node *rotateLeft(node *root) {
//    node *t = root->right;
//    root->right = t->left;
//    t->left = root;
//    return t;
//}
//node *rotateRight(node *root) {
//    node *t = root->left;
//    root->left = t->right;
//    t->right = root;
//    return t;
//}
//node *rotateLeftRight(node *root) {
//    root->left = rotateLeft(root->left);
//    return rotateRight(root);
//}
//node *rotateRightLeft(node *root) {
//    root->right = rotateRight(root->right);
//    return rotateLeft(root);
//}
//int getHeight(node *root) {
//    if(root == NULL) return 0;
//    return max(getHeight(root->left), getHeight(root->right)) + 1;
//}
//node *insert(node *root, int val) {
//    if(root == NULL) {
//        root = new node();
//        root->val = val;
//        root->left = root->right = NULL;
//    } else if(val < root->val) {
//        root->left = insert(root->left, val);
//        if(getHeight(root->left) - getHeight(root->right) == 2)
//            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
//    } else {
//        root->right = insert(root->right, val);
//        if(getHeight(root->left) - getHeight(root->right) == -2)
//            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
//    }
//    return root;
//}
//int main() {
//    int n, val;
//    scanf("%d", &n);
//    node *root = NULL;
//    for(int i = 0; i < n; i++) {
//        scanf("%d", &val);
//        root = insert(root, val);
//    }
//    printf("%d", root->val);
//    return 0;
//}

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
void getNewHeight(node* root) {
    root->height = max(root->left->height, root->right->height) + 1;
}
void L(node*& root) {
    
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    
    getNewHeight(root);
    getNewHeight(temp);
    
    root = temp;
}
void R(node*& root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    getNewHeight(root);
    getNewHeight(temp);
    root = temp;
}
void insert(node*& root, int v) {
    if(root == NULL) {
        root = newNode(v);
        return;
    }
    if(v < root->v) {
        insert(root->left, v);
        getNewHeight(root);
        if((root->left->height) - (root->right->height) == 2) {
            if((root->left->left->height)-(root->left->right->height)==1) {
                R(root);
            } else if((root->left->left->height) - (root->left->right->height) == -1) {
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->right, v);
        getNewHeight(root);
        if((root->left->height) - (root->right->height) == -2) {
            if((root->right->left->height) - (root->right->right->height) == 1) {
                R(root->right);
                L(root);
            } else if((root->right->left->height) - (root->right->right->height) == -1) {
                L(root);
            }
        }
    }
}
// void init() {
//     null = new node;
//     null -> height = 0;
//     root = null;
// }
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

