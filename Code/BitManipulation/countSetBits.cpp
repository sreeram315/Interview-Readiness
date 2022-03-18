

// You are given a number N. 
// Find the total count of set bits for all numbers from 1 to N(both inclusive).
int countSetBits(int n) {
    if(!n) return 0;
    int m = (log2(n))+1;
    int tl, tr, bl, br;
    tl = 0;
    tr = (m-1)*pow(2, m-2);
    bl = n - (pow(2, m-1) -1);
    br = countSetBits(n & (int)(pow(2, m-1)-1)) ;
    return tl+tr+bl+br;
}