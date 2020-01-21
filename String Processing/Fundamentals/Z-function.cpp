int n;
string s;
int z[N];

void z_function(){
    s = ' ' + s;
    Z[1] = 0;
    int l = 0, r = 0;
    ForE(i, 2, n){
        if (r < i){
            l = i;
            r = i;
            while (r <= n && s[r] == s[r - l + 1]){
                r++;
            }
            Z[i] = r - l;
            r--;
        }
        else{
            int k = i - l + 1;
            if (Z[k] < r - i){
                Z[i] = Z[k];
            }
            else{
                l = i;
                while (r <= n && s[r] == s[r - l + 1]){
                    r++;
                }
                Z[i] = r - l;
                r--;
            }
        }
    }
}
