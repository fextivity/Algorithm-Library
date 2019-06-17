int n;
int dist[N];
vpii adj[N]; // fi : node label, se: edge weight

// Find minimum distance from node u to all other nodes
// Complexity : O(ElogE)
void dijkstra(int u){
    pque <pii, vpii, greater <pii > > pq;
    mmset(h);
    pq.push({0, u});
    dist[u] = 0;
    while (!pq.empty()){
        int t = pq.top().se;
        pq.pop();
        Fora(v, adj[t]){
            if (dist[v.fi] > dist[t] + v.se){
                dist[v.fi] = dist[t] + v.se;
                pq.push({dist[v.fi], v.fi});
            }
        }
    }
}