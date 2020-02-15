int n;
vi adj[N];
bool ck[N];
vi vans;

void dfs(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    vans.pb(u);
}

void toposort(){
    ForE(i, 1, n){
        if (!ck[i]){
            dfs(i);
        }
    }
    reverse(bend(vans));
}
