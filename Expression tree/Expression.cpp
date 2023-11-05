#include <iostream>
#include <string.h>
using namespace std;

class exptree {
public:
    char array[100];
    char stack[10];
    int top = -1, k = 0;

    void root(char val) {
        array[0] = val;
    }

    void exp(char data) {
        if (data == '+' || data == '-' || data == '*' || data == '/') {
            if (top == -1) {
                cout << "Stack is empty" << endl;
                return;
            }
            else {
                if (top == 0) {
                    array[2 * k + 1]=data;
                    array[2 * k + 2] = stack[top];
                    top--;
                    k = 2 * k + 1;
                }
                else {
                    array[2 * k + 1]=data;
                    array[2 * k + 3] = stack[top];
                    array[2 * k + 2] = stack[top - 1];
                    if (array[2 * k + 1] == '+' || array[2 * k + 1] == '-' || array[2 * k + 1] == '*' || array[2 * k + 1] == '/') {
                        k = 2 * k + 1;
                    }
                    else if (array[2 * k + 2] == '+' || array[2 * k + 2] == '-' || array[2 * k + 2] == '*' || array[2 * k + 2] == '/') {
                        k = 2 * k + 2;
                    }
                    top -= 2;
                }
            }
        }
        else if(data == '?'){
            array[2 * k + 2] = stack[top];
            array[2 * k + 1] = stack[top - 1];
        }
        else {
            if (top == 9) {
                cout << "Stack is full" << endl;
                return;
            }
            else {
                top ++;
                stack[top] = data;
            }
        }
    }
    void display() {
        for (int i=0;i<100;i++){
            /*if (array[i] == '\0') {
                continue;
            }*/
            //else{
                cout << array[i] << " ";
            //}
        }
    }
};

int main() {
    string postfix = "?AB/C*D*E+";
    string revpostfix(postfix.rbegin(), postfix.rend());
    exptree e;
    e.root(revpostfix[0]);
    for (int i = 1; i < postfix.length()-1; i++) {
        e.exp(revpostfix[i]);
    }
    e.display();
    return 0;
}

