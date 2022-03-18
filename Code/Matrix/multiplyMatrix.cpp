


vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B){
    vector<vector<int>>arr(A.size(), vector<int>(B[0].size(), 0));
    if(!A.size() || A[0].size()!=B.size()) return {};
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            int temp = 0;
            for(int k = 0; k < A[0].size(); k++){
                temp += A[i][k]*B[k][j];
            }
            arr[i][j] = temp;
        }
    }
    return arr;
}