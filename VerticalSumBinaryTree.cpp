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
void VSum(struct node*root,int hd,map<int,int>&m){
	if(root==NULL){
		return;
	}
	VSum(root->left,hd-1,m);
	m[hd]+=root->data;
	VSum(root->right,hd+1,m);

}
void printVSum(struct node*root){
	map<int,int>m;
	map < int, int> :: iterator it;
  
    // populate the map
    VSum(root, 0, m);
  
    // Prints the values stored by VerticalSumUtil()
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ": "
             << it->second << endl;
    }

}

int main(){
	struct node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->right=new node(4);
	root->right->left=new node(5);
	printVSum(root);
	return 0;
}
