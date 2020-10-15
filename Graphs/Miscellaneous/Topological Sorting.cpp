int n;
vi adj[N];
bool ck[N];
vi topo;

void dfs(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    topo.pb(u);
}

void toposort(){
    mset(ck);
    ForE(i, 1, n){
        if (!ck[i]){
            dfs(i);
        }
    }
    reverse(bend(topo));
}
