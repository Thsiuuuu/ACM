#include <bits/stdc++.h>
using namespace std;
/*

    有点抽象的题目
    随机化

*/
mt19937 rd(time(nullptr));
void sol() {
    int n;
    cin>>n;
    int a=1,b=2,c=3;
    while(1){
        cout<<"? "<<a<<' '<<b<<' '<<c<<'\n';
        cout.flush();

        int p;
        cin>>p;
        if(!p){
            cout<<"! "<<a<<' '<<b<<' '<<c<<'\n';
            cout.flush();
            break;
        }
        int x=rd()%3;
        if(x==0) a=p;
        else if(x==1) b=p;
        else c=p;
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