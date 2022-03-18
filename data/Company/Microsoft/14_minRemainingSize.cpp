// https://www.geeksforgeeks.org/minimize-remaining-array-sizes-by-removing-equal-pairs-of-first-array-elements/

#include<bits/stdc++.h>
using namespace std;


int getMinRemoves(vector<int> arr1, vector<int> arr2){
	int ones = 0, zeros = 0;
	for(int x: arr1)
		if(x) ones++; else zeros++;
	int n = arr2.size();
	for(int i = 0; i < n; i++){
		if(arr2[i]==1){
			if(ones) ones--;
			else return (n-i);
		}else{
			if(zeros) zeros--;
			else return (n-i);
		}
	}
	return 0;
}

int main(){
	vector<int> arr1 = {1, 1, 0, 0}, arr2 = {0, 0, 0, 1};
	printf("MIN REMOVES: %d\n\n", getMinRemoves(arr1, arr2));
}