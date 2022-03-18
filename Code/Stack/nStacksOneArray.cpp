// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
#include<bits/stdc++.h>
using namespace std;

class NStack{
	int nStacks, capacity, free = 0;
	vector<int>arr, top, next;
public:
	NStack(int nStacks, int capacity): nStacks(nStacks), capacity(capacity){
		arr.resize(capacity);
		next.resize(capacity);
		for(int i = 0; i < capacity-1; i++)
			next[i] = (i+1);
		next[capacity-1] = -1;
		top.resize(nStacks, -1);
	}
	void push(int stackId, int value){
		if(free == -1){
			printf("Stack overflow. No Space");
			return;
		}
		int index = free;
		free = next[free];
		arr[index] = value;
		next[index] = top[stackId];
		top[stackId] = index;
	}
	void pop(int stackId){
		if(top[stackId] == -1){
			printf("Stack is empty\n");
			return;
		}
		int value = arr[top[stackId]], index = top[stackId];
		next[index] = free;
		free = index;
		top[stackId] = next[index];
	}
	int getTop(int stackId){
		if(top[stackId] == -1){
			printf("Stack(%d) is empty.\n", stackId);
			return -1;
		}
		return arr[top[stackId]];
	}
};


int main(){
	NStack myStack(3, 30);
	// myStack.push(1, 3);
	// myStack.push(1, 4);
	// myStack.push(1, 5);
	// myStack.push(1, 3);
	// myStack.push(2, 4);
	// myStack.push(1, 5);
	// myStack.push(2, 3);
	// myStack.push(0, 4);
	// myStack.push(0, 7);
	printf("Stack(%d) top: %d\n", 0, myStack.getTop(0));
	printf("Stack(%d) top: %d\n", 1, myStack.getTop(1));
	printf("Stack(%d) top: %d\n", 2, myStack.getTop(2));

	cout << endl;
}














