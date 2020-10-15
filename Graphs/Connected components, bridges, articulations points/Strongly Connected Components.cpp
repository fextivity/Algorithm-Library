int n, m;
vi adj[N], radj[N];
bool ck[N];
vi topo, cpn;
vvi scc;

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

void dfs2(int u){
    ck[u] = true;
    cpn.pb(u);
    Fora(v, radj[u]){
        if (!ck[v]){
            dfs2(v);
        }
    }
}

void find_scc(){
    toposort();
    mset(ck);
    For(i, 0, n){
        if (!ck[topo[i]]){
            cpn.clear();
            dfs2(topo[i]);
            scc.pb(cpn);
        }
    }
}
