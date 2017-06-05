#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=30;
int n,a[maxn];

struct node{
	int height,value;
	node* lchild;
	node* rchild;
};

int GetHeight(node* root){
	if(root==NULL) return 0;
	return root->height;
}

void UpdataHeight(node* root){
	// 这里高度也调用GetHeight处理
	root->height=max(GetHeight(root->lchild),GetHeight(root->rchild))+1;
}

int GetBF(node* root){
	return GetHeight(root->lchild) - GetHeight(root->rchild);
}

void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	UpdataHeight(root);
	UpdataHeight(temp);
	root=temp;
}

void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	UpdataHeight(root);
	UpdataHeight(temp);
	root=temp;
}

void Insert(node* &root,int value){
	if(root==NULL){
		node* Node=new node;
	    Node->height=1;
	    Node->value=value;
	    Node->lchild=NULL;
	    Node->rchild=NULL;
		root=Node;
		return;
	}
	if(value<root->value){
		Insert(root->lchild,value);
		UpdataHeight(root);
		if(GetBF(root)==2){
			if(GetBF(root->lchild)==1){
				R(root);
			}
			else if(GetBF(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		Insert(root->rchild,value);
		UpdataHeight(root);
		if(GetBF(root)==-2){
			if(GetBF(root->rchild)==-1){
				L(root);
			}
			// 这里是1不是-1
			else if(GetBF(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	node* root=NULL;
	for(int i=0;i<n;i++){
		Insert(root,a[i]);
	}
	cout<<root->value<<endl;
	return 0;
}