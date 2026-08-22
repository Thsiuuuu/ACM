#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;

#define pii pair<int,int>

#define min(a, b) (((a) < (b)) ? (a) : (b))
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
    pii query(int p, int l, int r, int ql, int qr){
        // cout<<p<<' ';
        tot += 1;
        if(l > qr || r < ql||l>r) return make_pair(inf,1);
        if(l >= ql && r <= qr){
            return make_pair(f[p],1);
        }
        int mid = (l + r) >> 1;
        // int tmp=min(query(p << 1, l, mid, ql, qr), query(p << 1 | 1, mid + 1, r, ql, qr));
        // cout<<tmp<<" ";
        auto ls=query(p << 1, l, mid, ql, qr),
             rs=query(p << 1 | 1, mid + 1, r, ql, qr);

        if(ls.first<rs.first){
            ls.second=ls.second*2+1+rs.second;
            return ls;
        }else{
            rs.second=rs.second*2+1+ls.second;
            return rs;
        }
    }
}seg;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    seg.build(1, 1, n);
    // cout<<'\n';
    while(q > 0){
        int l, r;
        tot = 0;
        cin >> l >> r;
        auto tmp=seg.query(1, 1, n, l, r);
        // cout<<'\n';
        cout <<tmp.second<< endl;
        q -= 1;
    }
    return 0;
}
