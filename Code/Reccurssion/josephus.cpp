int josephus(int n, int k){
    if(n==1) return 0;
    return (j(n-1, k)+k)%n;
}