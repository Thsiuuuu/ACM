#include <bits/stdc++.h>
using namespace std;
/*

    这个可以从最后考虑，开头大就大
    如果不大，就是一直取相等直到取到不一样的位置
    总之，Alice不会输
    可以从什么时候平局考虑，一直取相等之前有一处不等的之后就能决定了
    如果是回文，相邻两项重复，或者回文套着相邻两项重复就不可以

*/
void sol() {
    string s;
    cin>>s;
    int n=s.size();
    deque<char> que;
    for(int i=0;i<s.size();i++){
        que.push_back(s[i]);
    }
    while(que.size()&&que.back()==que.front()){
        que.pop_back();
        que.pop_front();
    }
    while(que.size()&&que[0]==que[1]){
        que.pop_front();
        que.pop_front();
    }
    if(que.size()){
        cout<<"Alice\n";
    }else{
        cout<<"Draw\n";
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