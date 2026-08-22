#include <bits/stdc++.h>
using namespace std;
/*

    直接遍历会超的
    可以用分治思想，类似于败者树的方式，两个一组，筛选出相邻元素的最大值和最小值，然后逐层递归
    时间复杂度n/2+n/4+...+1=n

*/
void sol() {
    int n;
    cin>>n;
    queue<int> que;
    vector<int> mx,mn;
    if(n==1){
        cout<<"! 1 1"<<endl;
        // cout.flush();
        return ;
    }
    for(int i=1;i<=n-1;i+=2){
        cout<<"? "<<i<<" "<<(i+1)<<endl;
        // cout.flush();
        char c;
        cin>>c;
        if(c=='='||c=='>'){
            mx.push_back(i);
            mn.push_back(i+1);
        }else{
            mn.push_back(i);
            mx.push_back(i+1);
        }
    }
    if(n&1){
        cout<<"? "<<(n-1)<<" "<<n<<endl;
        // cout.flush();
        char c;
        cin>>c;
        if(c=='='||c=='>'){
            mn.push_back(n);
        }else{
            mx.push_back(n);
        }
    }
    while(mx.size()>1){
        for(int i=0;i<mx.size();i++){
            que.push(mx[i]);
        }
        mx.clear();
        while(que.size()>1){
            int i=que.front();
            que.pop();
            int j=que.front();
            que.pop();
            cout<<"? "<<i<<" "<<j<<endl;
            // cout.flush();
            char c;
            cin>>c;
            if(c=='='||c=='>'){
                mx.push_back(i);
            }else{
                mx.push_back(j);
            }
        }
        if(que.size()==1){
            mx.push_back(que.front());
            que.pop();
        }
    }
    while(mn.size()>1){
        for(int i=0;i<mn.size();i++){
            que.push(mn[i]);
        }
        mn.clear();
        while(que.size()>1){
            int i=que.front();
            que.pop();
            int j=que.front();
            que.pop();
            cout<<"? "<<i<<" "<<j<<endl;
            // cout.flush();
            char c;
            cin>>c;
            if(c=='='||c=='<'){
                mn.push_back(i);
            }else{
                mn.push_back(j);
            }
        }
        if(que.size()==1){
            mn.push_back(que.front());
            que.pop();
        }
    }
    cout<<"! "<<mn[0]<<" "<<mx[0]<<endl;
    // cout.flush();
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