int n, M;
vector<int>colors;

bool is_okay(bool g[101][101], int node){
    int c = colors[node];
    for(int i = 0; i < n; i++){
        if(i == node) continue;
        if((g[node][i] || g[i][node]) && colors[i]==c ) return false;
    }
    return true;
}

bool util(bool g[101][101], int node = 0){
    if(node == n) return true;
    for(int c = 0; c < M; c++){
        colors[node] = c;
        if(is_okay(g, node) && util(g, node+1))
            return true;
        colors[node] = -1;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    n = V;
    M = m;
    colors.clear(); colors.resize(n, -1);
    return util(graph);
}