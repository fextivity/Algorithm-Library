/*
1. File: Extended Euclidean Algorithm.cpp   Link: https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
2. Algorithm
Calculate gcd of two integers (a and b), but also calculate coefficients x and y such that ax + by = 1.
3. Usage and Applications
Function gcd(int a, int b, int &x, int &y) return gcd of a and b, but also modify value of x and y.
Useful for general algebra.
4. Complexity: O(log(min(a,b)).
*/


int gcd(int a, int b, int &x, int &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1, d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
