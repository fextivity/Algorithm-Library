struct fenwick_tree{
    vi bit;
    int n;

    fenwick_tree(int n = 0){
        this->n = n + 1;
        bit.assign(this->n + 1, 0);
    }

    fenwick_tree(vector<int> a) : fenwick_tree(a.size()){
        this->n = a.size() + 1;
        bit.assign(n + 1, 0);
        For(i, 0, a.size()){
            add(i, a[i]);
        }
    }

    int sum(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }

    int sum(int l, int r){
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta){
        for (; idx <= n; idx += idx & -idx){
            bit[idx] += delta;
        }
    }
} bit1;

struct fenwick_tree_2d{
    vvi bit;
    int n, m;

    fenwick_tree_2d(int n = 0, int m = 0){
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(this->n + 1, vi(this->m + 1, 0));
    }

    fenwick_tree_2d(vvi a) : fenwick_tree_2d(a.size(), a[0].size()){
        this->n = a.size() + 1;
        this->m = a[0].size() + 1;
        bit.assign(n + 1, vi(m + 1, 0));
        For(i, 0, a.size()){
            For(j, 0, a[0].size()){
                add(i, j, a[i][j]);
            }
        }
    }

    int sum(int x, int y){
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i){
            for (int j = y; j > 0; j -= j & -j){
                ans += bit[i][j];
            }
        }
        return ans;
    }

    int sum(int x1, int y1, int x2, int y2){
        return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
    }

    void add(int x, int y, int delta){
        for (int i = x; i <= n; i += i & -i){
            for (int j = y; j <= m; j += j & -j){
                bit[i][j] += delta;
            }
        }
    }
} bit2;

int n, m;

void update(int ux, int uy, int vx, int vy, int val){
    int tmp, lx, ly, rx, ry;
    //=========================================================================================
    tmp = val; lx = ux; ly = uy; rx = vx; ry = vy;
    a.add(lx, ly, tmp);
    a.add(lx, ry + 1, -tmp);
    a.add(rx + 1, ly, -tmp);
    a.add(rx + 1, ry + 1, tmp);
    //=========================================================================================
    tmp = -val * (uy - 1); lx = ux; ly = uy; rx = vx; ry = vy;
    b.add(lx, ly, tmp);
    b.add(lx, ry + 1, -tmp);
    b.add(rx + 1, ly, -tmp);
    b.add(rx + 1, ry + 1, tmp);
    tmp = val * (vy - uy + 1); lx = ux; ly = vy + 1; rx = vx; ry = m;
    b.add(lx, ly, tmp);
    b.add(lx, ry + 1, -tmp);
    b.add(rx + 1, ly, -tmp);
    b.add(rx + 1, ry + 1, tmp);
    //=========================================================================================
    tmp = -val * (ux - 1); lx = ux; ly = uy; rx = vx; ry = vy;
    c.add(lx, ly, tmp);
    c.add(lx, ry + 1, -tmp);
    c.add(rx + 1, ly, -tmp);
    c.add(rx + 1, ry + 1, tmp);
    tmp = val * (vx - ux + 1); lx = vx + 1; ly = uy; rx = n; ry = vy;
    c.add(lx, ly, tmp);
    c.add(lx, ry + 1, -tmp);
    c.add(rx + 1, ly, -tmp);
    c.add(rx + 1, ry + 1, tmp);
    //=========================================================================================
    tmp = val * (ux - 1) * (uy - 1); lx = ux; ly = uy; rx = vx; ry = vy;
    d.add(lx, ly, tmp);
    d.add(lx, ry + 1, -tmp);
    d.add(rx + 1, ly, -tmp);
    d.add(rx + 1, ry + 1, tmp);
    tmp = -val * (ux - 1) * (vy - uy + 1); lx = ux; ly = vy + 1; rx = vx; ry = m;
    d.add(lx, ly, tmp);
    d.add(lx, ry + 1, -tmp);
    d.add(rx + 1, ly, -tmp);
    d.add(rx + 1, ry + 1, tmp);
    tmp = -val * (vx - ux + 1) * (uy - 1); lx = vx + 1; ly = uy; rx = n; ry = vy;
    d.add(lx, ly, tmp);
    d.add(lx, ry + 1, -tmp);
    d.add(rx + 1, ly, -tmp);
    d.add(rx + 1, ry + 1, tmp);
    tmp = val * (vx - ux + 1) * (vy - uy + 1); lx = vx + 1; ly = vy + 1; rx = n; ry = m;
    d.add(lx, ly, tmp);
    d.add(lx, ry + 1, -tmp);
    d.add(rx + 1, ly, -tmp);
    d.add(rx + 1, ry + 1, tmp);
    //=========================================================================================
}

int get(int x, int y){
    if (x <= 0 || y <= 0) return 0;
    return x * y * a.sum(x, y) + x * b.sum(x, y) + y * c.sum(x, y) + d.sum(x, y);
}

int get(int ux, int uy, int vx, int vy){
    return get(vx, vy) - get(vx, uy - 1) - get(ux - 1, vy) + get(ux - 1, uy - 1);
}
