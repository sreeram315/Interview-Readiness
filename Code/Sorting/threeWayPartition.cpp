

void threeWayPartition(vector<int>& arr,int a, int b) {
    int n = arr.size(), s = 0, e = n-1;
    for(int i = 0; i <= e;){
        if(arr[i] < a){
            swap(arr[i++], arr[s++]);
        }else if(arr[i] > b ){
            swap(arr[i], arr[e--]);
        }else{
            i++;
        }
    } 
}