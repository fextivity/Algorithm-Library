struct matrix{
    vvi mt;
    vi& operator[](int x){
        return mt[x];
    };
    int size(){
        return mt.size();
    }
    matrix(int n = 0, int m = 0){
        mt.assign(n + 1, vi(m + 1, 0));
    }
};

matrix operator*(matrix a, matrix b){
    int na = a.size() - 1, ma = a[0].size() - 1;
    int nb = b.size() - 1, mb = b[0].size() - 1;
    matrix c = matrix(na, mb);
    ForE(i, 1, na){
        ForE(j, 1, mb){
            ForE(k, 1, nb){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int b){
    int na = a.size() - 1;
    matrix ans = matrix(na + 1, na + 1);
    ForE(i, 1, na){
        ans[i][i] = 1;
    }
    while (b){
        if (b & 1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
