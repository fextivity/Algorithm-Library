struct segment_tree{
    int seg[4 * N];
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int i, int val){
        if (i < l || r < i){
            return;
        }
        if (l == r){
            seg[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} it1;

struct lazy_segment_tree{
    int seg[4 * N], lazy[4 * N];
    
    void down(int id, int l, int r){
        int mid = (l + r) >> 1;
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
        seg[id << 1] += lazy[id] * (mid - l + 1);
        seg[id << 1 | 1] += lazy[id] * (r - mid);
        lazy[id] = 0;
    }
    
    void build(int id, int l, int r){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(int id, int l, int r, int u, int v, int val){
        if (v < l || r < u){
            return;
        }
        if (u <= l && r <= v){
            seg[id] += (r - l + 1) * val;
            lazy[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    int get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} it2;

struct segment_tree_2d{
    int seg[4 * N][4 * N];
    
    void build_y(int idx, int lx, int rx, int idy, int ly, int ry){
        if (ly == ry){
            if (lx == rx){
                seg[idx][idy] = a[lx][ly];
                return;
            }
            seg[idx][idy] = seg[idx << 1][idy] + seg[idx << 1 | 1][idy];
            return;
        }
        int midy = (ly + ry) >> 1;
        build_y(idx, lx, rx, idy << 1, ly, midy);
        build_y(idx, lx, rx, idy << 1 | 1, midy + 1, ry);
        seg[idx][idy] = seg[idx][idy << 1] + seg[idx][idy << 1 | 1];
    }
    
    void build_x(int idx, int lx, int rx){
        if (lx == rx){
            build_y(idx, lx, rx, 1, 1, m);
            return;
        }
        int midx = (lx + rx) >> 1;
        build_x(idx << 1, lx, midx);
        build_x(idx << 1 | 1, midx + 1, rx);
        build_y(idx, lx, rx, 1, 1, m);
    }
    
    void update_y(int idx, int lx, int rx, int idy, int ly, int ry, int x, int y, int val){
        if (y < ly || ry < y){
            return;
        }
        if (ly == ry){
            if (lx == rx){
                seg[idx][idy] += val;
                return;
            }
            seg[idx][idy] = seg[idx << 1][idy] + seg[idx << 1 | 1][idy];
            return;
        }
        int midy = (ly + ry) >> 1;
        update_y(idx, lx, rx, idy << 1, ly, midy, x, y, val);
        update_y(idx, lx, rx, idy << 1 | 1, midy + 1, ry, x, y, val);
        seg[idx][idy] = seg[idx][idy << 1] + seg[idx][idy << 1 | 1];
    }
    
    void update_x(int idx, int lx, int rx, int x, int y, int val){
        if (x < lx || rx < x){
            return;
        }
        if (lx == rx){
            update_y(idx, lx, rx, 1, 1, m, x, y, val);
            return;
        }
        int midx = (lx + rx) >> 1;
        update_x(idx << 1, lx, midx, x, y, val);
        update_x(idx << 1 | 1, midx + 1, rx, x, y, val);
        update_y(idx, lx, rx, 1, 1, m, x, y, val);
    }
    
    int get_y(int idx, int lx, int rx, int idy, int ly, int ry, int ux, int vx, int uy, int vy){
        if (vy < ly || ry < uy){
            return 0;
        }
        if (uy <= ly && ry <= vy){
            return seg[idx][idy];
        }
        int midy = (ly + ry) >> 1;
        return get_y(idx, lx, rx, idy << 1, ly, midy, ux, vx, uy, vy) +
               get_y(idx, lx, rx, idy << 1 | 1, midy + 1, ry, ux, vx, uy, vy);
    }
    
    int get_x(int idx, int lx, int rx, int ux, int vx, int uy, int vy){
        if (vx < lx || rx < ux){
            return 0;
        }
        if (ux <= lx && rx <= vx){
            return get_y(idx, lx, rx, 1, 1, m, ux, vx, uy, vy);
        }
        int midx = (lx + rx) >> 1;
        return get_x(idx << 1, lx, midx, ux, vx, uy, vy) +
               get_x(idx << 1 | 1, midx + 1, rx, ux, vx, uy, vy);
    }
} it3;

struct persistent_segment_tree{
    struct Vertex{
        int idxl, idxr;
        int val;
        
        Vertex(int idxl = -1, int idxr = -1, int val = 0): idxl(idxl), idxr(idxr), val(val) {}
    } seg[(4 + M) * N];
    
    vector <int> root;
    
    int segidx = 0;
    
    int build(int l, int r){
        if (l == r){
            int curidx = ++segidx;
            seg[curidx] = Vertex(-1, -1, a[l]);
            return curidx;
        }
        int mid = (l + r) >> 1;
        int lidx = build(l, mid);
        int ridx = build(mid + 1, r);
        int curidx = ++segidx;
        seg[curidx] = Vertex(lidx, ridx, max(seg[lidx].val, seg[ridx].val));
        return curidx;
    }
    
    int update(int idx, int l, int r, int i, int val){
        if (i < l || r < i){
            return idx;
        }
        if (l == r){
            int curidx = ++segidx;
            seg[curidx] = Vertex(-1, -1, val);
            return curidx;
        }
        int mid = (l + r) >> 1;
        int lidx = update(seg[idx].idxl, l, mid, i, val);
        int ridx = update(seg[idx].idxr, mid + 1, r, i, val);
        int curidx = ++segidx;
        seg[curidx] = Vertex(lidx, ridx, max(seg[lidx].val, seg[ridx].val));
        return curidx;
    }
    
    int get(int idx, int l, int r, int u, int v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[idx].val;
        }
        int mid = (l + r) >> 1;
        int ans = max(get(seg[idx].idxl, l, mid, u, v), get(seg[idx].idxr, mid + 1, r, u, v));
        return ans;
    }
} it4;
