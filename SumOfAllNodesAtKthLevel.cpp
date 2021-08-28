#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node*left;
	struct node*right;
	node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

void level_order_traversal(struct node*root){
	if(root==NULL)
	{
		return ;
	}
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
	
		node*point=q.front();
			q.pop();
		if(point!=NULL){
			cout<<point->data<<" ";
			if(point->left){
				q.push(point->left);
			}
			if(point->right){
				q.push(point->right);
			}
		}
		else if(!q.empty())
			q.push(NULL);
	}
}

int sumnodeKlevel(struct node*root,int k){
	int sum=0,l=0;
	if(root==NULL){
		return 0;
	}
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node*data=q.front();
		q.pop();
		if(data!=NULL){
			if(l==k)
			sum+=data->data;
			if(data->left){
				q.push(data->left);
			}
			if(data->right){
				q.push(data->right);
			}
		}
		else if(!q.empty()){
			q.push(NULL);
			l=l+1;}
		}
		return sum;
}


int main(){
	node*root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	root->right->right=new node(7);
	level_order_traversal(root);
	cout<<endl;
	cout<<"Sum of all nodes at certain level is"<<" ";
	int h=sumnodeKlevel(root,1);
	cout<<h<<endl;
	return 0;
}