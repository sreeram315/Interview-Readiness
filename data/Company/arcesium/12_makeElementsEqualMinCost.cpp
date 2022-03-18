/* https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> arr = {1,4,5,6,8,9,3,2,5,4,7,2,3,5,7,523,12,4,24,63,745,34,352,4,3,9,4,13,6,13,214,25,23,523,23,63,6,36,326,36,3,6};
	int n 		= arr.size();
	nth_element(arr.begin(), arr.begin()+n/2, arr.end());
	int m1 = arr[n/2], m2 = -1;
	if(n%2==0){
		nth_element(arr.begin(), arr.begin()+n/2+1, arr.end());
		m2 = arr[n/2-1];
	}
	float median = n%2 ? (float)m1 : (float)(m1+m2)/2, ans = 0;
	printf("Median: %f\n", median);
	for(int x: arr)
		ans += (float)abs(median-(float)x);
	printf("ANS: %f\n", ans);
}