int n;
vi adj[N];
bool ck[N];

// Complexity: O(V)
void dfs(int u){
    ck[u] = 1;
    Fora(v, adj[u]){
        if (!ck[v]) dfs(v);
    }
}
