int n;
int a[N];

int lis(){
    int b[N];
    int idx = 1;
    b[idx] = a[1];
    ForE(i, 2, n){
        if (a[i] >= b[idx]){
            idx++;
            b[idx] = a[i];
            continue;
        }
        int itr = upb(b + 1, b + 1 + idx, a[i]) - b;
        b[itr] = a[i];
    }
    return idx;
}
