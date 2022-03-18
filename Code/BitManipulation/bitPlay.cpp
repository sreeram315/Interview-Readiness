#include<bits/stdc++.h>
using namespace std;

// 1. Find Modulus using Macro
#define MOD(N, M) (N-(N/M)*M)

// 2. Find size of element using macro
// Find the starting location of current element and next element and find the difference
// gives size of element.
#define SIZEOF(object) (char *)(&object+1) - (char *)(&object)

void rotateNibs(unsigned long &num){
	// 3. rotate nibbles (4 bits) in a 64 bit number
	num = ((num & 0x0000FFFF0000FFFF)<<16) | ((num & 0xFFFF0000FFFF0000)>>16);
	num = ((num & 0x00FF00FF00FF00FF)<<8) |  ((num & 0xFF00FF00FF00FF00)>>8);
	num = ((num & 0x0F0F0F0F0F0F0F0F)<<4) |  ((num & 0xF0F0F0F0F0F0F0F0)>>4);
}

void reverseBits(unsigned long &num){
	// 4. reverse bits in a 32 bit number, same like reverse nibbles but extended till single bits swaps
	// modification: swap even and odd bits ?
	num = ((num & 0x0000FFFF)<<16) | ((num & 0xFFFF0000)>>16); // swap first 16 and last 16
	num = ((num & 0x00FF00FF)<<8) |  ((num & 0xFF00FF00)>>8);  // swap adjacent 8 bits
	num = ((num & 0x0F0F0F0F)<<4) |  ((num & 0xF0F0F0F0)>>4);
	num = ((num & 0x33333333)<<2) |  ((num & 0xCCCCCCCC)>>2);
	num = ((num & 0x55555555)<<1) |  ((num & 0xAAAAAAAA)>>1); // only this line to swap even and odd bits
}

void swapNumbers(int &a, int &b){
	// 5. swapping two numbers using XOR operation. (know a^a^b = b)
	if(a==b) return;
	a = a^b;		// a becomes (a^b)
	b = a^b;		// b becomes (a^b) = ((a^b)^b) = a  -> a substituted as previous line
	a = a^b;		// a becomes (a^b) = ((a^b)^a) = b  -> a, b substitutes as previous two lines
}

void rotate3(int& a, int& b, int&c ){
	// 6. rotating three numbers using XOR operation.
	a = a^b^c;		// similar to above
	b = a^b^c;
	c = a^b^c;
	a = a^b^c;
}

void resetLSSetBit(int& num){
	// 7. Reset(make 0) the Least Significant Set(1) bit
	/*
	 011101111000					-> input
	         ^ is LSB
	 taking off 1 makes it
	 011101111000 - 1 = 
	 011101110111 	
	 011101110000 -> Logical AND above two -> output
	 finally made LSB Set(1) to 0
	*/
	num = num&(num-1);	
}

int getLSSetBit(int& num){
	// 8. Return position of Least Significant Set(1) bit
	/*
	011101111000 (num)
	011101111000 - 1 =  011101110111(num-1) 			-> want to make everything else zero except LSB set bit
	~(011101110111) = 100010001000	~(num-1)

	ANDING 
	011101111000	(num)
	100010001000	~(num-1)
=	000000001000 -> only LSB set bit of input is set now	
	*/
	return num & ~(num-1);
}

void turnOffKthBit(int& num, int k){
	// 9. Make kth bit ZERO
	/* Turn off 2th bit
		1100110		(to make 2th bit 0, need to AND it with zero and rest and with 0(leave as is) i.e. 1111011)
					(put 1 at kth position (1<<k) and flip all bits)
		1100110	(num)
		0000100 (1<<k)
		1111011 ~(1<<k)
		AND num and ~(1<<k)
	  = 1100010
	*/
	num = num & ~(1<<k);
}

void turnOnKthBit(int& num, int k){
	// 10. Make kth bit ONE
	/* Turn on 2th bit
		1100010		(to make 2th bit 1, need to OR it with 1 and rest and with 0(leave as is) i.e. 0000100)
					(put 1 at kth position (1<<k) and flip all bits)
		1100010	(num)
		0000100 (1<<k)
		OR num and ~(1<<k)
	  = 1100110
	*/
	num = num | (1<<k);
}

void toggleKthBit(int& num, int k){
	// 11. Toggles -> make zero if it is one, make one if it is zero
	/*
		XOR is useful to toggle. Any bit XOR with 1 toggles it
		1^1 = 0
		0^1 = 1
		So put a 1 ar kth positiona and XOR it. (rest will be zero, xor with zero means no change 0^0=0, 1^0=1)
		1100010 INPUT
		0000100 (1<<k) k=2
		1100110 (2th bit toggle)
	*/
	num = num ^ (1<<k);
}

bool isKthSet(int& num, int k){
	// 12. return true if kth bit is 1, else return false;
	return (num&(1<<k));
}

int binaryToGrey(int n) {
	// 13. adjacent bit xoring converts binary to grey
    return n ^ (n >> 1);
}

int grayToBinary(int n) {
	// 14. xoring with previous resultant bit converts grey to binary
    int res = 0;
    while(n > 0) {
        res = res ^ n;
        n >>= 1;
    }
    return res;
}

bool isPowerOf2(int num){
	// 15. Check if given nnumber is power of 2 (i.e. 2, 4, 8, 16, 32, 64, 128...)
	/*
		int power of 2, only one bit is set 2(10), 4(100), 8(100), 16(1000) ... 
		So using ont of above functions to reset the LSB set bit, and check if produced number is zero or not
		16 = 10000
		after reseting LSB set bit num = 0000 , so it is power of 2; 
	*/
	return (num&(num-1))==0;
}

int countSetBits(int num){
	// 16. Return number of 1's in binary format of given number
	/*
		bruteforce takes O(n) time n = number of bits in total
		instead keep resetting the LSB set bit till the number becomes zero,
		-> complexity = O(no. of set bits)
	*/
	int count = 0;
	while(num){
		count++;
		num = num&(num-1);
	}
	return count;
}

int posOfRightMostDiffBit(int m, int n){
	// 17. Giving two numbers, give the position where they differ first LSB
	/*
		101101100 = m (364)
		111001100 = n (460)
		   ^ -> first different bit from right
		XORing two numbers gives ones(1) where bits are different and zeros(0) where bits are same (1^0 = 0^1 = 1 | 1^1 = 0^0 = 0)
		m^n
	  = 010100000 (now simply find LSB set bit like we seen in function. 8)
	  log2() is to get position numer log2(0010000) = 4 (4th bit)
	*/
    int x = n^m;
    return log2(x&(~(x-1)));
}

int MODULUS(int num, int mod){
	// 18. Modulus operation (%) -> remainder operation
	/*
		dividing integers ignores the remainder, so why not multiply again ans see how much is ignored = remainder
		Examples: 	17/3 = 5 = q 		(17, 3 are integers not floats)
					q*3 = 5*3  = 15
					-> 17-15 = 2 is ignored
					Therefore 17%3 = 2
	*/
	return num - (num/mod)*mod;
}

bool isSparse(int num){
	/*
		19. A number is said to be a sparse number if in binary representation of the number no two or more consecutive bits are set.
		01010101010101 -> NOT SPARSE
		01010101011001 -> IS SPARSE
		-> return true if given number is sparse
		Move each bit one step right and AND with previous position. if any two ones are consecutive, 
		this will make one bit 1,
		if no two 1's are consecutive, all becomes zero.
		Ex: 10101010101 (num)
			01010101010 (num>>1)
		   =00000000000 = 0 (Hence sparse)
	*/
	return !(num & (num>>1)); // ! -> return true of n is zero i.e. !n 
}

int rangeBitwiseAnd(int m, int n) { // AND of all numbers between m and n 
	// 20. logic -> all bits except MSB equal part of m, n become 0.
	/*
		AND of all numbers between m and n
		m = 3 n = 7, ans = 3 && 4 && 5 && 6 && 7
		Run examples to understand below code
		Logic: the change always comes from least significant bits first, even if one flips once its going to be zero,
		so check what MSB part if similar in both numbers
	*/
    int a = 0;
    while(m != n) {
        m >>= 1;
        n >>= 1;
        a++;
    }
    return m<<a; 
}

void printBinary(unsigned long number, int bits = 32);

int main(){
	int num, num1, num2, num3, k;

	// Q1
	printf("Q1) MODULUS using Macro\n");
	num1 = 17; num2 = 3; 
	printf(" (%d MOD %d) = %d\n\n", num1, num2, MOD(num1, num2));

	// Q2
	printf("Q2) Get SIZE using Macro\n");
	printf(" SIZE of int is: %ld\n\n", SIZEOF(num));

	// Q3
	printf("Q3) Rotate nibbles in a number\n");
	unsigned long number = 92184147;
	printf(" Before Rotating: "); printBinary(number);
	rotateNibs(number);
	printf(" After Rotating: "); printBinary(number);
	printf("\n");

	// Q4 
	printf("Q4) Reverse bits in a number\n");
	number = 92184147;
	printf(" Before Reversing: "); printBinary(number);
	reverseBits(number);
	printf(" After Reversing: "); printBinary(number);
	printf("\n");

	// Q5
	printf("Q5) Swap two numbers using XOR\n");
	num1 = 3; num2 = 5;
	printf(" Before swap: %d %d\n", num1, num2); 
	swapNumbers(num1, num2);
	printf(" After swap:  %d %d\n\n", num1, num2);

	// Q6
	printf("Q6) Rotate three numbers\n");
	num1 = 3; num2 = 5; num3 = 7;
	printf(" Before rotate: %d %d %d\n", num1, num2, num3); 
	rotate3(num1, num2, num3);
	printf(" After rotate:  %d %d %d\n\n", num1, num2, num3);

	// Q7
	printf("Q7) Reset Least significant set bit\n");
	num = 1228;
	printf(" Before resetting LSB set bit: "); printBinary(num, 16);
	resetLSSetBit(num);
	printf(" After resetting LSB set bit: "); printBinary(num, 16);
	printf("\n");

	// Q8)
	printf("Q8) Get position of least significant set bit\n");
	num = 1228;
	printf(" Input number : \n"); printBinary(num, 16);
	num = getLSSetBit(num);
	printf(" Least significant set bit:\n"); printBinary(num, 16);
	printf(" Position of LSB set bit: %d", (int)log2(num));
	printf("\n\n");

	// Q9)
	printf("Q9) Turn OFF Kth bit\n");
	num = 1228; k = 6;
	printf(" Before turning off %dth bit: ", k); printBinary(num, 16);
	turnOffKthBit(num, k);
	printf(" After turning off %dth bit: ", k); printBinary(num, 16);
	printf("\n");

	// Q10)
	printf("Q10 Turn ON Kth bit)\n");
	num = 1228; k = 4;
	printf(" Before turning ON %dth bit: ", k); printBinary(num, 16);
	turnOnKthBit(num, k);
	printf(" After turning ON %dth bit: ", k); printBinary(num, 16);
	printf("\n");

	// Q11)
	printf("Q11) Toggle Kth bit\n");
	num = 1228; k = 6;
	printf(" Before toggling %dth bit: ", k); printBinary(num, 16);
	toggleKthBit(num, k);
	printf(" After toggling %dth bit: ", k); printBinary(num, 16);
	printf("\n");

	// Q12)
	printf("Q12) Check if Kth bit is set\n");
	num = 1228; k = 6;
	printBinary(num);
	printf(" Is: %dth bit set ? : %s\n\n", k, isKthSet(num, k) ? "YES" : "NO");

	// Q13)
	printf("Q13) Binary to Grey conversion\n");
	num = 1228;
	printf(" Binary: "); printBinary(num, 16);
	num = binaryToGrey(num);
	printf(" Grey: "); printBinary(num, 16);
	printf("\n");

	// Q14)
	printf("Q14) Grey to Binary conversion\n");
	num = 1228;
	printf(" Grey: "); printBinary(num, 16);
	num = grayToBinary(num);
	printf(" Binary: "); printBinary(num, 16);
	printf("\n");

	// Q15)
	printf("Q15) Check if number is power of 2\n");
	num1 = 1024; num2 = 1235;
	printf(" Is %d power of 2 ? -> %s\n", num1, isPowerOf2(num1) ? "YES" : "NO");
	printf(" Is %d power of 2 ? -> %s\n\n", num2, isPowerOf2(num2) ? "YES" : "NO");

	// Q16)
	printf("Q16) Count no. of set bits(1's) in a number\n");
	num = 1228;
	printf(" Number is "); printBinary(num, 16);
	printf(" No. of set bits = %d\n\n", countSetBits(num));

	// Q17)
	printf("Q17) Get position of Right most different bit (given two numbers)\n"); 
	num1 = 364; num2 = 460;
	printBinary(num1, 16); printBinary(num2, 16);
	printf("Position of right mose different bit: %d\n\n", posOfRightMostDiffBit(num1, num2));

	// Q18)
	printf("Q18) MODULUS without using %% operation\n");
	num1 = 17; num2 = 3;
	printf(" %d MOD %d = %d\n\n", num1, num2, MODULUS(num1, num2));

	// Q19)
	printf("Q19) Check if given number is sparse\n");
	num = 178956970; printBinary(num);
	printf(" Is it sparse ? %s\n", isSparse(num) ? "YES" : "NO");
	num = 178956123; printBinary(num);
	printf(" Is it sparse ? %s\n\n", isSparse(num) ? "YES" : "NO");

	// Q20)
	printf("Q20) Range AND\n");
	num1 = 373; num2 = 377;
	printBinary(num1, 16); printBinary(num2, 16);
	int ans = rangeBitwiseAnd(num1, num2);
	printBinary(ans, 16);
	printf(" Range AND from %d to %d = %d\n\n", num1, num2, ans);
}

void printBinary(unsigned long number, int bits){
	uint32_t num = (uint32_t)number;
	printf(" %d	: ", num);
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