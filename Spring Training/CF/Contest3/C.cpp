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

const int K=1e5+2;  
bool is[K][26];
int cnt[K][26];
struct node{
    // int idx;
    ll tim;
    int number=0;
    bool operator<(const node&other)const{
        if(number==other.number) return tim<other.tim;
        return number<other.number;
    }
};


void sol() {
    int k,n;
    cin>>k>>n;
    vector<node> p(k+1);
    // vector<int> mp(k+1);
    /*
    
        mp搞一个映射，索引指向->node数组的索引
    
    */
    // iota(mp.begin(),mp.end());
    int last=1;
    for(int i=1;i<=n;i++){
        string s,result;
        char id;
        int name;
        cin>>s>>name>>id>>result;
        if(is[name][id-'0']) continue;//做对了，就跳过
        int last=1,cur=1;
        if(name==0&&result=="AC"){
            for(int i=1;i<=k;i++){
                // mp[p[i].idx]=i;
                if(p[i].number>p[0].number||(p[i].number==p[0].number&&p[i].tim<p[0].tim)) last++;
            }
        }
        if(result=="AC"){
            is[name][id-'0']=true;
            p[name].tim+=(60*stoll(s.substr(0,2))+stoll(s.substr(3,2))+20*cnt[name][id-'0']);
            p[name].number++;
        }else if(result=="RJ"){
            cnt[name][id-'0']++;
        }
        if(name==0&&result=="AC"){
            for(int i=1;i<=k;i++){
                if(p[i].number>p[0].number||(p[i].number==p[0].number&&p[i].tim<p[0].tim)) cur++;
            }
            cout<<s<<" "<<id<<" "<<"#"<<last<<" -> #"<<cur<<'\n';
        }
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