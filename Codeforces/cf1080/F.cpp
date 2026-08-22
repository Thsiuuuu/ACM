#include <bits/stdc++.h>
using namespace std;
/*

    纵向不好想，尝试转化，无交点意味着是一个严格大于另外一个的
    严格大于可以建图解决，并且具有传递性
    也就是说求出来包含某个点i的最长链
    因为这个是一个有向无环图，所以说可以分别进行两次dp求出以i为终点的最长链和以i为起点的最长链

*/
#define ll long long 
struct node{
    ll a,b,c;
};

void sol() {
    int n;
    cin>>n;
    vector<node> f(n+1);
    vector<ll> in(n+1,0),out(n+1,0),dp1(n+1,0),dp2(n+1,0);
    vector<vector<int>> ein(n+1),eout(n+1);
    for(int i=1;i<=n;i++){
        cin>>f[i].a>>f[i].b>>f[i].c;
    }  
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i].a==f[j].a){
                if(f[i].b==f[j].b&&f[i].c!=f[j].c){
                    if(f[i].c>f[j].c){
                        eout[j].push_back(i),ein[i].push_back(j);
                        out[j]++,in[i]++;
                    }
                    else{
                        eout[i].push_back(j),ein[j].push_back(i);
                        out[i]++,in[j]++;
                    }
                }
            }else{
                if((f[i].b-f[j].b)*(f[i].b-f[j].b)<4*(f[i].a-f[j].a)*(f[i].c-f[j].c)){
                    if(f[i].a>f[j].a){
                        eout[j].push_back(i),ein[i].push_back(j);
                        out[j]++,in[i]++;
                    }else{
                        eout[i].push_back(j),ein[j].push_back(i);
                        out[i]++,in[j]++;
                    }
                }
            }
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!in[i]){
            q.push(i);
            dp1[i]=1;
        }
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:eout[u]){
            dp1[v]=max(dp1[v],dp1[u]+1);
            if(--in[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!out[i]){
            q.push(i);
            dp2[i]=1;
        }
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:ein[u]){
            dp2[v]=max(dp2[v],dp2[u]+1);
            if(--out[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp1[i]+dp2[i]-1<<" ";
    }
    cout<<'\n';
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