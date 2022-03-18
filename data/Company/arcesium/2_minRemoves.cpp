#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int main(){
	vector<int> arr = {5, 1, 3, 2, 6, 7, 4, 4,4,4,4};
	unordered_map<int, int>mp;
	for(int x: arr) mp[x]++;
	vector<pair<int, int>>vals;
	for(pair<int, int>p: mp)
		vals.push_back(p);
	
	sort(vals.begin(), vals.end());
	int i = 0, count = 0;
	while(i<vals.size()){
		int v = vals[i].first;
		i++; count++;
		if(vals[i].first == v+1)
			i++;
	}
	printf("%d ", count);
	cout << endl << endl;
}