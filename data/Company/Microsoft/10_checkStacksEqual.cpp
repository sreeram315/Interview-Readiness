#include<bits/stdc++.h>
using namespace std;

// Follow up - how to do without extra space ?
// it will take O(n^2) time tho.

bool areEqualStacks(stack<int>& st1, stack<int>& st2){
	stack<int> dummy;
	while(!st1.empty() && !st2.empty()){
		if(st1.top() != st2.top())
			break;
		dummy.push(st1.top());
		st1.pop();
		st2.pop();
	}
	bool ans = st1.empty() && st2.empty();
	while(!dummy.empty()){
		st1.push(dummy.top());
		st2.push(dummy.top());
		dummy.pop();
	}
	return ans;
}


int main(){
	stack<int>st1, st2;
	st1.push(5); st1.push(3); st1.push(7); st1.push(9); st1.push(3);
	st2.push(5); st2.push(3); st2.push(7); st2.push(9);	st2.push(3);
	if(areEqualStacks(st1, st2))
		printf("EQUAL\n\n");
	else
		printf("NOT EQUAL\n\n");
	return 0;
}