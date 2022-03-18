// https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr = {4, 5, 0, -2, -3, 1};
	unordered_map<int, int>mp;
	int sum = 0, ans = 0, k = 5;
	for(int x: arr){
		sum += x;
		int rem = ((sum%k)+k)%k; // mod could be negative. so two mods
		ans += mp[rem];
		mp[rem]++;
		if(rem == 0) ans++;
	}
	printf("ANS: %d\n", ans);
}

