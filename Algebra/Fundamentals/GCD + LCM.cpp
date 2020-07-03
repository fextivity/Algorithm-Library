long long gcd(long long a, long long b){
    while (b){
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b){
    return a / __gcd(a, b) * b;
}
