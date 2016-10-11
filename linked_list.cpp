#include <iostream>
using namespace std;
struct node{
	int val;
	node *next;
};
node* insert_b(node *head,int val){
	node* temp=new node;
	temp->val=val;
	temp->next=head;
	head=temp;
	return head;
}
node *insert_l(node *head,int val){
	node* temp=new node;
	temp->val=val;
	temp->next=NULL;
	if(head==NULL){
		head=temp;
		return head;
	}
	node *prev,*trav=head;
	while(trav!=NULL)
	{
		prev=trav;
		trav=trav->next;
	}
	prev->next=temp;
	return head;
}
void print(node* head){
	while(head!=NULL)
	{
		cout<<head->val<<' ';
		head=head->next;
	}
	cout<<endl;
}
int main() {
	node* head=NULL;
	for(int i=1;i<=5;i++){
		head=insert_l(head,i);
	}
	print(head);
	return 0;
}
