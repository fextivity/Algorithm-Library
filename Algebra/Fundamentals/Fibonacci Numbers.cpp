pii fib(int n){
    if (n == 0) return {0, 1};
    pii p = fib(n >> 1);
    int c = p.fi * (2 * p.se - p.fi);
    int d = p.fi * p.fi + p.se * p.se;
    if (n & 1) return {d, c + d};
    return {c, d};
}
