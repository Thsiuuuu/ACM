#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pll pair<ll,ll> 

vector<pll> check;
vector<int> L,R;
vector<ll> a;

ll query(ll val,int l,int r){
    auto i1=lower_bound(check.begin(),check.end(),make_pair(val,-1ll));
    if(i1==check.end()||i1->first!=val) return 0;
    auto i2=upper_bound(check.begin(),check.end(),make_pair(val,1145141919810));
    auto l1=lower_bound(i1,i2,make_pair(val,(ll)l));
    auto l2=upper_bound(i1,i2,make_pair(val,(ll)r));
    return (ll)distance(l1,l2);
}

void sol(){
    int n;cin>>n;
    ll ans=0;
    
    check.clear();
    L.assign(n+1,0),R.assign(n+1,0),a.assign(n+1,0);
    stack<int> stk;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        check.push_back({a[i],(ll)i});
    }
    sort(check.begin(),check.end());
    for(int i=1;i<=n;i++){
        while(stk.size()&&a[stk.top()]<=a[i]) stk.pop();
        L[i]=((stk.empty())?1:stk.top());
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    for(int i=n;i>=1;i--){
        while(stk.size()&&a[stk.top()]<a[i]) stk.pop();
        R[i]=((stk.empty())?n:stk.top());
        stk.push(i);
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2==0) continue;
        int Len=i-L[i]+1,Ren=R[i]-i+1;
        if(Len<=Ren){
            for(int j=L[i];j<=i;j++){
                ans+=query(a[i]-a[j]+1,i,R[i]);
            }
        }else{
            for(int j=i;j<=R[i];j++){
                ans+=query(a[i]-a[j]+1,L[i],i);
            }
        }
    }
    cout<<(ll)n*n-2*ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;cin>>t;
    while(t--){
        sol();
    }
    return 0;
}