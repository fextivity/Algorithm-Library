struct FenwickTree{
    vi bit;
    int n;

    FenwickTree(int n = 0){
        this->n = n + 1;
        bit.assign(this->n + 1, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()){
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
