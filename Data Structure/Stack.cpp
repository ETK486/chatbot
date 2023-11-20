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
class stack{
	public:
		node* top=NULL;
		void push(int value){
			node* newnode=new node(value);
				newnode->next=top;
				top=newnode;
		}
		void display(){
			node* current=top;
			while(current!=NULL){
				cout<<current->data<<endl;
				current=current->next;
			}
		}
		void pop(){
			node* temp=top;
			if (temp==NULL){
				cout<<"Empty"<<endl;
			}
			top=top->next;
			delete temp;
		}
}s;
int main(){
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display();
	s.pop();
	s.display();
	return 0;
}