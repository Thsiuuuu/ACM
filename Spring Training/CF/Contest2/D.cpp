#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
void sol() {
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    vector<ll> cnt(28,0);
    ll ans=INT64_MAX;
    for(int i=m;i<s.size();i++) cnt[s[i]-'a'+1]++;

    if(!m){
        vector<ll> a=cnt;
        sort(a.begin()+1,a.end(),greater<ll>());
        ll res=0,sum=0;
        for(int i=2;i<=27;i++){
            // cout<<i<<" "<<res<<'\n';
            if(res+(i-1)*(a[i-1]-a[i])>=k){
                int number=(k-res)%(i-1);
                for(int j=1;j<=i-1;j++){
                    if(number) sum+=(a[i-1]-(k-res)/(i-1)-1)*(a[i-1]-(k-res)/(i-1)-1),number--;
                    else sum+=(a[i-1]-(k-res)/(i-1))*(a[i-1]-(k-res)/(i-1));
                }
                for(int j=i;j<=26;j++){
                    sum+=(a[j]*a[j]);
                }
                ans=min(ans,sum);
                break;
            }else res+=(i-1)*(a[i-1]-a[i]);
        }
        cout<<ans<<'\n';
        return ;
    }

    for(int l=0,r=m-1;r<s.size();l++,r++){
        if(l!=0){
            cnt[s[l-1]-'a'+1]++,cnt[s[r]-'a'+1]--;
        }
        // cout<<l<<'\n';
        // for(int i=1;i<=26;i++) cout<<i<<" "<<cnt[i]<<'\n';
        vector<ll> a=cnt;
        sort(a.begin()+1,a.end(),greater<ll>());
        ll res=0,sum=0;
        for(int i=2;i<=27;i++){
            // cout<<i<<" "<<res<<'\n';
            if(res+(i-1)*(a[i-1]-a[i])>=k){
                int number=(k-res)%(i-1);
                for(int j=1;j<=i-1;j++){
                    if(number) sum+=(a[i-1]-(k-res)/(i-1)-1)*(a[i-1]-(k-res)/(i-1)-1),number--;
                    else sum+=(a[i-1]-(k-res)/(i-1))*(a[i-1]-(k-res)/(i-1));
                }
                for(int j=i;j<=26;j++){
                    sum+=(a[j]*a[j]);
                }
                ans=min(ans,sum);
                break;
            }else res+=(i-1)*(a[i-1]-a[i]);
        }
    }
    cout<<ans<<'\n';
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