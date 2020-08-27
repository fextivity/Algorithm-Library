int z[N];

void z_function(string s){
    int n = s.length(); s = ' ' + s;
    z[1] = 0;
    int l = 0, r = 0;
    ForE(i, 2, n){
        if (r < i){
            l = i;
            r = i;
            while (r <= n && s[r] == s[r - l + 1]){
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else{
            int k = i - l + 1;
            if (z[k] < r - i){
                z[i] = z[k];
            }
            else{
                l = i;
                while (r <= n && s[r] == s[r - l + 1]){
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}
