#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;

#define min(a, b) ((a) < (b) ? (a) : (b))
int tot = 0;
int a[N];

struct SegmentTree{
    int f[N << 2];
    void build(int p, int l, int r){
        if(l == r){
            f[p] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        f[p] = min(f[p << 1], f[p << 1 | 1]);
    }
    int query(int p, int l, int r, int ql, int qr){
        cout<<p<<" ";
        tot += 1;
        if(l > qr || r < ql) return inf;
        if(l >= ql && r <= qr){
            return f[p];
        }
        int mid = (l + r) >> 1;
        return min(query(p << 1, l, mid, ql, qr), query(p << 1 | 1, mid + 1, r, ql, qr));
    }
}seg;


int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    seg.build(1, 1, n);
    while(q > 0){
        int l, r;
        tot = 0;
        cin >> l >> r;
        seg.query(1, 1, n, l, r);
        cout<<'\n';
        cout << tot << endl;
        q -= 1;
    }
    return 0;
}
