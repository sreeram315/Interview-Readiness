#include<bits/stdc++.h>
using namespace std;

/*
When two person passes through the tunnel at a time, then the cost is Y.
(sum of heights cannot be more than maxHeight)
When one person passes through the tunnel at a time, then the cost is X.
*/


int main(){
	vector<int> arr = {1, 3, 4, 4, 2}; // heights
	int onePersonCost = 4, twoPersonCost = 6, maxHeight = 9, n = arr.size();
	sort(arr.begin(), arr.end());
	int i = 0, j = n-1, cost = 0;
	while(i<=j){
		if(i==j || arr[i]+arr[j] >= maxHeight){
			cost += onePersonCost; j--;
		}else{
			cost += twoPersonCost; i++; j--;
		}
	}
	printf("Cost: %d\n", cost);
}


