#include <bits/stdc++.h>
using namespace std;
#define int long  long 
/*



*/
//保证x是少的，y是多的

string check(int can1,int add1,int can2,int add2){
    int num=can2-add2;
    if(num+can1>=add1){
        return "YES\n";
    }
    return "NO\n";
}

string sol() {
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    int rem1=0,rem2=0,add1=0,add2=0;//rem必须的，add对应的
    int sum1=0,sum2=0;
    int sum=0;
    for(int i=0;i<s.size();i++){
        
        sum+=p[i];
        int cur=p[i]/2+1ll;
        if(s[i]=='0'){                  
            rem1+=cur;
            add2+=(p[i]-cur);
        }else{
            rem2+=cur;
            add1+=(p[i]-cur);
        }
    }
    if(count(s.begin(),s.end(),'0')==n){
        if((x-y<n)||(y+x<sum)){
            return "NO\n";
        }
        return "YES\n";
    }
    if(count(s.begin(),s.end(),'0')==0){
        if(((y-x)<n)||(y+x<sum)){
            return "NO\n";
        }
        return "YES\n";
    }

    if(x<rem1||y<rem2){
        return "NO\n";
    }
    sum1=rem1+add1;
    sum2=rem2+add2;
    if(((sum1+sum2)>(x+y))||(x+y<sum)){
        return "NO\n";
    }

    if((sum1<=x)&&(sum2<=y)){
        return "YES\n";
    }else{
        if(x>=sum1){
            return check(y-rem2,add2,x-rem1,add1);
        }
        return check(x-rem1,add1,y-rem2,add2);
    }

}

signed  main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        cout<<sol();
    }
    return 0;
}