class Solution 
{
    public:
    
    bool is_ok(int arr[N][N], int i, int j){
        for(int ind = 0; ind < N; ind++){
            if(j!=ind && arr[i][ind]==arr[i][j]) return false;
            if(i!=ind && arr[ind][j]==arr[i][j]) return false;
        }
        int R = (i/3)*3, C = (j/3)*3; // or do i-i%3 8-8%3 = 8-2 = 6
        for(int r = R; r<R+3; r++){
            for(int c = C; c<C+3; c++){
                if(r==i && j==c) continue;
                if(arr[r][c]==arr[i][j])
                    return false;
            }
        }
        return true;
    }
    
    bool util(int arr[N][N] ){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(arr[i][j]==0){
                    for(int x = 1; x<=9; x++){
                        arr[i][j] = x;
                        if(is_ok(arr, i, j) && util(arr))
                            return true;
                        arr[i][j] = 0;
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        return util(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                printf("%d ", grid[i][j]);
            // printf("\n");
        }
    }
};