#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// int a[7][7];

void sol(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    queue<int> res;
    int tail=INT32_MAX;
    stack<int> stk;
    int i=1;
    while(stk.size()&&i<=n){
        if(stk.size()){
            if(stk.top()<=tail){
                res.push(stk.top());
                tail=stk.top();
                stk.pop();
            }else{
                if(i>n){
                    int l=0;
                    tail=1e18;
                    while(res.size()){
                        if(l) cout<<" ";
                        cout<<res.front();res.pop();
                        l++;
                    }
                    cout<<'\n';
                }else{
                    bool f=false;
                    while(i<=n&&stk.size()<m){
                        
                        if(a[i]<=tail){
                            res.push(a[i]);tail=a[i];
                            i++;
                            f=true;
                            break;
                        }else{
                            i++;
                            stk.push(a[i]);
                        }
                    }
                    if(!f){
                        int l=0;
                        tail=1e18;
                        while(res.size()){
                            if(l) cout<<" ";
                            cout<<res.front();res.pop();
                            l++;
                        }
                        cout<<'\n';
                    }else{
                        if(res.size()==k){
                            int l=0;
                            tail=1e18;
                            while(res.size()){
                                if(l) cout<<" ";
                                cout<<res.front();res.pop();
                                l++;
                            }
                            cout<<'\n';
                        }
                    }
                }
                
            }
        }else{
                if(i>n){
                    int l=0;
                    tail=1e18;
                    while(res.size()){
                        if(l) cout<<" ";
                        cout<<res.front();res.pop();
                        l++;
                    }
                    cout<<'\n';
                }else{
                    bool f=false;
                    while(i<=n&&stk.size()<m){
                        
                        if(a[i]<=tail){
                            res.push(a[i]);tail=a[i];
                            i++;
                            f=true;
                            break;
                        }else{
                            i++;
                            stk.push(a[i]);
                        }
                    }
                    if(!f){
                        int l=0;
                        tail=1e18;
                        while(res.size()){
                            if(l) cout<<" ";
                            cout<<res.front();res.pop();
                            l++;
                        }
                        cout<<'\n';
                    }else{
                        if(res.size()==k){
                            int l=0;
                            tail=1e18;
                            while(res.size()){
                                if(l) cout<<" ";
                                cout<<res.front();res.pop();
                                l++;
                            }
                            cout<<'\n';
                        }
                    }
                }
        }
        if(res.size()==k){
            int l=0;
            tail=1e18;
            while(res.size()){
                if(l) cout<<" ";
                cout<<res.front();res.pop();
                l++;
            }
            cout<<'\n';
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