int n;
vi adj[N];
int col[N], par[N];
int cycle_start, cycle_end;
vi cycle;

bool dfs(int u){
    col[u] = 1;
    Fora(v, adj[u]){
        if (col[v] == 1){
            cycle_end = u;
            cycle_start = v;
            return true;
        }
        if (col[v] == 2){
            continue;
        }
        par[v] = u;
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
                cycle.pb(cycle_start);
                for (int j = cycle_end; j != cycle_start; j = par[j]){
                    cycle.pb(j);
                }
                reverse(bend(cycle));
                return true;
            }
        }
    }
    return false;
}
