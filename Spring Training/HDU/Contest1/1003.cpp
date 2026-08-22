#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int N=2010;
int rs[N<<1],rt[N<<1],ds[N<<1],dt[N<<1];
ll f[N][N];


void manacher(const string&t,int *R,int *diff){
    string s="#";
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
        R[i]=len-1;
        if(i+len>r){r=i+len;c=i;}
        if(R[i]){
            int lmin=(i-R[i]+1)/2,lmax=(i-1)/2;
            if(lmin<=lmax){
                diff[lmin]++;
                if(lmax+1<t.size()) diff[lmax+1]--;
            }
        }
    }
}

void sol(){
    string s,t;cin>>s>>t;
    for(int i=0;i<=4000;i++){
        rs[i]=rt[i]=ds[i]=dt[i]=0;
    }
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=2000;j++){
            f[i][j]=0;
        }
    }
    reverse(t.begin(),t.end());
    manacher(s,rs,ds);
    manacher(t,rt,dt);
    for(int i=1;i<s.size();i++){
        ds[i]+=ds[i-1],dt[i]+=dt[i-1];
    }
    ll ans=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(s[i]!=t[j]) f[i][j]=0;
            else{
                if(i==0||j==0) f[i][j]=1;
                else f[i][j]=f[i-1][j-1]+1;
            }
            ans+=f[i][j]*(1+ds[i+1]+dt[j+1]);
        }
    }
    cout<<ans<<'\n';
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