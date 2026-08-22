#include <bits/stdc++.h>
using namespace std;
/*

    首先有一个暴力做法，时间复杂度O(n*2*logn)
    然后考虑怎么优化，尝试几组数据发现路径很多是重复的
    如果当前命令是A,那么直接跳到下一位就好
    如果是B，那么下一次执行这个命令是跳到下一个白的的最近白的
    也就是说可以把多次模拟化简成一轮完成

    总的时间复杂度O(n*logn)

*/
#define int long long
void sol(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    set<int> st;
    for(int i=0,x;i<m;i++){
        cin>>x;
        st.insert(x);
    }
    for(int nw=1,i=0;i<s.size();i++){
        if(s[i]=='A'){
            st.insert(++nw);
        }else{
            while(st.find(nw+1)!=st.end()){
                nw++;
            }
            st.insert(++nw);
            while(st.find(nw+1)!=st.end()){
                nw++;
            }
            nw++;
        }
    }
    
    cout<<st.size()<<"\n";
    for(int x:st) cout<<x<<" ";
    cout<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}