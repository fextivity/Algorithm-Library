int n;
vi adj[N];
int tin[N], low[N];
bool ck[N], iscutpoint[N];
int tim;

void dfs(int u, int p){
    ck[u] = true;
    tin[u] = tim;
    low[u] = tim;
    tim++;
    int child = 0;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        if (ck[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1){
                iscutpoint[u] = true;
            }
            child++;
        }
    }
    if (p == -1 && child > 1){
        iscutpoint[u] = true;
    }
}

void find_cutpoints(){
    tim = 0;
    mset(ck);
    msetn1(tin);
    msetn1(low);
    For(i, 0, n){
        if (!ck[i]){
            dfs(i, -1);
        }
    }
}
