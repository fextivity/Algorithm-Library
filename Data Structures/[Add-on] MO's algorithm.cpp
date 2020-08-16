const int S = log2(Q) + 1;

ll gilbertOrder(int x, int y){
    ll d = 0;
    for (int s = 1 << (S - 1); s; s >>= 1){
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry){
            if (rx){
                x = (1 << S) - x;
                y = (1 << S) - y;
            }
            swap(x, y);
        }
    }
    return d;
}

struct Query{
    int l, r, idx;
    ll ord;

    void calcOrder(){
        ord = gilbertOrder(l, r);
    }
    
    bool operator< (const Query &it) const{
    	return ord < it.ord;
	}
};
