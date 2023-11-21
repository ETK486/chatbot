#include <iostream>
using namespace std;
struct node{
	int data;
	struct node* next;
	node(int data){
		this->data=data;
		next=nullptr;
	}
};
class queue{
	public:
		struct node* front=NULL;
		struct node* rear=NULL;
		void insert(int val){
			node* newnode=new node(val);
			if (front==NULL){
				front=rear=newnode;
			}
			else{
				rear->next=newnode;
				rear=newnode;
			}
		}
		void remove(){
			if (front==NULL){
				cout<<"Empty"<<endl;			
			}else{
			struct node* current=front;
			cout<<"The element dequeued is "<<current->data<<endl;
			front=front->next;
			delete current;
			}
		}
		void display(){
			struct node* temp=front;
			while(temp!=NULL){
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
}q;
int main(){
	q.insert(1);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	q.insert(5);
	q.display();
	q.remove();
	q.display();
}