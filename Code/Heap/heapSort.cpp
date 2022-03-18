class Solution
{
    public:

    void pull_down(int arr[], int n, int i)  
    {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if(l<n && arr[l]<arr[smallest]) smallest = l;
        if(r<n && arr[r]<arr[smallest]) smallest = r;
        if(i!=smallest){
            swap(arr[i], arr[smallest]);
            pull_down(arr, n, smallest);
        }
    }

    void buildHeap(int arr[], int n)  
    { 
        for(int i = n/2+1; i >= 0; i--){
            pull_down(arr, n, i);
        }
    }

    void heapSort(int arr[], int N)
    {
        int n = N;
        buildHeap(arr, n);
        while(n > 1){
            swap(arr[0], arr[--n]);
            pull_down(arr, n, 0);
        }
        reverse(arr, arr+N);
    }
};