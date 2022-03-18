// https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1/?track=P100-Stack&batchId=238
void calc_pm(int *pm, int *arr, int n){
    stack<int>st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        pm[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

void calc_nm(int *nm, int *arr, int n){
    stack<int>st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nm[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}

vector <int> maxOfMin(int arr[], int n) {
    vector<int>ans(n+1, -1);
    int pm[n];
    int nm[n];
    calc_pm(pm, arr, n);
    calc_nm(nm, arr, n);
    bool debug = 0;
    
    int a[n] = {INT_MIN};
    for(int i = 0; i < n; i++)
        a[i] = nm[i]-pm[i]-1;
        
    if(debug){
        for(int i = 0; i < n; i++)
            printf("%2d ", arr[i]);
        cout << "-- ARRAY" << endl;
        for(int i = 0; i < n; i++)
            printf("%2d ", nm[i]);
        cout << "-- NEXT MIN" << endl;
        for(int i = 0; i < n; i++)
            printf("%2d ", pm[i]);
        cout << "-- PREV MIN" << endl;
        for(int i = 0; i < n; i++)
            printf("%2d ", a[i]);
        cout << "-- WINDOW MINIMUM" << endl;
    }
    
    for(int i = 0; i < n; i++)
        ans[a[i]] = max(ans[a[i]], arr[i]);
    
    if(debug){
        for(int i = 1; i <= n; i++)
            printf("%2d ", ans[i]);
        cout << "-- ANS 1" << endl;
    }
    
    for(int i = n-1; i >= 0; i--)
            ans[i] = max(ans[i], ans[i+1]);
            
    if(debug){
        for(int i = 1; i <= n; i++)
            printf("%2d ", ans[i]);
        cout << "-- ANS 2" << endl;
    }
    
    // removing first element
    for(int i = 0; i < n; i++)
        ans[i] = ans[i+1];
    ans.resize(n);
    return ans;
}