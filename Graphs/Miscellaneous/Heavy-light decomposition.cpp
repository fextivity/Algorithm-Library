int dfs(int u){
    int sz = 1, mxsz = -1;
    Fora(v, adj[u]){
        if (v == par[u]) continue;
        par[v] = u;
        h[v] = h[u] + 1;
        int szv = dfs(v);
        sz += szv;
        if (mxsz < szv){
            mxsz = szv;
            heavy[u] = v;
        }
    }
    return sz;
}

void decompose(int u, int h){
    head[u] = h; pos[u] = ++curpos;
    if (heavy[u]){
        decompose(heavy[u], h);
    }
    Fora(v, adj[u]){
        if (v == par[u]) continue;
        if (v == heavy[u]) continue;
        decompose(v, v);
    }
}

int lca(int u, int v){
    while (head[u] != head[v]){
        if (h[head[u]] < h[head[v]]){
            swap(u, v);
        }
        u = par[head[u]];
    }
    if (h[u] < h[v]){
        swap(u, v);
    }
    return v;
}

void update(int u, int v, int val){
    while (head[u] != head[v]){
        if (h[head[u]] < h[head[v]]){
            swap(u, v);
        }
        it.update(1, 1, n, pos[head[u]], pos[u], val);
        u = par[head[u]];
    }
    if (h[u] < h[v]){
        swap(u, v);
    }
    it.update(1, 1, n, pos[v], pos[u], val);
}

int get(int u, int v){
    int ans = 0;
    while (head[u] != head[v]){
        if (h[head[u]] < h[head[v]]){
            swap(u, v);
        }
        ans += it.get(1, 1, n, pos[head[u]], pos[u]);
        u = par[head[u]];
    }
    if (h[u] < h[v]){
        swap(u, v);
    }
    ans += it.get(1, 1, n, pos[v], pos[u]);
    return ans;
}
