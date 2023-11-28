#include <iostream>
using namespace std;
class queue{
	public:
		int queue;
		int front,rear,capacity;	
		queue(int size){
			capacity=size;
			front=rear=-1;
			queue=new queue[capacity];
		}
		bool isEmpty(){
			return front=-1;
		}
		bool isFull(){
			return (rear+1)%capacity==front;
		}
		void enqueue(int data){
			if (isFull()){
				cout<<"The queue is overflow"<<endl;
			}
			if (isEmpty()){
				front=rear=0;
			}
			else{
				rear=(rear+1)%capacity;
			}
		}
}