#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=2e4+10;
int n;
vector<int> e[N];
bool vis[N];
int siz[N];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void getSize(int u,int fa){
    siz[u]=1;
    for(int v:e[u]){
        if(v!=u&&vis[v]){
            getSize(v,u);
            siz[u]+=siz[v];
        }
    }
}

int getRoot(int u,int fa){
    getSize(u,fa);
    int half=siz[u]>>1;
    bool find=false;
    while(!find){
        find=true;
        for(int v:e[u]){
            if(v!=fa&&!vis[v]&&siz[v]>half){
                fa=u;
                u=v;
                find=false;
                break;
            }
        }
    }
    return u;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


}