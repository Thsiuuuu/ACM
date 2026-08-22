#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const  int N=1e7+3;
int p[N],stk[N];
ll ls[N],rs[N];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=1,top=0;i<=n;i++){
        cin>>p[i];
        int pos=top;
        while(pos&&p[stk[pos]]>=p[i]) pos--;
        if(pos) rs[stk[pos]]=i;
        if(pos<top) ls[i]=stk[pos+1];
        top=pos,stk[++top]=i;
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        res=res^(i*(ls[i]+1));
    }
    cout<<res<<" ";
    res=0;
    for(int i=1;i<=n;i++){
        res=res^(i*(rs[i]+1));
    }
    cout<<res;
    return 0;
}