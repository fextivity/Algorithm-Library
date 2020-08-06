int n;
int dist[N], par[N], mval[N]; // mval: 0 - not calculated, 1 - is calculated, 2 - has calculated
vpii adj[N];

void shortest_paths(int u){
    deque <int> qu;
    msetinf(dist);
    msetn1(par);
    qu.push_back(u);
    dist[u] = 0;
    while (!qu.empty()) {
        int t = qu.front();
        q.pop_front();
        mval[t] = 2;
        Fora(v, adj[t]){
            if (dist[v.fi] > dist[t] + v.se){
                dist[v.fi] = dist[t] + v.se;
                par[v.fi] = t;
                mval[v.fi] = 1;
                if (mval[v.fi] == 0){
                    q.push_back(v.fi);
                }
                else if (mval[v.fi] == 2){
                    qu.push_front(v.fi);
                }
            }
        }
    }
}
