#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node*left;
	struct Node*right;
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};
int search(int inorder[],int start,int end,int cur){
	for(int i=start;i<=end;i++)
		{if (inorder[i]==cur)
		return i;
		}return -1;
}
void printinorder(struct Node * root){
	if(root==NULL){
		return;
	}
	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
}
struct Node*buildTree(int inorder[],int postorder[],int start,int end){
	if(start>end){
      return NULL;
	}
	static int i=4;
	int cur;
	cur=postorder[i];
	i--;
	Node*root=new Node(cur);
	
	if(start==end){
		return root;
	}
	int pos=search(inorder,start,end,cur);
	root->right=buildTree(inorder,postorder,pos+1,end);
	root->left=buildTree(inorder,postorder,start,pos-1);
	return root;

}

int main()
{
	int postorder[]={4,5,2,3,1};
	int inorder[]={4,2,5,1,3};

	Node*root=buildTree(inorder,postorder,0,4);
	printinorder(root);
	return 0;
}