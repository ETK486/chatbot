#include <iostream>
using namespace std;
struct treenode{
	char data;
	treenode* left;
	treenode* right;
	treenode(char data){
		this->data=data;
		left=nullptr;
		right=nullptr;
	}
};
struct node{
	string data;
	node* next;
	node(string data){
		this->data=data;
		next=nullptr;
	}
};
class stack{
	public:
		node* top=NULL;
		void push(string data){
			node* newnode=new node(data);
			if (top==NULL){
				top=newnode;
			}else{
				newnode->next=top;
				top=newnode;
			}
		}
		void pop(){
			if (top==NULL){
				cout<<"Stack is empty"<<endl;
			}
			node* temp=top;
			top=top->next;
			cout<<temp->data<<endl<<endl<<endl;
			delete temp;
		}
		void display(){
			node* current=top;
			while(current!=NULL){
				cout<<current->data<<endl<<endl;
				current=current->next;
			}
		}
}s;
class expressiontree{
	public:
		bool isoperator(char data){
			if (data=='+'||data=='-'||data=='*'||data=='/'){
				return true;
			}
		}
		treenode* insert(string data){
			for (char c:data){
			treenode* node=new treenode(c);
			if (isoperator(c)){
				node->right=s.pop();
				node->left=s.pop();
			}
			s.push(c);
		}
		return s.pop()
		}
		void display(string* node){
			display(node->left);
			cout<<node->data<<endl;
			display(node->right);
		}
}e;
int main(){
	e.insert("AB+CD*/");
	e.display();
}