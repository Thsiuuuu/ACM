#include <bits/stdc++.h>
using namespace std;
/*

    两种做法：
    1.模拟链表，每次记录自己当前的失配位置，进行快速的跳转
    2.单调栈，因为类似于逆序对，如果栈中字符大于当前字符，就弹栈

*/
#define int long long
void sol() {
    int pos,n;
    string s;
    cin>>s>>pos;
    n=s.size();
    // vector<int> fail(n,0),order;
    // fail[0]=-1;
    // for(int i=1;i<n;i++){
    //     if(s[i]<s[i-1]){
    //         int cur=i-1;
    //         while(cur!=-1&&s[i]<s[cur]){
    //             order.push_back(cur);
    //             cur=fail[cur];
    //         }
    //         fail[i]=cur;
    //     }else{
    //         fail[i]=i-1;
    //     }
    // }
    // if(order.size()==0){
    //     for(int i=n-1;i>=0;i--){
    //         order.push_back(i);
    //     }
    // }

    // int cur=n-1;
    // while(cur!=-1){
    //     order.push_back(cur);
    //     cur=fail[cur];
    // }

    vector<int> order;
    stack<int> stk;
    stk.push(0);
    for(int i=1;i<n;i++){
        while(stk.size()&&s[stk.top()]>s[i]){
            order.push_back(stk.top());
            stk.pop();
        }
        stk.push(i);
    }
    while(stk.size()){
        order.push_back(stk.top());
        stk.pop();
    }

    int cnt=0,l=1,r=n;
    while(1){
        if(l<=pos&&pos<=r){
            break;
        }else{
            cnt++;
            l=r+1;
            r=r+n-cnt;
        }
    }
    // cout<<order.size()<<'\n';
    
    // cout<<l<<" "<<r<<'\n';
    // cout<<cnt<<'\n';
    if(cnt==0){
        cout<<s[pos-1];
    }else{
        vector<int> visited(n,1);
        for(int i=0;i<cnt;i++){
            visited[order[i]]=0;
        }
        // sort(order.begin(),order.begin()+cnt);
        // for(int i:order){
        //     cout<<i<<" ";
        // }
        for(int i=0,num=0;i<n;i++){
            if(visited[i]){
                if(num==pos-l){
                    cout<<s[i];
                    return;
                }else num++;
            }else{

            }
        }
    }
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