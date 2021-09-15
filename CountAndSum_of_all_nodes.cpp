#include<bits/stdc++.h>.
using namespace std;

struct node{
	int data;
	struct node*left;
	struct node*right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

int CountNodes(node*root){
	if(root==NULL){
		return 0;}
	return CountNodes(root->left)+CountNodes(root->right)+1;
}
int SumNodes(node*root){
		if(root==NULL){
			return 0;}
		
		return SumNodes(root->left)+SumNodes(root->right)+root->data;
}
int HeightNode(node*root){
	if(root==NULL){
		return 0;
	}int lheight=HeightNode(root->left);
	int rheight=HeightNode(root->right);
	return max(lheight,rheight)+1;
}
//int SumNodes(struct node*root)
int main(){
	//int count;
	node*root;
	root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	cout<<CountNodes(root)<<endl;
	cout<<SumNodes(root)<<endl;
	cout<<HeightNode(root)<<endl;
	//cout<<count<<endl;
	return 0;
}
