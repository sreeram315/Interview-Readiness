#include<bits/stdc++.h>
using namespace std;

class Queue{
	int capacity, start = 0, end = 0, currSize = 0;
	int *arr;
public:
	Queue(int capacity): capacity(capacity){
		arr = new int[capacity];
	}
	void push(int num){
		if(currSize == capacity){
			printf("Capacity reached.\n");
			return ;
		}
		currSize++;
		int nextIndex = (end+1)%capacity;
		arr[end] = num;
		end = nextIndex;
	}
	void pop(){
		if(currSize == 0){
			printf("No elements.\n");
			return;
		}
		currSize--;
		start = (start+1)%capacity;
	}
	int front(){
		if(currSize == 0){
			printf("No elements.\n");
			return -1;
		}
		return arr[start];
	}
};


int main(){
	Queue q(5);
	q.push(7); q.push(9); q.push(4); q.push(2);  q.push(3); 
	printf("Front: %d\n", q.front()); q.pop(); q.push(33);
	printf("Front: %d\n", q.front()); q.pop(); 
	printf("Front: %d\n", q.front()); q.pop(); 
	printf("Front: %d\n", q.front()); q.pop(); 
	printf("Front: %d\n", q.front()); q.pop(); q.pop(); q.pop(); q.pop(); q.pop(); 


	cout << endl;
}




