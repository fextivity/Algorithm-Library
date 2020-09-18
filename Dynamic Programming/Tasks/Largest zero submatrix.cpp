int n, m;
int a[N][N];
int d[N], d1[N], d2[N];
stack <int> st;

int zero_matrix(){
    int ans = 0;
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (a[i][j] == 1){
                d[j] = i;
            }
        }
        ForE(j, 1, m){
            while (!st.empty() && d[st.top()] <= d[j]){
                st.pop();
            }
            d1[j] = (st.empty() ? 0 : st.top());
            st.push(j);
        }
        while (!st.empty()){
            st.pop();
        }
        FordE(j, m, 1){
            while (!st.empty() && d[st.top()] <= d[j]){
                st.pop();
            }
            d2[j] = (st.empty() ? m + 1 : st.top());
            st.push(j);
        }
        while (!st.empty()){
            st.pop();
        }
        ForE(j, 1, m){
            ans = max(ans, (i - d[j]) * (d2[j] - d1[j] - 1));
        }
    }
    return ans;
}
