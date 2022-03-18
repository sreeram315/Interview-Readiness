// C++ program to find the maximum sum
// after rearranging the array for K range queries
// https://www.geeksforgeeks.org/maximum-sum-after-rearranging-the-array-for-k-queries/

#include <bits/stdc++.h>
using namespace std;


int maxSumArrangement(int A[], int R[][2], int N, int M){
	vector<int>count(N);
	for (int i = 0; i < M; ++i) {
		int l = R[i][0], r = R[i][1] + 1;
		l--;	// if indexing was given for 1-index change to 0-index
		r--;
		count[l]++;
		if (r < N)
			count[r]--;
	}
	for (int i = 1; i < N; ++i)
		count[i] += count[i - 1];

	int ans = 0;
	sort(count.begin(), count.end());
	sort(A, A + N);

	for (int i = N - 1; i >= 0; --i) 
		ans += A[i] * count[i];

	return ans;
}

int main() {
	int A[] 	= { 2, 6, 10, 1, 5, 6 };
	int R[][2] 	= { { 1, 3 }, { 4, 6 }, { 3, 4 } };
	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(R) / sizeof(R[0]);
	cout << maxSumArrangement(A, R, N, M) <<endl;
	return 0;
}

