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
ll f[51][51];
bool ck1(ll p, ll S,ll cnt,ll k,ll h){
    return ((i128)p*(k)+k*(k+1)/2*S)*cnt<h;
}
ostream& operator<<(ostream& out,i128 x){
    if(x==0) return out<<0;
    if(x<0){
        out<<'-';
        x=-x;
    }
    string s;
    while(x){
        s+=char('0'+x%10);
        x/=10;
    }
    reverse(s.begin(),s.end());
    return out<<s;
}
void sol() {
    ll n,p,h;cin>>n>>p>>h;
    int cnt=0;
    VL add,mul;
    for(int i=0;i<n;i++) {
        char op;cin>>op;
        // cout<<op<<'\n';
        if(op=='!') cnt++;
        else if(op=='+') {
            ll x;cin>>x;
            add.push_back(x);
        }else{
            ll x;cin>>x;
            mul.push_back(x);
        }
    }
    sort(add.begin(),add.end(),greater<ll>());
    sort(mul.begin(),mul.end(),greater<ll>());
    if(cnt==0||(!p&&add.size()==0)){
        cout<<"*";
        return ;
    }
    if(p>=h){
        cout<<"1";
        return ;
    }
    i128 ori=p;
    int obj=0;
    ll hurt=0;
    if(mul.size()==0||mul[0]==1){
        // cerr<<"1\n";
        ll S=0;
        for(ll x:add) S+=x;
        // ll up1=h/(S*cnt);?
        ll up1;
        if(S) up1=h/(S*cnt);
        else {
            int number=(h+p-1)/p;
            cout<<((number-1)/cnt*n+(number-1)%cnt+1);
            // cout<<(h/(p*cnt)*n+h%(p*cnt)/p);
            return ;
        }
        // cerr<<up1<<" "<<S<<'\n';
        int l=0,r=up1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(ck1(p,S,cnt,mid,h)){
                l=mid+1;
                obj = mid;
            }else{
                r=mid-1;
            }
        }
        // cerr<<"1\n";
        // cerr<<obj<<'\n';
        hurt=((i128)p*(obj)+obj*(obj+1)/2*S)*cnt;
        ll rem=h-hurt;
        ll mn=1e9;
        hurt=p+obj*S;
        if(hurt) {
            if((rem+hurt-1)/hurt<=cnt) mn=(rem+hurt-1)/hurt;
        }
        for(ll i=0,pre=0;i<add.size();i++){
            if(pre>=rem) break;
            pre+=add[i];
            if(pre>=rem){
                mn=min(mn,i+1+1);
                break;
            }
            if((rem+pre+hurt-1)/(hurt+pre)<=cnt) mn=min(mn,i+1+(rem+pre+hurt-1)/(hurt+pre));
        }   
        // cerr<<mn<<'\n';
        cout<<obj*n+mn;
    }else{
        bool is=true;
        int number=0;
        // cout<<"1\n";
        obj=0;
        while(1){
            i128 oori=ori;
            for(int i=0;i<add.size();i++){
                if(oori>h){
                    is=false;
                    break;
                }
                oori+=add[i];
            }
            for(int i=0;i<mul.size();i++){
                if(oori>h){
                    is=false;
                    break;
                }
                oori*=mul[i];
            }
            if(!is) break;
            i128 hhurt=0;
            for(int i=0;i<cnt;i++){
                hhurt+=oori;
            }
            if(hurt+hhurt>=h) break;
            ori=oori;
            obj++;
            hurt+=hhurt;
        }
        // cout<<ori<<'\n';
        ////hurt 上海总量，obj未尽人
        ll rem=h-hurt;
        ll copyori=ori;
        swap(copyori,hurt);
        for(int i=0;i<51;i++) for(int j=0;j<51;j++) f[i][j]=1e18;
        f[0][0]=hurt;
        for(int i=0;i<add.size();i++){
            f[i+1][0]=(ll)min((i128)h,(i128)f[i][0]+add[i]);
            if(f[i+1][0]>=(1e18)) break;
        }
        for(int i=0;i<=add.size();i++){
            if(f[i+1][0]>=(1e18)) break;
            for(int j=0;j<mul.size();j++){
                f[i+1][j+1]=(ll)min((i128)h,(i128)f[i+1][j]*mul[j]);
                if(f[i+1][j+1]>=(1e18)) break;
            }
        }
        ll mn=1e9;
        // cout<<obj<<'\n';
        // cout<<hurt<<'\n';
        // cout<<rem<<'\n';
        for(int i=1;i<=add.size();i++){
            if(f[i][0]>(1e18)) break;
            for(int j=0;j<=mul.size();j++){
                if(f[i][j]>(1e18)) break;
                if((rem+f[i][j]-1)/f[i][j]>cnt) continue;
                // cerr<<i<<" "<<j<<" "<<f[i][j]<<'\n';
                mn=min(mn,i+j+(rem+f[i][j]-1ll)/f[i][j]);
            }
        }
        if(hurt) {
            if((rem+hurt-1)/hurt<=cnt) mn=min(mn,(rem+hurt-1)/hurt);
        }
        for(ll i=0,pre=0;i<add.size();i++){
            if(pre>=rem) break;
            pre+=add[i];
            if(pre>=rem){
                mn=min(mn,i+1+1);
                break;
            }
            if((rem+hurt+pre-1)/(hurt+pre)<=cnt) mn=min(mn,i+1+(rem+hurt+pre-1)/(hurt+pre));
        }
        if(hurt){
            i128 pre=1;
            for(ll i=0;i<mul.size();i++){
                if(pre*hurt>=rem) break;
                pre*=mul[i];
                if(pre*hurt>=rem){
                    mn=min(mn,i+1+1);
                }
                if((rem+hurt*pre-1)/(hurt*pre)<=cnt) mn=min(mn,(ll)(i+1+(rem+hurt*pre-1)/(hurt*pre)));
            }
        }
        // cerr<<mn<<'\n';
        // cout<<obj*n+mn;
        // cout<<mn<<'\n';
        // cout<<obj<<'\n';
        cout<<obj*n+mn;
    }
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