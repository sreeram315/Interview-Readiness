


unsigned int getFirstSetBit(int n){
   return log2(n&(~(n-1)))+1;
}

int posOfRightMostDiffBit(int m, int n){
    int x = n^m;
    return log2(x&(~(x-1)))+1;
}

bool checkKthBit(int n, int k){
    return (n>>k)&1;
}

int countBitsFlip(int a, int b){ 
    bitset<32>B(a^b);
    return B.count();
}

bool isSparse(int n) {
    return !(n&(n>>1));
}

int maxConsecutiveOnes(int N) {
    int c = 0; int ans = -1;
    while(N){
        if(N&1){
            c++;
        }
        else{
            ans = max(c, ans);
            c=0;
        }
        N = N>>1;
    }
    return max(ans, c);
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

int isPowerOf2(int n){
	return  n!=0 && (n & (n-1))==0;
}

unsigned int swapEvenOddBits(unsigned int n) {
	unsigned int e = (n & 0b10101010101010101010101010101010)>>1,
	             o = (n & 0b01010101010101010101010101010101)<<1;
	return e|o;
}











