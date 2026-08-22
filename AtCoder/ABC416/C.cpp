#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 


const int N=1e6+10;



void sol(){

    int n,m,x;
    cin>>n>>m>>x;
    
    vector<string> s(n),t;
    for(int i=0;i<n;i++) cin>>s[i];
    
    string temp;
    //sort(s.begin(),s.end());
    if(m==1){
        sort(s.begin(),s.end());
        cout<<s[x-1];
    }else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp=s[i]+s[j];
                t.push_back(temp);
            }
        }
        sort(t.begin(),t.end());
        //for(auto tri:t) cout<<tri<<"\n";
        cout<<t[x-1];
    }else if(m==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    temp=s[i]+s[j]+s[k];
                    t.push_back(temp);
                }
            }
        }
        sort(t.begin(),t.end());
        cout<<t[x-1];
    }else if(m==4){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        temp=s[i]+s[j]+s[k]+s[l];
                         t.push_back(temp);
                    }
                    
                }
            }
        }
        sort(t.begin(),t.end());
        cout<<t[x-1];
    }else if(m==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        for(int p=0;p<n;p++){
                        temp=s[i]+s[j]+s[k]+s[l]+s[p];
                         t.push_back(temp);
                        }
                    }
                    
                }
            }
        }
        sort(t.begin(),t.end());
        cout<<t[x-1];
    }


}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}