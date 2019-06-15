int n;
int h[N];
vpii adj[N]; // fi : node label, se: edge weight

// Complexity : O(ElogE)

void dijkstra(int u){
    pque <pii, vpii, greater <pii > > pq;
    mmset(h);
    pq.push({0, u});
    h[u] = 0;
    while (!pq.empty()){
        int t = pq.top().se;
        pq.pop();
        Fora(v, adj[t]){
            if (h[v.fi] > h[t] + v.se){
                h[v.fi] = h[t] + v.se;
                pq.push({h[v.fi], v.fi});
            }
        }
    }
}
