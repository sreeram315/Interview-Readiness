#include<iostream>
#include<queue>
using namespace std;

class Semaphore{
	int count;
	queue<int>processQueue;
public:
	Semaphore(int maxAllowed): count(maxAllowed){}
	void down(int id){
		if(count>0){
			printf("Allowed %d\n", id);
		}
		else{
			printf("Sleeping %d\n", id);
			processQueue.push(id);
		}
		count--;
	}
	void up(){
		if(count<0){
			printf("Waking up %d\n", processQueue.front());
			processQueue.pop();
		}
		count++;
	}
};

int main(){
	Semaphore s1(2);
	s1.down(1);
	s1.down(2);
	s1.down(3);
	s1.down(4);
	s1.up();
	s1.down(5);
}