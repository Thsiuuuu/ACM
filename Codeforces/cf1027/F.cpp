#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 

ll ans1,ans2;
ll x,y,k;

struct node{
    ll number;
    ll cnt;
};

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

bool judge(vector<node> &a,ll val){
    for(int i=2;i*i<=val;i++){
        if(val%i==0){
            if(i>k){
                return false;
            }
            int count=0;
            while(val%i==0){
                val/=i;
                count++;
            }
            a.push_back({i,count});
        }
    }
    if(val>1){
        if(val>k) return false;
        a.push_back({val,1});
    }
    return true;
}

void dfs(vector<node> &a,ll level,int curi,int starti,ll mul){
    
}


void sol() {

    cin>>x>>y>>k;
    if(x<y) swap(x,y);

    ans1=ans2=INT64_MAX;

    ll g=gcd(x,y);
    ll sub=x/g,add=y/g;
    vector<node> vecsub,vecadd;
    if(judge(vecsub,sub)&&judge(vecadd,add)){
        if(vecsub.size()){

        }else{
            ans1=0;
        }
        if(vecadd.size()){

        }else{
            ans2=0;
        }
    }else{
        cout<<"-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}