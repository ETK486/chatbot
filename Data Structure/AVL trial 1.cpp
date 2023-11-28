#include <iostream>
using namespace std;
struct avlnode{
	int data;
	int height;
	avlnode* left;
	avlnode* right;
	avlnode(int data){
		this->data=data;
		height=0;
		left=nullptr;
		right=nullptr;
	}
};
class AVLNode{
	public:
		avlnode* root;
		int height(avlnode* node){
			if (node==NULL){
				return 0;
			}
			return node->height;
		}
		void updateheight(avlnode* node){
			if (node!=NULL){
				node->height=1+max(height(node->left),height(node->right));
			}
		}
		int balance(avlnode* node){
			if (node==NULL){
				return 0;
			}
			int balance=height(node->left)-height(node->right);
			return balance;
		}
		avlnode* rotateright(avlnode* y){
			avlnode* x=y->left;
			avlnode* z=x->right;
			x->right=y;
			y->left=z;
			updateheight(y);
			updateheight(x);
			return x;
		}
		avlnode* rotateleft(avlnode* y){
			avlnode* x=y->right;
			avlnode* z=x->left;
			x->left=y;
			y->right=z;
			updateheight(y);
			updateheight(x);
			return x;
		}
		avlnode* insert(avlnode* node,int data){
			if (node==NULL){
				return new avlnode(data);
			}
			else if(data>node->data){
				node->right=insert(node->right,data);
			}
			else if (data<node->data){
				node->left=insert(node->left,data);
			}
			updateheight(node);
			int bal=balance(node);
			if (bal>1){
				if (data>node->left->data){
					return rotateright(node);
				}
				else{
					node->left=rotateleft(node->left);
					return rotateright(node);	
				}
			}
			if (bal<-1){
				if (data>node->right->data){
					return rotateleft(node);
				}
				else{
					node->left=rotateright(node->left);
					return rotateleft(node);	
				}
			}
			return node;
		}
		void display(avlnode* node){
			if (node!=NULL){
				display(node->left);
				cout<<node->data<<endl;
				display(node->right);
			}
		}
		void insert(int data){
			root=insert(root,data);
		}
		void display(){
			cout<<root->data<<endl;
			display(root);
		}
}a;
int main(){
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.display();
}