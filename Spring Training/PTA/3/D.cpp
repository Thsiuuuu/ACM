#include <bits/stdc++.h>
using namespace std;
#define ll long long 


const int N=502;
int a[N][N];
int sex[N];

struct node{
    int idx;
    int score;
    bool operator<(const node&other)const{
        if(score==other.score) return idx<other.idx;
        return score<other.score;
    }
};

void sol(){ 
    int n;
    // scanf("%d",&n);
    cin>>n;
    vector<node> fm,m;  
    for(int i=1;i<=n;i++){
        char op;cin>>op;
        sex[i]=((op=='M')?1:0);
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int other,dis;
            string s;cin>>s;
            // scanf("%d:%d",&other,&dis);
            for(int i=0;i<s.size();i++){
                if(s[i]==':'){
                    other=stoi(s.substr(0,i));
                    dis=stoi(s.substr(i+1,s.size()-i-1));
                    break;
                }
            }
            a[i][other]=dis;
        }
    }
    for(int i=1;i<=n;i++){
        
        int ans=INT32_MIN;
        for(int j=1;j<=n;j++){
            if(i==j||sex[i]==sex[j]||a[j][i]) continue;
            cout<<a[i][j]<<" ";
            ans=max(ans,a[j][i]);
        }
        cout<<'\n';
        if(sex[i]) m.push_back({i,ans});
        else fm.push_back({i,ans});
    }
    sort(fm.begin(),fm.end());
    sort(m.begin(),m.end());
    int l=0;
    for(int i=0;i<fm.size();i++){
        if(l) cout<<" ";
        if(fm[i].score==fm[0].score){
            l++;
            cout<<fm[i].idx;
        }
    }
    cout<<'\n';
    l=0;
    for(int i=0;i<m.size();i++){
        if(l) cout<<" ";
        if(m[i].score==m[0].score){
            l++;
            cout<<m[i].idx;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}