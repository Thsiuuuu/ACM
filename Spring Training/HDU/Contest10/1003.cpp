#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
struct Point{
    int x,y;
}a[4],b[4];
int f[4][4];
void sol() {
    int n;
    cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            f[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;

        f[a[i].x][a[i].y]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].x>>b[i].y;
        f[b[i].x][b[i].y]=2;
    }
    if(n<=1){
        cout<<"Columbina Hyposelenia\n";
        return ;
    }
    auto P1=a[n-1],P2=a[n];
    int Ansx=-1,Ansy=-1;
    if(P1.x==P2.x){
        for(int y=1;y<=3;y++){
            if(f[P1.x][y]==2){
                cout<<"Columbina Hyposelenia\n";
                return ;
            }else if(!f[P1.x][y]){
                Ansx=P1.x,Ansy=y;
            }
        }
        if(Ansx+Ansy==-2){
            Ansx=a[1].x,Ansy=a[1].y;
        }
        cout<<Ansx<<" "<<Ansy<<'\n';
        return ;
    }
    if(P1.y==P2.y){
        for(int x=1;x<=3;x++){
            if(f[x][P1.y]==2){
                cout<<"Columbina Hyposelenia\n";
                return ;
            }else if(!f[x][P1.y]){
                Ansx=x,Ansy=P1.y;
            }
        }
        if(Ansx+Ansy==-2){
            Ansx=a[1].x,Ansy=a[1].y;
        }
        cout<<Ansx<<" "<<Ansy<<'\n';
        return ;
    }
    if(P1.x==P1.y&&P2.x==P2.y){
        for(int x=1,y=1;x<=3;x++,y++){
            if(f[x][y]==2){
                cout<<"Columbina Hyposelenia\n";
                return ;
            }else if(!f[x][y]){
                Ansx=x,Ansy=y;
            }
        }
        if(Ansx+Ansy==-2){
            Ansx=a[1].x,Ansy=a[1].y;
        }
        cout<<Ansx<<" "<<Ansy<<'\n';
        return ;
    }
    if(P1.x+P1.y==4&&P2.x+P2.y==4){
        for(int x=1,y=3;x<=3;x++,y--){
            if(f[x][y]==2){
                cout<<"Columbina Hyposelenia\n";
                return ;
            }else if(!f[x][y]){
                Ansx=x,Ansy=y;
            }
        }
        if(Ansx+Ansy==-2){
            Ansx=a[1].x,Ansy=a[1].y;
        }
        cout<<Ansx<<" "<<Ansy<<'\n';
        return ;
    }
    cout<<"Columbina Hyposelenia\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}