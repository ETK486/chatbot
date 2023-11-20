#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node(int val){
		data=val;
		next=nullptr;
	}
};
class List{
	public:
	node* head=nullptr;
	void insert(int data){
		node* newnode = new node(data);
		newnode->next=head;
		head=newnode;
	}
	void display(){
		node* temp=head;
		while(temp!=nullptr){
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	void remove(int num){
		if (head==nullptr){
			return;
		}
		if (head->data==num){
			node* temp=head;
			head=head->next;
			delete temp;
			return;
		}
		node* current=head;
		while(current->next!=nullptr&&current->next->data!=num){
			current=current->next;
		}
		if (current->next==nullptr){
			return;
		}
		node* t=current;
		current->next=current->next->next;
		delete t;
	}
}l;
int main(){
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(7);
	l.insert(8);
	//l.display();
	//l.remove(5);
	//l.display();
	return 0;
}