// https://www.geeksforgeeks.org/sum-two-large-numbers/

#include<bits/stdc++.h>
using namespace std;

string getSum(string num1, string num2){
	if(num1.size() < num2.size())
		return getSum(num2, num1);
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int i = 0, j = 0, n1 = num1.size(), n2 = num2.size(), sum, carry = 0, ans = 0;
	while(i<n1 && j<n2){
		int val1 = num1[i++]-'0', val2 = num2[j++]-'0';
		sum  	= (val1+val2+carry)%10;
		carry  	= (val1+val2+carry)/10;
		num1[i-1] = sum+'0';
	}
	while(i<n1){
		int val = num1[i++]-'0';
		sum  	= (val+carry)%10;
		carry  	= (val+carry)/10;
		num1[i-1] = sum+'0';
	}
	if(carry)
		num1.push_back(carry+'0');
	reverse(num1.begin(), num1.end());
	return num1;
}

int main(){
	string str1 = "99", str2 = "98";
	printf("SUM: %s\n\n", getSum(str1, str2).c_str());
	return 0;
}