#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    vector<int> a(5,0);
    int number=0,sum=0,even=0,odd=0;
    for(int i=1;i<=4;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]){
            number++;
            if(a[i]&1){
                even++;
            }else{
                odd++;
            }
        }
    }
    if(sum%2==0){
        if(number==4){
            if(even==number||even==0){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }else{
            if(odd==number){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }else{
        if(number==4){
            if(odd==3||odd==1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }else{
            if(a[4]==0&&even==3){
                cout<<"Yes\n";
            }else if(even==1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
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