#include <bits/stdc++.h>
using namespace std;

void seg(int arr[],int n){
    int i=-1,j=n;
    while(true) {
        do{i++;}while(arr[i]<0);
        do{j--;}while(arr[j]>=0);
        if(i>=j)return;
        swap(arr[i],arr[j]);
    }
}

int main() {
    int arr[]={13,-12,18,-10};
	int n=sizeof(arr)/sizeof(arr[0]);
	seg(arr,n);
	for(int x:arr)
	    cout << x << " ";
}