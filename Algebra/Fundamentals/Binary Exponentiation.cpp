/*
1. File: Binary Exponentiation.cpp  Link: https://cp-algorithms.com/algebra/binary-exp.html
2. Algorithm
Calculate power (x^y) with arbitrary base (x), exponent (y) and possibly modulo (mod).
Use Divide and Conquer (D&C).
3. Usage and Applications
Function binpow(int x, int y) return value of (x^y) modulo mod.
Useful for general algebra with numbers upto 10^9.
4. Complexity: O(log(y)).
*/

long long binpow(long long x, long long y){
    long long ans = 1;
    while (y){
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
