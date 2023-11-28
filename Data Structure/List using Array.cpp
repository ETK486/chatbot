#include <iostream>
using namespace std;
int main(){
	int opt;
	float arr1[]={12.3,23.4,34.5,45.6,56.7,67.8,78.9};
	int size=sizeof(arr1)/sizeof(float);
	cout<<"Choose an option....."<<endl;
	cout<<"1.Insert at Beginning."<<endl;
	cout<<"2.Insert at End."<<endl;
	cout<<"3.Insert at Given position."<<endl;
	cout<<"4.Remove at a Given position."<<endl;
	cout<<"5.Replace at a Given position."<<endl;
	cout<<"6.Check list is empty or not."<<endl;
	cin>>opt;
	switch(opt){
		case 1:{
			float temp[size+1];
			cout<<"Enter the value to insert"<<endl;
			float data;
			cin>>data;
			temp[0]=data;
			for (int i=0;i<size;i++){
				temp[i+1]=arr1[i];
			}
			for(float j:temp){
				cout<<j<<endl;
			}
			break;
		}
		case 2:{
			float temp1[size+1];
			cout<<"Enter the value to insert"<<endl;
			float data1;
			cin>>data1;
			for (int i=0;i<size;i++){
				temp1[i]=arr1[i];
			}
			temp1[size]=data1;
			for(float j:temp1){
				cout<<j<<endl;
			}
			break;
		}
		case 3:{
			float temp2[size+1];
			cout<<"Enter the value to insert"<<endl;
			float data2;
			int index;
			cin>>data2;
			cout<<"Enter the index value"<<endl;
			cin>>index;
			temp2[index]=data2;
			for (int i=0;i<index;i++){
				temp2[i]=arr1[i];
			}
			for (int i=index;i<size;i++){
				temp2[i+1]=arr1[i];
			}
			for(float j:temp2){
				cout<<j<<endl;
			}
			break;
		}
		case 4:{
			float temp3[size];
			cout<<"Enter the index to remove"<<endl;
			float index1;
			cin>>index1;
			for (int i=0;i<size;i++){
				if (i>=index1){
					temp3[i]=arr1[i+1];
				}
				else{
					temp3[i]=arr1[i];
				}
			}
			for(float j:temp3){
				cout<<j<<endl;
			}
			break;
		}
		case 5:{
			int index2;
			float data2;
			cout<<"Enter the data to change"<<endl;
			cin>>data2;
			cout<<"Enter the index to change"<<endl;
			cin>>index2;
			arr1[index2]=data2;
			for(float j:arr1){
				cout<<j<<endl;
			}
			break;
		}
		case 6:{
			if (arr1[0]!=0){
				cout<<"The Array is not empty"<<endl;
			}
			else{
				cout<<"The Array is empty"<<endl;
			}
			break;
		}
	}
}