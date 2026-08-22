#include <bits/stdc++.h>
using namespace std;
/*

    手玩样例发现从前往后扫不一定能得到正解，正难则反，考虑从后往前去解决。
    对于当前的每一个位置而言，一定是受到它之前的位置的支配
    并且对于i-1,i位置，支配它们的位置s_(i-1)<=s_i一定成立，否则一定会被覆盖过去
    那么如果说某一个位置找不到了，就不可以
    否则就是每一个覆盖值的最大值就是轮数
    下面考虑怎么构造：
    从前往后扫，如果当前的就是我要的，但是被后面的覆盖了，那么肯定不可以
    从后往前扫，我要的一定不会被覆盖，并且如果前面的需要覆盖我的也可以保证得到覆盖
    还是从后往前构造，每一轮在不超过支配它字符的范围的情况下一定扩张，就可以了

*/
void sol(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    vector<int> pos(n,-1);//记录与t串中每个字符匹配的s串的字符的右端点
    int nx=n-1;
    int mx=-1;
    for(int i=n-1;i>=0;i--){
        nx=min(nx,i);
        while(nx>=0&&s[nx]!=t[i]){
            nx--;
        }   
        if(nx<0){
            cout<<"-1\n";
            return ;
        }
        if(pos[nx]==-1) pos[nx]=i;
        mx=max(mx,i-nx);
    }
    if(mx>k) cout<<"-1\n";
    else{
        cout<<mx<<'\n';
        string cpy=s;
        for(int cnt=1;cnt<=mx;cnt++){
            for(int i=n-2;i>=0;i--){
                if(pos[i]!=-1&&(i+cnt<=pos[i])){
                    s[i+cnt]=cpy[i];
                }
            }
            cout<<s<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}