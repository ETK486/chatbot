#include <iostream>
using namespace std;;
struct node{
	int data;
	node* left;
	node* right;
	node(int data):data(data),left(nullptr),right(nullptr){}
};
class bst{
	public:
		node* root=NULL;
		node* insertnode(node* n,int data){
			node* newnode=new node(data);
			if (n==NULL){
				n=newnode;
			}
			if(data<n->data){
				n->left=insertnode(n->left,data);
			}
			else if(data>n->data){
				n->right=insertnode(n->right,data);
			}
			return n;
		}
		void displaynode(node* node){
			if (node!=NULL){
				displaynode(node->left);
				cout<<node->data<<endl;
				displaynode(node->right);
			}
		}
		void insert(int data){
			root=insertnode(root,data);
		}
		void display(){
			displaynode(root);
		}
}b;
int main(){
	b.insert(1);
	b.insert(2);
	b.insert(3);
	b.insert(4);
	b.display();
}