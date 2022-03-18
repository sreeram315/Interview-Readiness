#include <iostream>
#include <limits.h>
using namespace std;

int countSubsets(int arr[], int n, int sum) {
	if(n==0)
		return sum==0? 1 : 0;
	return countSubsets(arr, n-1, sum) + 
		   countSubsets(arr, n-1, sum - arr[n-1]);
}

int main() {
	int n = 7, arr[]= {10, 20, 15, 25, 10, 15, 25}, sum = 25;
	cout << countSubsets(arr, n, sum) << endl;
	return 0;
}