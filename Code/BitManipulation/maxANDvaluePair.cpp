int util(int pat, int *arr, int N){
    int c = 0;
    for(int i = 0; i < N; i++)
        if( (arr[i]&pat) == pat) c++;
    return c;
}
    
int maxAND (int arr[], int N)
{
    int res = 0, nb = sizeof(int)*8, count;
    for(int b = nb-1; b >= 0; b--){
        count =  util(res|(1<<b), arr, N);
        if(count >= 2)
            res |= (1<<b);
    }
    return res;
}

// https://practice.geeksforgeeks.org/problems/maximum-and-value-1587115620/1/?track=P100-Bit%20Magic&batchId=238