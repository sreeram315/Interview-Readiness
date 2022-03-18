#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
#include <deque>
using namespace std;

const int n = 4;

void trans(vector<vector<int> >& m, int n){
   	for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j<i) continue;
            if(j>i) swap(m[i][j], m[j][i]);
        }
    }
}
    
void swap_rows(vector<vector<int>> & m, int n){
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n; j++){
            swap(m[n-i-1][j], m[i][j]);
        }
    }
}

void rotateby90(vector<vector<int> >& m, int n) 
{ 
    trans(m, n);
    swap_rows(m, n);
} 

int main() {	
	vector<vector<int>>arr = {{1, 2, 3, 4},
				    {5, 6, 7, 8},
				    {9, 10, 11, 12},
				    {13, 14, 15, 16}};
	rotateby90(arr, 4);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}	
	return 0;
}