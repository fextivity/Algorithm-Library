int n;
int lpf[N];
vector <int> prime;

void sieve(){
    for (int i = 2; i < N; i++){
        if (lpf[i] == 0){
            lpf[i] = i;
            prime.pb(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= lpf[i] && i * prime[j] < N; j++){
            lpf[i * prime[j]] = prime[j];
        }
    }
}
