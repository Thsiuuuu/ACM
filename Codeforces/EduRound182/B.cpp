#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int len=0;
    int num=0,st=0;
    int tot=n*(n+1)/2;
    int l,r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tot-=a[i];
        if(!a[i]){
            num++;
            st=i;
        }
    } 
    if(num==1){
        a[st]=tot;
    }
    for(l=1;l<=n;l++){
        if(a[l]^l){
            break;
        }
    }
    if(l==n+1){
        cout<<"0\n";
        return;
    }else{
        for(r=n;r>l;r--){
            if(a[r]^r){
                break;
            }
        }
        cout<<r-l+1<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}