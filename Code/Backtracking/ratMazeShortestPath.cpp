// https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps-1587115621/1/?track=P100-Backtracking&batchId=238

int n;
vector<pair<int, int>>paths = {
    {0, 1}, {1, 0}
};

inline bool is_valid(int x, int y, vector<int> maze[]){
    return ((x>=0 && y>=0 && x<n && y<n && maze[x][y]>0) || (x==n-1 && y==n-1));
}

bool util(pair<int, int>p, vector<int> arr[], vector<int> ans[]){
    int i = p.first, j = p.second;
    if(i==n-1 && j==n-1){
        ans[i][j] = 1;
        return true;
    }
    int S = arr[i][j];
    ans[i][j] = 1;
    for(int s = 1; s <= S; s++){
        for(auto p: paths){
            int x = i+(s* (p.first)), y = j+(s*(p.second));
            if(is_valid(x, y, arr) && util({x, y}, arr, ans)) return true;
        }
    }
    ans[i][j] = 0;
    return false;
}

void solve(int N, vector<int> maze[]) {
    n = N;
    vector<int> ans[N];
    for(int i = 0; i < N; i++) ans[i].assign(N, 0);
    if(!util({0, 0}, maze, ans)){
        printf("-1\n");
        return;
    }else{
        print(n, ans);
    }
}