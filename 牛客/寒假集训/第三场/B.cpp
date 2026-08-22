#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    map<int,int> mp;
    bool flag=false;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(flag){
            continue;
        }
        int y=x;
        for(int number=2;number*number<=x;number++){
           if(y%number==0){
                if(mp.find(number)==mp.end()){
                    mp[number]=x;
                }else{
                    cout<<mp[number]<<" "<<x<<'\n';
                    flag=true;
                }
                while(y%number==0){
                    y/=number;
                }
           }
        }
        if(y>1&&flag==false){
            if(mp.find(y)==mp.end()){
                mp[y]=x;
            }else{
                cout<<mp[y]<<" "<<x<<'\n';
                flag=true;
            }
        }
    }
    if(!flag){
        cout<<"-1\n";
    }
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