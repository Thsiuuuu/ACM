#include <bits/stdc++.h>
using namespace std;
/*

    1 1 4 5 1 4
    1 9 1 9 8 1
    3 5 0 2 3 4
    3 1 0 1 1 0
    1 9 9 7 0 1
    0 9 3 7 2 4

    1 1 4 5 1 4
    1 9 1 9 8 1
    3 5 0 2 3 4
    3 1 0 1 1 0
    1 9 9 7 0 1
    0 9 3 15 2 4

    1 1 4 5 1 4
    1 9 1 9 8 1
    3 13 0 2 3 4
    3 1 0 1 1 0
    1 9 9 7 0 1
    0 9 3 15 2 4

*/
#define ll long long 
const int N=510;
ll a[N][N];

void sol() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int maxx=1,maxy=1;
    ll maxval=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll val=0;
            for(int x=i-2;x<=i+2;x++){
                for(int y=j-2;y<=j+2;y++){
                    if(abs(x-i)+abs(y-j)>2){
                        continue;
                    }
                    if(x>=1&&x<=n&&y>=1&&y<=m){
                        val+=a[x][y];
                    }
                }
            }
            if(val>maxval){
                maxx=i,maxy=j,maxval=val;
            }
        }
    }
    while(q--){
        int xi,yi;
        ll zi;
        cin>>xi>>yi>>zi;
        a[xi][yi]+=zi;
        for(int i=xi-2;i<=xi+2;i++){
            for(int j=yi-2;j<=yi+2;j++){
                if(i<1||i>n||j<1||j>m||abs(i-xi)+abs(j-yi)>2){
                    continue;
                }
                ll val=0;
                for(int x=i-2;x<=i+2;x++){
                    for(int y=j-2;y<=j+2;y++){
                        if(abs(x-i)+abs(y-j)>2){
                            continue;
                        }
                        if(x>=1&&x<=n&&y>=1&&y<=m){
                            val+=a[x][y];
                        }
                    }
                }
                if(val>maxval){
                    maxx=i,maxy=j,maxval=val;
                }
            }
        }
        cout<<maxx<<" "<<maxy<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}