int n;
vector <int> lpf(n + 1, 0), prime;

void sieve(){
    for (int i = 2; i <= n; i++){
        if (lpf[i] == 0){
            lpf[i] = i;
            prime.pb(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= lpf[i] && i * prime[j] <= n; j++){
            lpf[i * prime[j]] = prime[j];
        }
    }
}
