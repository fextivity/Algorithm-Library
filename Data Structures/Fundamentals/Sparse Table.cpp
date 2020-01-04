const int N = 1e5 + 5, K = log2(N) + 2;

int n;
int a[N];
int rmq[N][K];

int cal(int x, int y){
	int z = log2(y - x + 1);
	return __gcd(rmq[x][z], rmq[y - (1 << z) + 1][z]);
}

ForE(i, 1, n){
    rmq[i][0] = a[i];
}
For(j, 1, K){
    ForE(i, 1, n - (1 << j) + 1){
        rmq[i][j] = __gcd(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
    }
}

