#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next, *prev;
	Node(int data):data(data), next(nullptr), prev(nullptr){}
};

class LinkedList{
	Node *head = nullptr, *tail = nullptr;
public:
	LinkedList(){}
	void pushBack(int num){
		if(!head){
			head = new Node(num);
			tail = head;
			return;
		}
		Node *newNode = new Node(num);
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	void pushFront(int num){
		if(!head){
			head = new Node(num);
			tail = head;
			return;
		}
		Node *newNode = new Node(num);
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	void popFront(){
		if(!head) return;
		Node *toBeDeleted = head;
		head = head->next;
		if(head)
			head->prev = nullptr;
		else
			tail = nullptr;
		free(toBeDeleted);
	}
	void popBack(){
		if(!head) return;
		Node *toBeDeleted = tail;
		tail = tail->prev;
		if(tail)
			tail->next = nullptr;
		else
			head = nullptr;
		free(toBeDeleted);
	}
	void deleteNode(Node *toBeDeleted){
		if(!toBeDeleted) return;
		if(toBeDeleted==head) return this->popFront();
		if(toBeDeleted==tail) return this->popBack();
		Node *prev = toBeDeleted->prev;
		prev->next = toBeDeleted->next;
		toBeDeleted->next->prev = prev;
		free(toBeDeleted);
	}
	Node* getKthElement(int k){
		Node *ptr;
		for(ptr = head; ptr && --k; ptr=ptr->next);
		return ptr;
	}
	void print(){
		for(Node *ptr = head; ptr!=NULL; ptr = ptr->next)
			printf("%d ", ptr->data);
		printf("\n");
	}
};

int main2(){
	LinkedList ll;
	ll.pushFront(33); ll.pushBack(2); ll.pushBack(3); ll.pushBack(7); ll.pushBack(11); ll.pushFront(98);
	ll.print();
	ll.popFront(); ll.popFront();
	ll.print();
	Node *ptr = ll.getKthElement(5);
	printf("Got Node: %d\n", ptr ? ptr->data : -1);
	ll.deleteNode(ptr);
	ll.print();
	cout << endl;
	return 0;
}