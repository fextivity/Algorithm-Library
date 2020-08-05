pair <long long, long long> fib(long long n){
    if (n == 0) return make_pair(0, 1);
    pair <long long, long long> p = fib(n >> 1);
    long long c = p.first * (2 * p.second - p.first);
    long long d = p.first * p.first + p.second * p.second;
    if (n & 1) return make_pair(d, c + d);
    return make_pair(c, d);
}
