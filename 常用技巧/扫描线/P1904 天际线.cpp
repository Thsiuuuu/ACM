#include <bits/stdc++.h>
using namespace std;
/*



*/

struct node{
    int l,r,h;
    // int time;
    bool operator<(const node&other)const{
        return h<other.h;
    }
};


void sol() {
    int l,r,h;
    vector<node> vec;
    while(cin>>l>>r>>h){
        vec.push_back({l,r,h});
    }
    priority_queue<node,vector<node>> que;
    sort(vec.begin(),vec.end(),[](const node&a,const node&b){
        if(a.l==b.l){
            return a.r<b.r;
        }else{
            return a.l<b.l;
        } 
    });
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}