#include<iostream>
using namespace std;

// next permutation

bool nextPermutation(string& str){
	int n = str.length(), i = n-2, last = n-1;
	while(i>=0 && str[i]>str[i+1])
		i--;
	if(i==-1) return false;
	int mnEl = i+1;
	for(int ind = i+1; ind < n; ind++){
		if(str[ind]>str[i] && str[ind]<str[mnEl])
			mnEl = ind;
	}
	swap(str[i], str[mnEl]);
	reverse(str.begin()+i+1, str.end());
	return true;
}

int main(){
	string str = "534976";
	bool nextExists;
	int count = 2;
	do {
		printf("%s\n", str.c_str());
		nextExists = nextPermutation(str);
	}while(nextExists && count--);
	cout << endl << endl;
}

