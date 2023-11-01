#include <iostream>
#include <string.h>
using namespace std;
class exptree{
	public:
		char array[100];
		char stack[10];
		int top=-1;
		int k=0;
		void root(char val){
			array[0]=val;
		}
		 void exp(char data){
			if (data=='+'||data=='-'||data=='*'||data=='/'){
				if (top==-1){
					cout<<"Stack is empty"<<endl;
				}
				else{
					if(top==0){
						array[2k+1]=stack[top];
						cout<<top<<endl;
						top--;
						k=2k+1;
					}
					else{
							array[2k+2]=stack[top];
							array[2k+1]=stack[top-1];
							cout<<top<<top-1<<endl;
							if (array[2k+1]=='+'||array[2k+1]=='-'||array[2k+1]=='*'||array[2k+1]=='/'){
								k=2k+1;	
							}
							else if (array[2k+2]=='+'||array[2k+2]=='-'||array[2k+2]=='*'||array[2k+2]=='/'){
								k=2k+2;
							}
					}
				}
			}
			else{
				if (top==-1){
					cout<<"Stack is empty"<<endl;
				}
				else{
					++top;
					stack[top]=data;
				}
			}
		} 
}e;
int main(){
	string postfix="AB+";
	string revpostfix;
	for (int i = postfix.length() - 1; i >= 0; i--) {
        revpostfix += postfix[i];
    }
	e.root(revpostfix[0]);
	for (int i=1;i<revpostfix.length();i++){
		e.exp(revpostfix[i]);
	}
}

						