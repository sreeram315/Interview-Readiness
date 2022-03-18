// https://www.geeksforgeeks.org/length-longest-palindrome-list-linked-list-using-o1-extra-space/
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next, *prev;
	Node(int data):data(data), next(nullptr), prev(nullptr){}
};

void print(Node *head){
	for(Node *ptr = head; ptr!=NULL; ptr = ptr->next)
		printf("%d ", ptr->data);
	printf("\n");
}

int similarPrefixLength(Node *head1, Node *head2){
	int length = 0;
	while(head1 && head2){
		if(head1->data != head2->data)
			return length;
		length += 2;
		head1 = head1->next;
		head2 = head2->next;
	}
	return length;
}

int getLongestPalindromeLength(Node *head){
	if(!head) return 0;
	Node *curr = head, *prev = nullptr;
	int length = 1;
	while(curr){
		Node *nextNode = curr->next;
		curr->next = prev;
		int evenLengthPalindrome 	= similarPrefixLength(curr, nextNode),
			oddLengthPalindrome 	= (nextNode!=nullptr) ? similarPrefixLength(curr, nextNode->next)+1 : 0;
		length = max(length, max(evenLengthPalindrome, oddLengthPalindrome));
		// printf("%d: %d %d\n", curr->data, evenLengthPalindrome, oddLengthPalindrome);
		prev = curr;
		curr = nextNode;
	}
	return length;
}


int main(){
	vector<int> arr = {12, 4, 4, 3, 14};
	Node *head = new Node(arr[0]), *prev = head;
	for(int i = 1; i < arr.size(); i++){
		prev->next = new Node(arr[i]);
		prev 	   = prev->next;
	}
	print(head);
	printf("Longest Palindromic Sublist: %d\n\n", getLongestPalindromeLength(head));
}