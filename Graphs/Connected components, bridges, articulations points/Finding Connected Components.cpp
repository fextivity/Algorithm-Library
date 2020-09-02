int n;
vi adj[N], cpn;
bool ck[N];

void dfs(int u){
    ck[u] = true;
    cpn.pb(u);
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
}

void find_cpn(){
    ForE(i, 1, n){
        if (ck[i]){
            continue;
        }
        dfs(i);
        PrintV(cpn);
        cout << endl;
        cpn.clear();
    }
}
