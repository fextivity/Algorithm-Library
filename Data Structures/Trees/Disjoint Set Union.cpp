struct disjoint_set_union{
    int par[N];
    
    void init(){
        msetn1(par);
    }

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
} dsu;
