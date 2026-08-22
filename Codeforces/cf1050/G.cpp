#include <bits/stdc++.h>
using namespace std;
/*

    题目可以转化为找到一个数，使得这个数的出现次数尽可能多
    但是需要保证出现次数不能等于当前序列长度
    这个数并不一定是质数，最开始想成用质数个数去判断，一个n^2的算法就超时了
    实际上一个合数也有可能
    也就是说，每次的答案总是之前的答案和这一轮更新的合数的次数取最大值
    然后需要注意处理出现个数等于轮数的数，它在下一轮有可能成为答案，所以需要开一个数组记录一下

*/
const int N=2e5+10;
vector<int> divs[N];
int ans[N];
void init(){
    for(int i=2;i<=2e5+3;i++){
        for(int j=i;j<=2e5+3;j+=i){
            divs[j].push_back(i);
        }
    }
}


void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=0;
    }
    int p=0;
    vector<int> last,cnt(n+1,0);
    vector<bool> st(n+1,false);
    for(int i=1;i<=n;i++){
        int x=a[i];
        vector<int> cur;
        for(int number:divs[x]){
            cnt[number]++;
            if(cnt[number]<i){
                p=max(p,cnt[number]);
            }else if(!st[number]){
                st[number]=true;
                cur.push_back(number);
            }
        }
        for(int number:cur){
            st[number]=false;
        }
        for(int number:last){
            if(cnt[number]<i){
                p=max(cnt[number],p);
            }
        }
        last=cur;
        ans[i]=p;
    }

    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}