vi adj[N];
bool ck[N];

void dfs(int u){
    ck[u] = 1;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
}
