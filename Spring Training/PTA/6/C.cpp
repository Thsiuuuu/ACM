#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long 

struct node{
    pii i1,i2,i3;
    node(pii i1,pii i2,pii i3):i1(i1),i2(i2),i3(i3){}
    bool operator<(const node&other)const{
        if(i2.first==other.i2.first) return i1.first<other.i1.first;
        return i2.first<other.i2.first;
    }
    bool operator==(const node&other)const{
        return i1==other.i1&&i2==other.i2&&i3==other.i3;
    }
};

vector<int> a[3];
void sol(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[y].push_back(x);

    }
    for(int i=0;i<3;i++){
        sort(a[i].begin(),a[i].end());
        a[i].erase(unique(a[i].begin(),a[i].end()),a[i].end());
    }

    vector<node> ans;
    for(const auto key:a[0]){
        for(const auto key1:a[1]){
            if(abs(2*key1-key)<=1e6){
                auto it=lower_bound(a[2].begin(),a[2].end(),(2*key1-key));
                if(it!=a[2].end()&&*it==(2*key1-key)){
                    ans.push_back(node({key,0},{key1,1},{2*key1-key,2}));
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    // ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0;i<ans.size();i++){
        auto [i1,i2,i3]=ans[i];
        cout<<"["<<i1.first<<", 0] ["<<i2.first<<", 1] ["<<i3.first<<", 2]\n";
    }
    if(ans.size()==0) cout<<"-1";
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