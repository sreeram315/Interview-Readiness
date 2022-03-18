// https://www.geeksforgeeks.org/generate-a-string-consisting-of-characters-a-and-b-that-satisfy-the-given-conditions/

// INPUT: A - no. of a's, B - no. of b's
// OUTPUT: Generate stirngs such that any sub-string “aaa” or “bbb” must not occur in str

#include<iostream>
using namespace std;

int main(){
	int A = 1, B = 2;
	string ans = "";
	while(A>0 && B>0){
		if(A>B){
			ans += "aab";
			A -= 2;
			B -= 1;
		}else if (B>A){
			ans += "bba";
			A -= 1;
			B -= 2;
		}else{
			ans += "ab";
			A -= 1;
			B -= 1;
		}
	}
	if(A>2 || B>2){
		printf("Not possible\n\n");
		return 0;
	}
	while(A--) ans += "a";
	while(B--) ans += "b";
	printf("ANS = %s \n\n", ans.c_str());
}