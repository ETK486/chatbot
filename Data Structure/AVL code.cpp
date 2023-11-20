#include <iostream>
using namespace std;
struct avltree{
	int data;
	int height;
	avltree* left;
	avltree* right;
	avltree(int val):data(val),height(1),left(NULL),right(NULL) {}
};
class AVLtree{
	public:
		avltree* root;
		int height(avlnode* t){
			if (t==NULL){
				return 0;
			}
			return t->height;
		}
		int balancefactor(avlnode* t){
			if (t==NULL){
				return 0;
			}
			return height(t->left)-height(t->right);
		}
		void updateheight(avlnode* t){
			if (t!=nullptr){
				t->height=1+max(height(t->left),height(t->right));
			}
		}
};