#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *right;
	struct node *left;
	node(int val){
		data=val;
		right=NULL;
		left=NULL;
	}
};
//Root Left Right
void preorder(struct node * root){
	if(root==NULL){
		return;
	}
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
	}

//Left Root Right
void inorder(struct node * root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}

//Left Right Root
void postorder(struct node * root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}


int main(){
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	cout<<"Preorder - ";
	preorder(root);
	cout<<endl;
	cout<<"Inorder - ";
	inorder(root);
	cout<<endl;
	cout<<"PostOrder - ";
	postorder(root);
	return 0;
}