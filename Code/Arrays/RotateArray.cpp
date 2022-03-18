#include<bits/stdc++.h>
using namespace std;


void rotateArr(int arr[], int d, int n){
    rotate(arr, arr+d, arr+n);
    rotate(arr+d, arr+n, arr+n);
    rotate(arr, arr+n, arr+n);
}
