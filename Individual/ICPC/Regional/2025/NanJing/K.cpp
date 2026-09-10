#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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

int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};

int bx[8]={0,1,1,0,0,-1,-1,0};
int by[8]={1,0,0,-1,-1,0,0,1};

int rx[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};

int res[10][11][10][11][2];
int deg[10][11][10][11][2];

struct Node{
    int x1,y1,x2,y2,is;
};

bool ck(int x,int y){
    return x>=1&&x<=9&&y>=1&&y<=10;
}

void init(){
    queue<Node> q;
    for(int x1=1;x1<=9;x1++){
        for(int y1=1;y1<=10;y1++){
            for(int x2=1;x2<=9;x2++){
                for(int y2=1;y2<=10;y2++){
                    if(x1==x2&&y1==y2)continue;
                    bool is1=false;
                    for(int d=0;d<8;d++){
                        int nx=x1+dx[d],ny=y1+dy[d];
                        int lx=x1+bx[d],ly=y1+by[d];
                        if(ck(nx,ny)&&(lx!=x2||ly!=y2)){
                            deg[x1][y1][x2][y2][0]++;
                            if(nx==x2&&ny==y2)is1=true;
                        }
                    }
                    bool is2=false;
                    for(int d=0;d<4;d++){
                        int nx=x2+rx[d],ny=y2+ry[d];
                        while(ck(nx,ny)){
                            deg[x1][y1][x2][y2][1]++;
                            if(nx==x1&&ny==y1){
                                is2=true;
                                break;
                            }
                            nx+=rx[d];
                            ny+=ry[d];
                        }
                    }
                    if(is1){
                        res[x1][y1][x2][y2][0]=1;
                        q.push({x1,y1,x2,y2,0});
                    }
                    if(is2){
                        res[x1][y1][x2][y2][1]=1;
                        q.push({x1,y1,x2,y2,1});
                    }
                }
            }
        }
    }
    while(!q.empty()){
        auto [x1,y1,x2,y2,is]=q.front();
        q.pop();
        int cur=res[x1][y1][x2][y2][is];
        if(is==0){
            for(int d=0;d<4;d++){
                int px2=x2-rx[d],py2=y2-ry[d];
                while(ck(px2,py2)){
                    if(px2==x1&&py2==y1)break;
                    if(res[x1][y1][px2][py2][1]==0){
                        if(cur==-1){
                            res[x1][y1][px2][py2][1]=1;
                            q.push({x1,y1,px2,py2,1});
                        }else if(cur==1){
                            deg[x1][y1][px2][py2][1]--;
                            if(deg[x1][y1][px2][py2][1]==0){
                                res[x1][y1][px2][py2][1]=-1;
                                q.push({x1,y1,px2,py2,1});
                            }
                        }
                    }
                    px2-=rx[d];
                    py2-=ry[d];
                }
            }
        }else{
            for(int d=0;d<8;d++){
                int px1=x1-dx[d],py1=y1-dy[d];
                int lx=px1+bx[d],ly=py1+by[d];
                if(ck(px1,py1)&&(px1!=x2||py1!=y2)){
                    if(lx!=x2||ly!=y2){
                        if(res[px1][py1][x2][y2][0]==0){
                            if(cur==-1){
                                res[px1][py1][x2][y2][0]=1;
                                q.push({px1,py1,x2,y2,0});
                            }else if(cur==1){
                                deg[px1][py1][x2][y2][0]--;
                                if(deg[px1][py1][x2][y2][0]==0){
                                    res[px1][py1][x2][y2][0]=-1;
                                    q.push({px1,py1,x2,y2,0});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void sol(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<(res[x1][y1][x2][y2][0]==-1?"YES\n":"NO\n");
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    init();
    int t = 1;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}