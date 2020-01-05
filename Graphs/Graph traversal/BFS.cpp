vi adj[N];
bool ck[N];

void bfs(int u){
    queue <int> qu;
    qu.push(u);
    while (!qu.empty()){
        int t = qu.front();
        qu.pop();
        ck[t] = 1;
        Fora(v, adj[t]){
            if (!ck[v]){
                qu.push(v);
            }
        }
    }
}
