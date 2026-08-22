// 用传送门来让网格连通吧 
// 4000ms, 524288MB

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define int ll
#define pii pair<int,int>
const int _=50005, _m=998244353, INF=0x3f3f3f3f3f3f3f3fLL; 
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, k, q, color[_], cdx, idx, vis[_], he[_], hdx, ddx, dd[_], vd[_], vdx, mp[205][205];
char a[_];
vector<int> g[205];

inline int read() {
    register int x=0, f=0, ch;
    while(!isdigit(ch=getchar())) f|=ch=='-';
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
    return f?-x:x;
}

void solve() {
    n=read();
    m=read();
    k=read();
    q=read();
    ++idx;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            a[(i-1)*m+j]=getchar(); color[(i-1)*m+j]=0;
            if(a[(i-1)*m+j]=='#') {
                vis[(i-1)*m+j]=idx;
                color[(i-1)*m+j]=INF;
            }
        }
        getchar();
    }
    cdx=0; ++hdx; ++ddx; vdx=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!color[(i-1)*m+j]&&a[(i-1)*m+j]!='#') {
            	queue<pii> Q;
            	Q.push({i,j});
            	while(Q.size()){
            		auto [x,y]=Q.front();
            		Q.pop();
				    if(vis[(x-1)*m+y]==idx) return;
				    vis[(x-1)*m+y]=idx;
				    color[(x-1)*m+y]=cdx;
				    for(int i=0; i<4; i++) {
				        int tx=x+dx[i];
				        int ty=y+dy[i];
				        if(tx>=1&&tx<=n&&ty>=1&&ty<=m) Q.push({tx,ty});
				    }
				}
            }
        }
    }
    vector<pair<int, int>> e;
    for(int i=1; i<=k; i++) {
        int u1, v1, u2, v2;
        u1=read();
        v1=read();
        u2=read();
        v2=read();
        if(color[(u1-1)*m+v1]==color[(u2-1)*m+v2]) continue;
        he[color[(u1-1)*m+v1]]=hdx;
        if(dd[color[(u1-1)*m+v1]]!=ddx) {
            dd[color[(u1-1)*m+v1]]=ddx;
            vd[color[(u1-1)*m+v1]]=++vdx;
        }
        if(dd[color[(u2-1)*m+v2]]!=ddx) {
            dd[color[(u2-1)*m+v2]]=ddx;
            vd[color[(u2-1)*m+v2]]=++vdx;
        }
        e.push_back({vd[color[(u1-1)*m+v1]], vd[color[(u2-1)*m+v2]]});
    }
    for(int u=1; u<=vdx; u++) {
        g[u].clear();
        for(int v=1; v<=vdx; v++) {
            mp[u][v]=0;
        }
    }
    for(auto &[u, v]: e) {
        g[u].push_back(v);
    }
    for(int u=1; u<=vdx; u++) {
        ++idx;
        queue<int> Q;
        Q.push(u);
        while(Q.size()){
        	auto i=Q.front();
        	Q.pop();
		  	if(vis[i]==idx) return;
		    vis[i]=idx;
		    for(auto &v: g[i]) {
		        Q.push(v);
		    }
		}
        for(int v=1; v<=vdx; v++) {
            if(vis[v]==idx) {
                mp[u][v]=1;
            }
        }
    }
    for(int i=1; i<=q; i++) {
        int u1, v1, u2, v2;
        u1=read();
        v1=read();
        u2=read();
        v2=read();
        if(color[(u1-1)*m+v1]==color[(u2-1)*m+v2]) {
            printf("1\n"); continue;
        }
        if(he[color[(u1-1)*m+v1]]!=hdx) {
            printf("0\n"); continue;
        }
        if(mp[vd[color[(u1-1)*m+v1]]][vd[color[(u2-1)*m+v2]]]) {
            printf("1\n");
        }
        else printf("0\n");
    }
} //yunayu_2026_target_M

signed main() {
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // solve();
    int T; T=read(); while(T--) solve();
    return 0;
} //"只要不失去你的崇高，整个世界都会向你敞开"