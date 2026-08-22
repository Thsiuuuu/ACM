#include <bits/stdc++.h>
using  namespace std;
#define ll long long 
#define pii pair<int,int>


int a[330];
int vis[330];
int l,r;
int fa[10010];


bool dfs1(int cur){
    if(vis[cur]&&(!a[cur])){
        return false;
    }
    if(vis[cur]&&a[cur]) return true;
    if(cur==1){
        a[cur]=1;
        return true;
    }
    vis[cur]=1;
    auto s=to_string(cur);
    int number=0;
    for(int i=0;i<s.size();i++){
        number+=pow(s[i]-'0',2);
    }
    a[cur]=dfs1(number);
    return a[cur];
}

bool dfs2(int x,int cur){
    if(cur==1){
        return false;
    }
    if(cur==x) return true;
    auto s=to_string(cur);
    int number=0;
    for(int i=0;i<s.size();i++){
        number+=pow(s[i]-'0',2);
    }
    dfs2(x,number);
}

int dfs3(int cur){
    if(cur==1){
        return 0;
    }
    auto s=to_string(cur);
    int number=0;
    for(int i=0;i<s.size();i++){
        number+=pow(s[i]-'0',2);
    }
    return dfs3(number)+1;
}


void sol(){
    vis[1]=1,a[1]=1;
    for(int i=2;i<=324;i++){
        dfs1(i);
    }
    cin>>l>>r;
    bool f=false;
    for(int i=l;i<=r;i++){
        auto s=to_string(i);
        int number=0;
        for(int i=0;i<s.size();i++){
            number+=pow(s[i]-'0',2);
        }
        if(!a[number]) continue;
        bool check=false;
        for(int j=l;j<=r;j++){
            auto t=to_string(j);
            int number1=0;
            for(int i=0;i<t.size();i++){
                number1+=pow(t[i]-'0',2);
            }
            if(!a[number1]||!dfs2(number,number1)) continue;
            else{
                check=true;
                break;
            }
        }
        if(check) continue;
        
        int tot=dfs3(number);
        f=true;
        bool is=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                is=false;
                break;
            }
        }
        if(is) tot*=2;
    }
    if(!f) cout<<"SAD";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
} 