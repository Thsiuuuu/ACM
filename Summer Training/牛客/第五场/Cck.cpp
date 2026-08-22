#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
vector<int> p;
VII all;
void out(VI p){
    for(int i=0;i<p.size();i++){
        cout<<p[i]<<" ";
    }
    cout<<'\n';
}
bool ck1(VI&p){
    for(int i=0;i<p.size();i++){
        if((!(i%2))!=p[i]) return false;
    }
    return true;
}
bool ck2(VI&p){
    for(int i=1;i<=p.size();i++){
        if(p[i-1]!=i) return false;
    }
    return true;
}
bool ck3(VI&p1,VI&p2){
    for(int i=0;i<p1.size();i++){
        if(p1[i]==p2[i]) return false;
    }
    return true;
}
bool ck4(VI p1){
    int siz=p1.size();
    sort(p1.begin(),p1.end());
    p1.erase(unique(p1.begin(),p1.end()),p1.end());
    return p1.size()==siz;
}
void o1(){
    cout<<"!\n";
}
void sol() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    vector<int> p(n);
    iota(p.begin(),p.end(),0);
    do{
        // out(p);
        all.push_back(p);
    }while(next_permutation(p.begin(),p.end()));
    for(int i=0;i+2<all.size();i++){
        for(int j=i+1;j+1<all.size();j++){
            vector<int> st;
            bool f=true;
            int jin=0;
            for(int idx=0;idx<all[i].size();idx++){
                if(all[i][idx]==all[j][idx]){
                    f=false;
                    break;
                }
                st.push_back((jin+all[i][idx]+all[j][idx])%n);
                jin=(jin+all[i][idx]+all[j][idx])/n;
            }
            if(f&&st.size()==n&&ck3(all[i],st)&&ck3(all[j],st)&&ck4(st)){
                cout<<"YES\n";
                for(int num:all[i]) cout<<num<<" ";
                cout<<'\n';
                for(int num:all[j]) cout<<num<<" ";
                cout<<'\n';
                for(int num:st) cout<<num<<" ";
                cout<<'\n';
                // return ;
            }

            // for(int k=0;k<all.size();k++){
            //     if(i==k||j==k) continue;
            //     int jin=0;
            //     bool f=true;
            //     if(f&&!jin
            //         // &&all[k][0]==0
            //     ){
            //         cout<<"YES\n";
            //         for(int num:all[i]) cout<<num<<" ";
            //         cout<<'\n';
            //         for(int num:all[j]) cout<<num<<" ";
            //         cout<<'\n';
            //         for(int num:all[k]) cout<<num<<" ";
            //         cout<<'\n';
            //         jin=0;
            //         for(int idx=0;idx<all[i].size();idx++){
            //             cout<<((jin+all[i][idx]+all[j][idx])>=n)<<" ";
            //             // tmp.push_back(((jin+all[i][idx]+all[j][idx])>=n));
            //             jin=(jin+all[i][idx]+all[j][idx])/n;
            //         }
            //         cout<<"\n###########\n";
            //         return ;
            //         // vector<int> tmp;
            //         // int jin=0;
            //         // for(int idx=0;idx<all[i].size();idx++){
            //         //     // cout<<((jin+all[i][idx]+all[j][idx])>=n)<<" ";
            //         //     tmp.push_back(((jin+all[i][idx]+all[j][idx])>=n));
            //         //     jin=(jin+all[i][idx]+all[j][idx])/n;
            //         // }
            //         // if(ck1(tmp)
            //         // // &&ck2(all[i])
            //         // ){
            //         // }
            //         // return ;
            //     }
            // }
        }
    }
    cout<<"NO";
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