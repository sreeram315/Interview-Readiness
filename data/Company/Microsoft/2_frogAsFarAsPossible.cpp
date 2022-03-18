// https://stackoverflow.com/questions/63132225/maximum-distance-two-frogs-can-create-by-starting-at-any-index-in-a-list-in-on]

// Maximum distance two frogs can create by starting at any index in a list in O(n) or less time?

#include<bits/stdc++.h>
using namespace std;

vector<int> getNextDip(vector<int>& arr){
	int n = arr.size();
	vector<int> nextDip(n);
	nextDip[n-1] = n-1;
	for(int i = n-2; i >= 0; i--)
		nextDip[i] = (arr[i]>arr[i+1]) ? i : nextDip[i+1];
	return nextDip;
}

vector<int> getPrevDip(vector<int>& arr){
	int n = arr.size();
	vector<int> prevDip(n);
	prevDip[0] = 0;
	for(int i = 1; i < n; i++)
		prevDip[i] = (arr[i]>arr[i-1]) ? i : prevDip[i-1];
	return prevDip;
}

int main(){
	vector<int> arr = {3,3,3,4,4,5,5,-3,6};
	vector<int> nextDip = getNextDip(arr), prevDip = getPrevDip(arr);
	int ans = 0;
	for(int i = 0; i < arr.size(); i++)
		ans = max(ans, nextDip[i]-prevDip[i]);
	printf("ANS = %d\n\n", ans);
	return 0;
}




