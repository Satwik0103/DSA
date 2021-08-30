#include<bits/stdc++.h>
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
int calcHeight(struct node *root){
	if(root==NULL){
		return 0;
	}

	return max(calcHeight(root->left),calcHeight(root->right))+1;
}
//Complexity o(N)
int optimCalcDiameter(struct node*root,int *height){
	if(root==NULL){
		*height=0;
		return 0;
	}
	int lh=0,rh=0;
	int ldiam=optimCalcDiameter(root->left,&lh);
	int rdiam=optimCalcDiameter(root->right,&rh);
	int curDiameter=lh+rh+1;
	*height=max(lh,rh)+1;
	return max(curDiameter,max(ldiam,rdiam));
}
//Complexity o(n^2)
int calculateDiameter(struct node*root){
	if(root==NULL){
		return 0;
	}
	int lheight=calcHeight(root->left);
	int rheight=calcHeight(root->right);
	int calcdiameter=lheight+rheight+1;
	int ldiameter=calculateDiameter(root->left);
	int rdiameter=calculateDiameter(root->right);
	return max(calcdiameter,max(ldiameter,rdiameter));
}



int main(){
	struct node*root;
	root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	cout<<calculateDiameter(root)<<endl;
	int heights=0;
	cout<<"Optimal-";
	cout<<optimCalcDiameter(root,&heights)<<endl;

	return 0;
}