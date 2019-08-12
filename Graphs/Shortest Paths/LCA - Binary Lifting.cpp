int n;
vi adj[N];
int memo[N][M + 1], h[N];

void dfs(int u, int p){
    memo[u][0] = p;
    ForE(i, 1, M){
        memo[u][i] = memo[memo[u][i - 1]][i - 1];
    }
    Fora(v, adj[u]){
        if (v != p){
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v){
    if (h[u] < h[v]){
        swap(u, v);
    }
    FordE(i, M, 0){
        if (h[u] - (1 << i) >= h[v]){
            u = memo[u][i];
        }
    }
    if (u == v){
        return u;
    }
    FordE(i, M, 0){
        if (memo[u][i] != memo[v][i]){
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];
}

int dis(int u, int v){
    int p = lca(u, v);
    return h[u] + h[v] - 2 * h[p];
}
