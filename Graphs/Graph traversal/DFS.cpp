int n;
vi adj[N];
bool ck[N];

void dfs(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
}

void dfs(int u, int p){
    Fora(v, adj[u]){
        if (v != p){
            dfs(v, u);
        }
    }
}
