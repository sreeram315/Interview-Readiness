#include<bits/stdc++.h>
using namespace std;

long MOD = 1000000007;
unsigned long getproductOfMaxOfSubsets(vector<int>& arr, int n){
	unsigned long ans = 1UL;
	sort(arr.begin(), arr.end());
	for(int i = n-1; i >= 0; i--){
		int count = pow(2, i);
		for(int c = 0; c < count; c++)
			ans = (ans*arr[i])%MOD;
	}
	return ans;
}


int main(){
	vector<int> arr = {1,2,9,124,5,35,6,4,6,25,6};
	printf("Sum: %lu\n", getproductOfMaxOfSubsets(arr, arr.size()));
}