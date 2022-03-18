#include<bits/stdc++.h>
using namespace std;


void printSubSequences(string& str, string& temp, int i = 0){
	int n = str.size();
	if(i==n){
		cout << temp << " "; return;
	}
	temp.push_back(str[i]);
	printSubSequences(str, temp, i+1);
	temp.pop_back();
	printSubSequences(str, temp, i+1);
}

int main(){
	string str = "abc", temp;
	printSubSequences(str, temp);
	cout << endl;
}