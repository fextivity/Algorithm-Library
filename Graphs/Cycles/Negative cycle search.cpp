int n;
int dist[N], par[N];
vpii adj[N];
vi cycle;

bool find_negative_cycle(){
    msetinf(dist);
    msetn1(par);
    int cycle_start;
    ForE(cnt, 1, n){
        cycle_start = -1;
        ForE(t, 1, n){
            Fora(v, adj[t]){
                if (dist[v.fi] > dist[t] + v.se){
                    dist[v.fi] = dist[t] + v.se;
                    par[v.fi] = t;
                    cycle_start = v.fi;
                }
            }
        }
    }

    if (cycle_start == -1){
        return 0;
    }
    ForE(cnt, 1, n){
        cycle_start = par[cycle_start];
    }
    cycle.pb(cycle_start);
    for (int i = par[cycle_start]; i != cycle_start; i = par[i]){
        cycle.pb(i);
    }
    reverse(bend(cycle));
    return 1;
}
