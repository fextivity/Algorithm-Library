int par[N];

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

msetn1(par);
