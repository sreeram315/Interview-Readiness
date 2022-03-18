// https://www.geeksforgeeks.org/minimum-characters-required-to-be-removed-to-sort-binary-string-in-ascending-order/

#include<bits/stdc++.h>
using namespace std;

int getMinRemoves(const string& str){
	/* Calculate removes if only zeros to be removed (no. of zeros after first one)
						 if ones to be removed.		 (no. of ones before last zero)
					return min of the two.
	*/
	int ones = 0, zeroCount = 0, oneCount, doZeroCount = false;
	for(char ch: str){
		if(ch == '1'){
			ones++;
			doZeroCount = true;
		}
		else if(ch == '0'){
			oneCount = ones;
			if(doZeroCount) zeroCount++;
		}
	}
	printf("%d %d\n", zeroCount, oneCount);
	return min(zeroCount, oneCount);
}

int main(){
	string str = "001111";
	printf("Min Removes To Sort: %d\n\n", getMinRemoves(str));
	return 0;
}