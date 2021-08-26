#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};
int search(int inorder[],int start,int end,int cur){
	for(int i=start;i<end;i++)
	{
		if(inorder[i]==cur)
			return i;
	}

	return -1;
}
void printinorder(struct node * root){
	if(root==NULL){
		return;
	}
	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
}
struct node* buildtree(int preorder[],int inorder[],int start,int end){
	static int i=0;
	if(start>end){
		return NULL;
	}
	int cur;
	cur=preorder[i];
	i++;
	node*data=new node(cur);
	if(start==end){
		return data;
	}
	int pos;

	pos=search(inorder,start,end,cur);
	data->left=buildtree(preorder,inorder,start,pos-1);
	data->right=buildtree(preorder,inorder,pos+1,end);
	return data;
}


int main(){
	int preorder[]={1,2,4,5,3};
	int inorder[]={4,2,5,1,3};
	node *root= buildtree(preorder,inorder,0,4);
	//cout<<root;
	printinorder(root);
}