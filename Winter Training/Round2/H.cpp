#include <bits/stdc++.h>
using namespace std;
/*

    非常离谱的题，大胆猜想，仔细验证，多手玩样例，可从特殊情况想

    计x为1的次数
    全相同：
        每个不是1的位置会被更新x次
    全不同：
        每个是1的位置会被更新x次

    根据奇偶性最终会演化成
    000000
    111111

    000000
    000000
    第一种情况分别额外对[1,1],[2,n],[1,n]进行更新即可

    

*/
void sol() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]^b[i]){
            cnt++;
        }
    }
    // int num=0;
    if(cnt>0&&cnt<n){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            if(a[i]=='1'){
                ans.push_back({i+1,i+1});
            }
        }
        bool f1=false;
        if(cnt!=0){
            if(ans.size()%2==0){
                f1=true;
            }
        }else{
            if(ans.size()&1){
                f1=true;
            }
        }
        if(f1){
            cout<<ans.size()+3<<'\n';
        }else cout<<ans.size()<<'\n';

        for(auto [l,r]:ans){
            cout<<l<<" "<<r<<'\n';
        }
        if(f1){
            cout<<"1 1\n";
            cout<<"2 "<<n<<'\n';
            cout<<"1 "<<n<<'\n';
        }
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