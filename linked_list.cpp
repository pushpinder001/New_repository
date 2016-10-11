#include <iostream>
using namespace std;
class list{
	struct node{
		int val;
		node *next;
	};
	node *head;
	node *create_node(int val);
	node *insert_beg(node* ,int);
	public :
	list(){
		head=NULL;
	}
	void insert(int ,int);
	void print(void);
};
list::node* list::create_node(int val){
	node* temp=new node;
	temp->val=val;
	temp->next=NULL;
	return temp;
}
list::node* list::insert_beg(node *trav,int val){
	node *temp=create_node(val);
	temp->next=trav;
	return temp;
}
void list::insert(int val,int pos){
	if(pos<0)
	{
		cout<<"Node cannot be inserted\n";
	}
	if(pos==0)
	{
		head=insert_beg(head,val);
		return ;
	}
	node *prev,*trav=head;
	while(pos!=0)
	{
		if(trav==NULL)
		{
			cout<<"Node cannot be inserted\n";
			return ;
		}
		prev=trav;
		trav=trav->next;
		pos--;
	}
	prev->next=insert_beg(trav,val);
}
void list::print(void ){
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->val<<' ';
		temp=temp->next;
	}
	cout<<endl;
}
int main() {
	list l1;
	for(int i=1;i<=5;i++){
		l1.insert(i,0);
	}
	l1.print();
	return 0;
}
