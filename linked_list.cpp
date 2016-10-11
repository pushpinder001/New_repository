#include <iostream>
using namespace std;
class list{
	struct node{
		int val;
		node *next;
	};
	node *head;
	node *del_beg(node*);
	node *create_node(int val);
	node *insert_beg(node* ,int);
	node *get_middle(node* );
	node *merge(node *,node *);
	node *merge_sort(node *);
public :
	list(){
		head=NULL;
	}
	int get(void)
	{
		return get_middle(head)->val;
	}
	void sort(void);
	void insert(int ,int);
	void del(int);
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
list::node* list::del_beg(node* trav){
	if(trav==NULL)
	{
		cout<<"Node cannot be deleted\n";
		return trav;
	}
	node *temp=trav->next;
	delete trav;
	return temp;
}
void list::sort(void)
{
	head=merge_sort(head);
}
list::node* list::get_middle(node *trav){
	if(trav==NULL)
		return trav;
	node *slow=trav,*fast=trav;
	while(fast->next!=NULL&&fast->next->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
list::node* list::merge(node *n1,node *n2){
	node *dummy=new node,*cur=dummy;
	while(n1!=NULL&&n2!=NULL){
		if(n1->val<=n2->val){
			cur->next=n1;
			cur=cur->next;
			n1=n1->next;
		}
		else{
			cur->next=n2;
			cur=cur->next;
			n2=n2->next;	
		}
	}
	if(n1!=NULL)
		cur->next=n1;
	else if(n2!=NULL)
		cur->next=n2;
	cur=dummy->next;
	delete dummy;
	return cur;
}
list::node* list::merge_sort(node* n1){
	if(n1==NULL||n1->next==NULL)
		return n1;
	node *mid=get_middle(n1);
	node* sh=mid->next;
	mid->next=NULL;
	return merge(merge_sort(n1),merge_sort(sh));
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

void list::del(int pos){
	if(pos==0)
	{
		head=del_beg(head);
		return ;
	}
	node *prev,*trav=head;
	while(pos!=0)
	{
		if(trav==NULL)
		{
			cout<<"Node cannot be deleted\n";
			return;
		}
		prev=trav;
		trav=trav->next;
		pos--;
	}
	prev->next=del_beg(trav);
	return;
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
	l1.sort();
	//l1.del(2);
	//cout<<l1.get()<<endl;
	l1.print();
	return 0;
}
