#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> number(19,0);
    for(int i=0;i<=(1<<n)-1;i++){
        for(int j=18;j>=0;j--){
            if(i>>j&1){
                number[j]++;
            }
        }
    }

    vector<int> ans;
    int cur=0,cnt=(1<<n)-1;
    ans.push_back(cur);
    while(cnt>0){
        cout<<cur<<'\n';
        for(int j=18;j>=0;j--){
            if(((cur>>j&1)==0&&(number[j]==cnt))||((cur>>j&1)==1&&(number[j]==0))){
                cout<<"hel\n";
                if((cur>>j&1)==0){
                    number[j]--;
                }
                cur^=(1<<j);
            }else{
                if(cur>>j&1){
                    number[j]--;
                }
            }
        }
        ans.push_back(cur);
        cnt--;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}