int n;
vector <bool> prime(n + 1, true);

void sieve(){
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++){
        if (prime[i]){
            for (int j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
}
