// https://www.geeksforgeeks.org/maximum-even-sum-subsequence-of-length-k/
/*
Given an array arr[] consisting of N positive integers, and an integer K,
the task is to find the maximum possible even sum of any subsequence of size K. 
If it is not possible to find any even sum subsequence of size K, then print -1.
*/
#include<bits/stdc++.h>
using namespace std;

int getSum(vector<int>& arr, int k){
	vector<int>evens, odds;
	for(int x: arr){
		if(x%2) odds.push_back(x);
		else evens.push_back(x);
	}
	sort(evens.begin(), evens.end(), greater<int>());
	sort(odds.begin(), odds.end(), greater<int>());
	int sum = 0, e = 0, o = 0, eSize = evens.size(), oSize = odds.size();
	
	while(k!=0){
		if(k%2==1){
			if(eSize == 0) return -1;
			sum += evens[e++];
			k--;
		}
		else if(e+1 < eSize && o+1 < oSize){
			int evenSum = evens[e]+evens[e+1], oddSum = odds[o]+odds[o+1];
			if(evenSum > oddSum){
				sum += evenSum;
				e += 2;
			}else{
				sum += oddSum;
				o += 2;
			}
			k -= 2;
		}
		else if(e+1 < eSize){
			sum += (evens[e]+evens[e+1]);
			e += 2;
			k -= 2;
		}
		else if(o+1 < oSize){
			sum += (odds[o]+odds[o+1]);
			o += 2;
			k -= 2;
		}
	}

	return sum;
}

int main(){
	vector<int> arr = {4, 2, 6, 7, 8};
	int k = 3;
	printf("MAX EVEN SUM (K=%d) Elements: %d\n\n", k, getSum(arr, k));
}