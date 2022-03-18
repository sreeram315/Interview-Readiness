#include<bits/stdc++.h>
using namespace std;

#define MOD(N, M) (N-(N/M)*M)


void printBinary(unsigned long num, int bits = 32){
	printf(" %18lu	: ", num);
	int temp = num, c = 0;
	string ans = "";
	while(num){
		ans += (num&1) + '0';
		num >>= 1;
		c++;
		if(c%4==0 && num){
			ans += ' ';
		}
	}
	while(c != bits) {
		if(c%4==0){
			ans += ' ';
		}
		ans += '0';
		c++;
	}
	reverse(ans.begin(), ans.end());
	printf("%s \n", ans.c_str());
}

void swapNibs(unsigned long &num, int bits = 64){
	if(bits >= 64)
		num = ((num & 0x00000000FFFFFFFF)<<32) | ((num & 0xFFFFFFFF00000000)>>32);
	if(bits >= 32)
	num = ((num & 0x0000FFFF0000FFFF)<<16) | ((num & 0xFFFF0000FFFF0000)>>16);
	if(bits >= 16)
	num = ((num & 0x00FF00FF00FF00FF)<<8) |  ((num & 0xFF00FF00FF00FF00)>>8);
	num = ((num & 0x0F0F0F0F0F0F0F0F)<<4) |  ((num & 0xF0F0F0F0F0F0F0F0)>>4);
}

void reverseBits(unsigned int &num, int bits = 32){
	num = ((num & 0x0000FFFF)<<16) | ((num & 0xFFFF0000)>>16);
	num = ((num & 0x00FF00FF)<<8) |  ((num & 0xFF00FF00)>>8);
	num = ((num & 0x0F0F0F0F)<<4) |  ((num & 0xF0F0F0F0)>>4);
	num = ((num & 0x33333333)<<2) |  ((num & 0xCCCCCCCC)>>2);
	num = ((num & 0x55555555)<<1) |  ((num & 0xAAAAAAAA)>>1);
}

void swapNumbers(int &a, int &b){
	if(a==b) return;
	a = a^b;
	b = a^b;
	a = a^b;
}

void rotate3(int& a, int& b, int&c ){
	a = a^b^c;
	b = a^b^c;
	c = a^b^c;
	a = a^b^c;
}

void resetLSSetBit(int& num){
	num = num&(num-1);
}

void getLSSetBit(int& num){
	num = num & ~(num-1);
}

void turnOffKthBit(int& num, int k){
	num = num & ~(1<<k);
}

void turnOnKthBit(int& num, int k){
	num = num | (1<<k);
}

void toggleKthBit(int& num, int k){
	num = num ^ (1<<k);
}

bool isKthSet(int& num, int k){
	return (num&(1<<k));
}

int binaryToGrey(int n) {
    return n ^ (n >> 1);
}

int grayToBinary(int n) {
    int res = 0;
    while(n > 0) {
        res = res ^ n;
        n >>= 1;
    }
    return res;
}

bool isPowerOf2(int num){
	return (num&(num-1))==0;
}

int countSetBits(int num){
	// O(no of 1's)
	int count = 0;
	while(num){
		count++;
		num = num&(num-1);
	}
	return count;
}

int rangeBitwiseAnd(int m, int n) { // AND of all numbers between m and n 
	// logic -> all bits except MSB equal part of m, n become 0.
    int a = 0;
    while(m != n) {
        m >>= 1;
        n >>= 1;
        a++;
    }
    return m<<a; 
}

int MODULUS(int num, int mod){
	return num - (num/mod)*mod;
}

int main(){

	int num = 0x77;
	printf("%x\n", num);
	printBinary(num, 8);

	// int A = 7, B = 10;
	// swapNumbers(A, A);
	// printf("a=%d b=%d\n", A, A);

	/*
	int arr[] = {1, 2};
	printf("%ld \n", (size_t)(arr+1)-(size_t )arr);
	*/

	/*
	unsigned int num = 91284;
	printBinary(num);
	reverseBits(num);
	printBinary(num);
	*/

	/*
	unsigned long num = 3999994687126541298;
	printBinary(num, 64);
	swapNibs(num, 64);
	printBinary(num, 64);
	*/


	/*
	int a = 87124, b, c;
	printBinary(a);
	cout << countSetBits(a) << endl;

	
	printf("%d \n", MOD(19, 7));
	

	
	a = 11; b = 14; c = 93;
	printf("%d %d %d\n", a, b, c);
	rotate3(a, b, c);
	printf("%d %d %d\n", a, b, c);
	

	
	
	

	

	for(int n = 0; n < 20; n++)
		printBinary(n, 8);


	
	*/
	
}