#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*next;
	node(int val){
		data=val;
		next=NULL;
	}
};
void middle(struct node*head){
	node*slow=head;
	node*fast=head;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<slow->data;
}
int main(){
	struct node*head=new node(1);
	head->next=new node(2);
	head->next->next=new node(3);
	head->next->next->next=new node(4);
	head->next->next->next->next=new node(5);
	head->next->next->next->next->next=new node(6);
	head->next->next->next->next->next->next=new node(7);
	middle(head);

	return 0;
}