#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n;
    cin>>n;
    if(n>=3){
        cout<<"! 1\n";
        cout.flush();
    }else{
        int  cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            cout<<"? "<<i<<'\n';
            cout.flush();
            int x;
            cin>>x;
            if(x%3==0){
                cout<<"! 1\n";
                cout.flush();
                return;
            }else{
                if(x%3==1){

                    cnt1++;
                }else{
                    cnt2++;
                }
            }
        }
        if(cnt1&&cnt2){
            cout<<"! 1\n";
        }else{
            cout<<"! 0\n";
        }
        cout.flush();
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