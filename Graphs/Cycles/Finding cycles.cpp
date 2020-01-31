int n;
vi adj[N];
int col[N];

bool dfs(int u){
    col[u] = 1;
    Fora(v, adj[u]){
        if (col[v] == 1){
            return true;
        }
        if (col[v] == 2){
            continue;
        }
        if (dfs(v)){
            return true;
        }
    }
    col[u] = 2;
    return false;
}

bool is_cycle(){
    ForE(i, 1, n){
        if (col[i] == 0){
            if (dfs(i)){
                return true;
            }
        }
    }
    return false;
}
