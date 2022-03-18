// easy
// https://www.geeksforgeeks.org/find-repeating-element-sorted-array-size-n/

#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,16,17,18,19,20,21,22,23,24,25,26,27,28};
	int n = arr.size(), l = 0, r = n-1;
	while(l < r){
		int mid = (l+r)/2;
		if(arr[l]==l+1 && arr[mid]==mid+1)
			l = mid+1;
		else
			r = mid;
	}
	printf("%d ", l);
}