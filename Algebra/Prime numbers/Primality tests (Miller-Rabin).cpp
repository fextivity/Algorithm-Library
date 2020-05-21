ll binpow(ll base, ll e, ll md){
    ll ans = 1;
    base %= md;
    while (e){
        if (e & 1){
            ans = (ans * base) % md;
        }
        base = (base * base) % md;
        e >>= 1;
    }
    return ans;
}

bool check_composite(ll n, ll a, ll d, int s){
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1){
        return false;
    }
    for (int r = 1; r < s; r++){
        x = (x * x) % n;
        if (x == n - 1){
            return false;
        }
    }
    return true;
}

bool Miller_Rabin(ll n){ // Nondeterministic version
    int iter = 20;
    if (n < 4){
        return n == 2 || n == 3;
    }
    /* OPTIMIZATION:
    ForE(i, 2, 100){
        if (n % i == 0){
            if (n == i){
                return true;
            }
            else{
                return false;
            }
        }
    }
    */
    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0){
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter; i++){
        int a = 2 + rando() % (n - 3);
        if (check_composite(n, a, d, s)){
            return false;
        }
    }
    return true;
}

bool Miller_Rabin(ll n) { // Deterministic version.
    if (n < 2){
        return false;
    }
    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0){
        d >>= 1;
        r++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if (n == a){
            return true;
        }
        if (check_composite(n, a, d, r)){
            return false;
        }
    }
    return true;
}
