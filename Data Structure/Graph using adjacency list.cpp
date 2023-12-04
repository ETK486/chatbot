#include <iostream>
using namespace std;
class Node{
	public:
		int node;
		Node* next;
		Node(int node){
			this->node=node;
			next=nullptr;
		}
};
class linkedlist{
	public:
		Node* head;
		linkedlist(){
			head=nullptr;
		}
		void insert(int value){
			Node* newnode=new Node(value);
			newnode->next=head;
			head=newnode;
		}
};
class graph{
	public:
		int vertices;
		linkedlist* adjlist;
		graph(int vertices){
			this->vertices=vertices;
			adjlist=new linkedlist[vertices];
		}
		void addedge(int from,int to){
			adjlist[from].insert(to);
			adjlist[to].insert(from);
		}
		void display(){
			for(int i=0;i<vertices;i++){
				cout<<"Vertex "<<i<<" : ";
				Node* current=adjlist[i].head;
				while(current){
					cout<<current->node<<" -> ";
					current=current->next;
				}
				cout<<endl;
			}
		}
};
int main(){
	int v=4;
	graph g(v);
	g.addedge(0,1);
	g.addedge(1,3);
	g.addedge(1,2);
	g.addedge(2,1);
	g.display();
}