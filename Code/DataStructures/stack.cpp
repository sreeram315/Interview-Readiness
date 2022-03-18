#include<bits/stdc++.h>
using namespace std;


class Stack{
	int capacity, currIndex = 0;
	int *arr;
public:
	Stack(int capacity): capacity(capacity) {
		arr = new int[capacity];
	}
	void push(int num){
		if(currIndex == capacity){
			printf("Cannot push. Limit reached.\n");
			return;
		}
		arr[currIndex++] = num;
	}
	void pop(){
		if(currIndex == 0){
			printf("Cannot pop. No elements\n");
			return;
		}
		currIndex--;
	}
	int top(){
		if(currIndex == 0){
			printf("Stack Empty. No top\n");
			return -1;
		}
		return arr[currIndex-1];
	}
};

int main(){
	Stack myStack(10);
	myStack.push(5); myStack.push(7); myStack.push(11); 
	printf("Top: %d\n", myStack.top());
	myStack.pop(); myStack.push(97); myStack.pop(); myStack.push(101);
	printf("Top: %d\n", myStack.top());
	myStack.pop(); myStack.pop(); myStack.pop(); 
	cout << endl;
}