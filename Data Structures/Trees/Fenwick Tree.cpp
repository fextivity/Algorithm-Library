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

struct 2d_fenwick_tree{
    vvi bit;
    int n, m;

    2d_fenwick_tree(int n = 0, int m = 0){
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(this->n + 1, vi(this->m + 1, 0));
    }

    2d_fenwick_tree(vvi a) : 2d_fenwick_tree(a.size(), a[0].size()){
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
