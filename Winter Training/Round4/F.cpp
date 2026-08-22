#include <bits/stdc++.h>
using namespace std;
/*

    首先，Alice肯定要把前面的B尽可能拿掉，如果前面有一个不拿，但是去拿后边的，那么就会导致这个可能会被计入答案
    Bob也是
    显然这个和Alice的操作次数以及B的数量有关系
    Alice操作(k+1)/2次，所以说要比较它和k-1位置前面b的数量的关系
    如果比b的数量多，那么说明b可以拿干净，并且a没有办法被Bob拿完
    如果一样多，就需要看k位置的字符是什么了
    如果比b的数量少，那么说明a会被拿干净，并且b没有办法被Alice拿完

*/
void sol() {
    int n;
    string  s;
    cin>>n>>s;
    vector<int> pa(n+1,0),pb(n+1,0);
    for(int i=0;i<=n;i++){
        if(i!=0){
            pa[i]=pa[i-1];
            pb[i]=pb[i-1];
        }
        if(s[i]=='A'){
            pa[i]++;
        }else{
            pb[i]++;
        }
    }
    for(int k=1;k<=n;k++){
        int numa=(k+1)/2,numb=k-numa;
        if(pb[k-1]<numa){
            cout<<"Alice\n";
        }else if(pb[k-1]>numa){
            cout<<"Bob\n";
        }else{
            cout<<((s[k]=='A')?"Alice":"Bob")<<'\n';
        }
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