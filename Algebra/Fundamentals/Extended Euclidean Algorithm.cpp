/*
1. File: Extended Euclidean Algorithm.cpp   Link: https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
2. Algorithm
Calculate gcd of two integers (a and b), but also calculate coefficients x and y such that ax + by = 1.
3. Usage and Applications
Function egcd(int a, int b, int &x, int &y) return gcd of a and b, but also modify value of x and y.
Useful for general algebra.
4. Complexity: O(log(min(a, b)).
*/

long long egcd(long long a, long long b, long long &x, long long &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1, d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
