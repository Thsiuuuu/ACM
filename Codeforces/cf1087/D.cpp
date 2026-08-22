#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

struct node{
    char c;
    int num=0;
    bool operator<(const node&other)const{
        if(num==other.num) return c<other.c;
        return num>other.num;
    }
};

void sol() {
    vector<node> a(3);
    a[0].c='R',a[1].c='G',a[2].c='B';
    for(int i=0;i<=2;i++){
        cin>>a[i].num;
    }
    sort(a.begin(),a.end());
    string res;
    while(a[1].num&&a[2].num&&a[0].num<a[1].num+a[2].num){ 
        res.push_back(a[1].c),res.push_back(a[2].c);
        a[1].num--,a[2].num--;
    }
    while(a[1].num||a[2].num){
        res.push_back(a[0].c);a[0].num--;
        if(a[1].num&&(res[res.size()-1]!=a[1].c&&(res.size()<3||res[res.size()-3]!=a[1].c))){res.push_back(a[1].c);a[1].num--;}
        else if(a[2].num&&(res[res.size()-1]!=a[2].c&&(res.size()<3||res[res.size()-3]!=a[2].c))){res.push_back(a[2].c);a[2].num--;}
    }
    if(a[0].num){res.push_back(a[0].c);a[0].num--;}
    if(a[0].num){
        if((res.size()>=3&&res[2]==a[0].c)||(res.size()>=1&&res[0]==a[0].c)){}
        else {res.insert(0,1,a[0].c);a[0].num--;}
    }
    cout<<res<<'\n';
    // if(a[0].num==a[1].num==a[2].num){
    //     for(int i=1;i<=a[0].num;i++){
    //         if(i%3==1){
    //             cout<<"RGB";
    //         }else if(i%3==2){
    //             cout<<"GBR";
    //         }else{
    //             cout<<"BRG";
    //         }
    //     }
    //     cout<<'\n';
    // }else{
    //     if(a[0].num>=a[1].num+a[2].num){
    //         while(a[1].num||a[2].num){
    //             cout<<a[0].c;a[0].num--;
    //             if(a[1].num){cout<<a[1].c;a[1].num--;}
    //             else if(a[2].num){cout<<a[2].c;a[2].num--;}
    //         }
    //         if(a[0].num) cout<<a[0].c<<'\n';
    //     }else{
    //         string s;
    //         for(int i=1;i<=a[2].num;i++){
    //             if(i%1==1) s.append("RGB");
    //             else if(i%2==1) s.append("GBR");
    //             else s.append("BRG");
    //             a[0].num--,a[1].num--;
    //         }
    //         a[2].num=0;
            
    //         // while(a[0].num!=0){
    //         //     s.push_back(a[0].c);a[0].num--;
    //         //     if(a[1].num){s.push_back(a[1].c);a[1].num--;}
    //         //     else if(a[2].num){s.push_back(a[2].c);a[2].num--;}
    //         // }
    //         // if(a[1].num==0){
    //         //     while(a[2].num){
    //         //         if(s.size()>=1&&s[s.size()-1]==a[2].c) break;

    //         //     }
    //         // }else{
    //         //     while(a[1].num&&a[2].num){
    //         //         s.push_back(a[2].c);s.push_back(a[1].c);
    //         //         a[1].num--,a[2].num--;
    //         //     }
    //         //     if(a[1].num){
    //         //         if(((s.size()>=3&&s[s.size()-3])==a[1].c)||(s.size()>=1&&s[s.size()-1]==a[1].c)){

    //         //         }else{
    //         //             s.push_back(a[1].c);
    //         //             a[1].num--;
    //         //         }
    //         //         if(a[1].num) s=a[1].c+a[1].c;
    //         //     }else if(a[2].num){
    //         //         s.push_back(a[2].c);
    //         //         a[2].num--;
    //         //         if((s.size()>=1&&s[0]==a[2].c)||(s.size()==3&&s[2]==a[2].c)){

    //         //         }else{
    //         //             if(a[2].num)    s.push_back(a[2].c);
    //         //         }
    //         //     }
    //         // }
    //         // cout<<s<<'\n';
    //     }
    // }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}