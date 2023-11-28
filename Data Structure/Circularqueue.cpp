#include <iostream>
using namespace std;
struct node{
	int data;
	node* next;
	node(int data){
		this->data=data;
		next=nullptr;
	}
};
class queue{
	public:
		node* front=nullptr;
		node* rear=nullptr;
		void insert(int data){
			node* newnode=new node(data);
			if (front==NULL){
				front=rear=newnode;
				rear->next=front;
			}
			else{
				rear->next=newnode;
				rear=newnode;
				rear->next=front;
			}
		}
		void remove(){
			if (front==NULL){
				cout<<"Queue Underflow"<<endl;
			}else{
				node* temp=front;
				front=front->next;
				rear->next=front;
				cout<<"The deleted element is "<<temp->data<<endl;
				delete temp;
			}	
		}
		void display(){
			node* current=front;
			do{
				cout<<current->data<<endl;
				current=current->next;
			}while(current!=front);
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