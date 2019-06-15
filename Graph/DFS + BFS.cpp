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

// Complexity: O(V)
void bfs(int u){
    queue <int> qu;
    qu.push(u);
    while (!qu.empty()){
        int t = qu.front();
        qu.pop();
        ck[t] = 1;
        Fora(v, adj[t]){
            if (!ck[v]){
                qu.push(v);
            }
        }
    }
}
