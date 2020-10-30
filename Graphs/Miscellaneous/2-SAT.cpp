int n, m;

int f(int x, int y){
	return x + (y ? n : 0);
}

vi adj[2 * N], radj[2 * N];
bool ck[2 * N];
int posscc[2 * N];
vi topo, cpn;
vvi scc;
int ans[N];

void dfs(int u){
    ck[u] = true;
    Fora(v, adj[u]){
        if (!ck[v]){
            dfs(v);
        }
    }
    topo.pb(u);
}

void toposort(){
    mset(ck);
    ForE(i, 1, 2 * n){
        if (!ck[i]){
            dfs(i);
        }
    }
    reverse(bend(topo));
}

void dfs2(int u){
    ck[u] = true;
    cpn.pb(u);
    Fora(v, radj[u]){
        if (!ck[v]){
            dfs2(v);
        }
    }
}

void find_scc(){
    toposort();
    mset(ck);
    For(i, 0, 2 * n){
        if (!ck[topo[i]]){
            cpn.clear();
            dfs2(topo[i]);
            scc.pb(cpn);
        }
    }
}

bool twosat(){
    find_scc();
    For(i, 0, scc.size()){
    	Fora(v, scc[i]){
    	    posscc[v] = i;
    	}
    }
    ForE(i, 1, n){
    	if (posscc[f(i, 0)] == posscc[f(i, 1)]){
    	    return 0;
    	}
    }
    ForE(i, 1, n){
    	if (posscc[f(i, 0)] > posscc[f(i, 1)]){
    	    ans[i] = 0;
    	}
    	else{
    	    ans[i] = 1;
    	}
    }
    return 1;
}
