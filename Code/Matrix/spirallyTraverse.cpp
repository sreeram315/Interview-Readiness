#include <bits/stdc++.h> 
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) {
    vector<int>ans;
    int sr = 0, sc = 0, er = r-1, ec = c-1;
    
    while(sr<=er && sc<=ec){
        
        for(int i = sc; i <= ec; i++)
            ans.push_back(m[sr][i]);
        sr++;
        
        for(int i = sr; i <= er; i++)
            ans.push_back(m[i][ec]);
        ec--;
        
        if(sr <= er){
            for(int i = ec; i >= sc; i--)
                ans.push_back(m[er][i]);
            er--;
        }
        
        if(sc <= ec){
            for(int i = er; i >= sr; i--)
                ans.push_back(m[i][sc]);
            sc++;
        }
    }
    
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int>ans = spirallyTraverse(arr, 3, 3);
    for(int x: ans) printf("%d ", x);
    printf("\n\n");
}