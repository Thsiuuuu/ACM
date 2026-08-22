#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

    4 8
3 4 1 8
4 7 1 8 4
5 6 5 1 2 3
4 3 2 4 8
*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

int mp[5][5];
int l,n;
int ans=0;
int x[5],y[5];

void dfs(int i,int j){
    // if(ans>3) return ;
    if(i>n){
        bool f=true;
        for(int i=1;i<=n;i++){
            if(x[i]!=l){
                f=false;
                break;
            } 
        }
        if(f){
            for(int j=1;j<=n;j++){
                if(y[j]!=l){
                    f=false;
                    break;
                } 
            }
        }
        if(f) ans++;
        return ;
    }
    if(j==n){
        int number=l-x[i];
        if(y[j]+number>l) return ;
        else{
            x[i]=l,y[j]+=number;
            dfs(i+1,1);
            x[i]-=number,y[j]-=number;
        }
    }else{
        for(int number=0;number+max(x[i],y[j])<=l;number++){
            x[i]+=number,y[j]+=number;
            dfs(i,j+1);
            x[i]-=number,y[j]-=number;
        }   
    }
}

void sol() {
    cin>>l>>n;
    dfs(1,1);
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}