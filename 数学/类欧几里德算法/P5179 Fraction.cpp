#include <bits/stdc++.h>
using namespace std;
/*

    核心思想是把大范围问题转化到小范围上，再取倒数转化为相同结构的子问题

*/

void solve(int a,int b,int &p,int &q,int c,int d){
    if((a/b+1)*d<c){
        p=a/b+1;
        q=1;
    }else{
        solve(d,c-d*(a/b),q,p,b,a%b);
        p+=q*(a/b);
    }
}

void sol() {
    int a,b,c,d,p,q;
    while(cin>>a>>b>>c>>d){
        solve(a,b,p,q,c,d);
        cout<<p<<'/'<<q<<'\n';
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