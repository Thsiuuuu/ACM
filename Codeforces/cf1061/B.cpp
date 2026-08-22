    #include <bits/stdc++.h>
    using namespace std;
    #define int long long 

    void sol(){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        bool flag=true;
        for(int i=0;i<(int)s.size();i++){
            if(s[i]=='B'){
                flag=false;
                break;
            }
        }
        int siz=s.size();
        while(q--){
            int ans=0;
            int a;
            cin>>a;
            if(flag==true){
                cout<<a<<'\n';
            }else{
                for(int i=0;a;ans++,i=(i+1)%siz){
                    if(s[i]=='A'){
                        a--;
                    }else{
                        a/=2;
                    }
                }
                cout<<ans<<'\n';
            }
        }
    }
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);

        int t;
        cin>>t;
        while(t--){
            sol();
        }
    }