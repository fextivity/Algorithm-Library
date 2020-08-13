const int N = 1e5 + 5, K = 26;

void add(string s);
int go(int cur, char ch);
int getlink(int cur);
int getexlink(int cur);

int len[N];
vi ans[N];

struct Vertex{
    int next[K];
    bool leaf = false;
    int p = -1; // parent
    char pch; // edge from p -> this
    int link = -1; // suffix link
    int exlink = -1; // exit suffix link
    int go[K]; // transition
    vi endidx;

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector <Vertex> aho(1);

void add(string s, int toxic){
    int cur = 0;
    Fora(ch, s){
        if (aho[cur].next[ch - 'a'] == -1){
            aho[cur].next[ch - 'a'] = aho.size();
            aho.eb(cur, ch);
        }
        cur = aho[cur].next[ch - 'a'];
    }
    aho[cur].leaf = true;
    aho[cur].endidx.pb(toxic);
}

int go(int cur, char ch){
    if (aho[cur].go[ch - 'a'] == -1){
        if (aho[cur].next[ch - 'a'] == -1){
            aho[cur].go[ch - 'a'] = (cur == 0 ? 0 : go(getlink(cur), ch));
        }
        else{
            aho[cur].go[ch - 'a'] = aho[cur].next[ch - 'a'];
        }
    }
    return aho[cur].go[ch - 'a'];
}

int getlink(int cur){
    if (aho[cur].link == -1){
        if (cur == 0 || aho[cur].p == 0){
            aho[cur].link = 0;
        }
        else{
            aho[cur].link = go(getlink(aho[cur].p), aho[cur].pch);
        }
    }
    return aho[cur].link;
}

int getexlink(int cur){
    if (aho[cur].exlink == -1){
        int nxt = aho[cur].link;
        if (cur == 0 || nxt == 0){
            aho[cur].exlink = 0;
        }
        else if (aho[nxt].leaf){
            aho[cur].exlink = nxt;
        }
        else{
            aho[cur].exlink = getexlink(nxt);
        }
    }
    return aho[cur].exlink;
}

void traverse(string s){
    int cur = 0;
    For(i, 0, s.length()){
        cur = go(cur, s[i]);
        int tcur = cur;
        while (tcur){
            if (aho[tcur].leaf){
                Fora(v, aho[tcur].endidx){
                    ans[v].pb(i);
                }
            }
            tcur = aho[tcur].exlink;
        }
    }
}

void init(){
    For(i, 0, aho.size()){
        getlink(i);
    }
    For(i, 0, aho.size()){
        getexlink(i);
    }
}
