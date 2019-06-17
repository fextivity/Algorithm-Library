/*
par[i] > 0 => i and x are in the same set
par[i] < 0 => i is the root of the set and -par[i] is the size of the set
At the beginning: set par[i] = -1 
*/
int par[N];

// Complexity: O(f^-1(n)) for each query / function, where f^-1() is the inverse Ackermann function

int root(int x){
    return par[x] < 0 ? x : par[x] = root(par[x]);
}

void merge(int x, int y){
    if ((x = root(x)) == (y = root(y))){
        return;
    }
    if (par[y] < par[x]){
        swap(x, y);
    }
    par[x] += par[y];
    par[y] = x;
}
