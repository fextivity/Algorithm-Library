const int base = 31;

int n;
string s;
pii hashs[N];
int pw1[N], pw2[N];

void init(){
    s = ' ' + s;
    pw1[0] = 1;
    pw2[0] = 1;
    For(i, 1, N){
        pw1[i] = (pw1[i - 1] * base) % mod1;
        pw2[i] = (pw2[i - 1] * base) % mod2;
    }
    ForE(i, 1, n){
        hashs[i] = {(hashs[i - 1].fi * base + s[i] - 'a' + 1) % mod1, (hashs[i - 1].se * base + s[i] - 'a' + 1) % mod2};
    }
}

pii cal(int l, int r){
    pii ans;
    ans.fi = ((hashs[r].fi - (hashs[l - 1].fi * pw1[r - l + 1]) % mod1) % mod1 + mod1) % mod1;
    ans.se = ((hashs[r].se - (hashs[l - 1].se * pw2[r - l + 1]) % mod2) % mod2 + mod2) % mod2;
    return ans;
}
