int n;
vi adj[N];
bool ck[N];
vi toposort, cpn;
vvi scc;

void dfs(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    toposort.pb(u);
}

void toposort(){
    mset(ck);
    ForE(i, 1, n){
        if (!ck[i]){
            dfs(i);
        }
    }
    reverse(bend(toposort));
}

void dfs2(int u){
    ck[u] = true;
    cpn.pb(u);
    Fora(v, adj[u]){
        if (!ck[u]){
            dfs(u);
        }
    }
}

void find_scc(){
    toposort();
    mset(ck);
    FordE(i, n - 1, 0){
        if (!ck[i]){
            cpn.clear();
            dfs2(i);
            scc.pb(cpn);
        }
    }
}
