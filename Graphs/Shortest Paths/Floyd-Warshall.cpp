int n;
int adj[N][N]; // 0 if i = j, inf if there is no edge, else weight of edge
int dist[N][N];

// Find shortest distance between all pairs in graph
// Complexity: O(n^3)
void floyd(){
    ForE(i, 1, n){
        ForE(j, 1, n){
            dist[i][j] = adj[i][j];
        }
    }
    ForE(k, 1, n){
        ForE(i, 1, n){
            ForE(j, 1, n){
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
