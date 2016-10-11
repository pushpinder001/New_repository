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
node *insert_n(node* head,int val,int pos){
	if(pos<0)
	{
		cout<<"Node cannot be inserted\n";
		return head;
	}
	if(pos==0)
	{
		return insert_b(head,val);
	}
	node *prev,*trav=head;
	while(pos!=0)
	{
		if(trav==NULL)
		{
			cout<<"Node cannot be inserted\n";
			return head;
		}
		prev=trav;
		trav=trav->next;
		pos--;
	}
	prev->next=insert_b(trav,val);
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
	head=insert_n(head,2334,5);
	print(head);
	return 0;
}
