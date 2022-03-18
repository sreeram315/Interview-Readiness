// https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/


// C++ program to find the smallest positive value that cannot be
// represented as sum of subsets of a given sorted array
#include <bits/stdc++.h>
using namespace std;


int findSmallest(int arr[], int n) {
	/*
	at each step we know we can make subsets of 0 tp res-1, (next we need to make res)
	if next element is anything between 0 to res, it can be pair up with nums from
	0 to res-1, ans sum can be formed.
	but if it more than res -> res cannot be formed

	*/
	int res = 1; 
	for (int i = 0; i < n && arr[i] <= res; i++)
		res = res + arr[i];
	return res;
}

int main()
{
int arr1[] = {1, 3, 4, 5};
int n1 = sizeof(arr1)/sizeof(arr1[0]);
cout << findSmallest(arr1, n1) << endl;

int arr2[] = {1, 2, 6, 10, 11, 15};
int n2 = sizeof(arr2)/sizeof(arr2[0]);
cout << findSmallest(arr2, n2) << endl;

int arr3[] = {1, 1, 1, 1};
int n3 = sizeof(arr3)/sizeof(arr3[0]);
cout << findSmallest(arr3, n3) << endl;

int arr4[] = {1, 1, 3, 4};
int n4 = sizeof(arr4)/sizeof(arr4[0]);
cout << findSmallest(arr4, n4) << endl;

return 0;
}



