#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    由每一列相等，可得需要(n+1)k/2存在，所以n偶k奇不可以
    如果k是偶数，以k=2为例，可以通过首尾相接的方式构造
    所以直接构造即可，但是需要注意n!>=k
    如果k是奇数
    那么可以通过转化为若干偶数行加上一个3行进行构造
    这个非常重要，是利用已知去尝试未知
    这个构造方法是
    1    2   3   4 ...   2x   2x+1
    2x+1 x+1 2x  x       x+2   1
    x    2x  x  2x-1     1    x+1

    采用循环首尾相接的构造方法，进行构造


*/



void sol() {
    int n,k;
    cin>>n>>k;

    if(n==1&&k==1){
        cout<<"YES\n1\n";
    }
    else if(k==1){
        cout<<"NO\n";
    }
    else if(n%2==0&&k%2==1){
        cout<<"NO\n";
    }else{

        int mul=1;
        for(int x=n;x>=1;x--){
            if(mul>=5e6){
                mul=INT64_MAX;
                break;
            }
            mul*=x;
        }
        if(mul<k){
            cout<<"NO\n";
            return ;
        }
        if(k%2==0){
            vector<int> num(n);
            iota(num.begin(),num.end(),1);
            int cnt=0;
            // int tot=(n+1)*k/2;
            cout<<"YES\n";
            do{
                for(int i=0;i<n;i++){
                    cout<<num[i]<<" ";
                }
                cout<<'\n';
                for(int i=0;i<n;i++){
                    cout<<n+1-num[i]<<" ";
                }
                cout<<'\n';
                cnt+=2;
                if(cnt>=k) return ;
            }while(next_permutation(num.begin(),num.end()));
        }else if(k%2==1){
            if(k+3>mul){
                cout<<"NO\n";
                return ;
            }
            int cnt=0;
            vector<int> num(n),res1,res2;
            res1=res2=num;
            iota(num.begin(),num.end(),1);
            int x=(n-1)/2;
            int tot=3*(x+1);
            // cout<<"x "<<x<<'\n';
            // cout<<"tot "<<tot<<'\n';
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<num[i]<<" ";
                if(i==0){
                    res1[0]=x+1;
                    res2[0]=2*x+1;
                }else{
                    res1[i]=res2[i-1];
                    res2[i]=tot-(i+1)-res1[i];
                }
            }
            cout<<'\n';
            for(int i=0;i<n;i++){
                cout<<res1[i]<<" ";
            }
            cout<<'\n';
            for(int i=0;i<n;i++){
                cout<<res2[i]<<" ";
            }
            cout<<'\n';
            cnt+=3;
            set<vector<int>> st;
            st.insert(num);
            st.insert(res1);
            st.insert(res2);
            vector<int> cmp(n);

            do{
                if(cnt>=k) return ;
                for(int i=0;i<n;i++){
                    cmp[i]=n+1-num[i];
                }
                if(st.find(num)!=st.end()||st.find(cmp)!=st.end()){
                    continue;
                }else{
                    for(int number:num){
                        cout<<number<<" ";
                    }
                    cout<<'\n';
                    for(int number:cmp){
                        cout<<number<<" ";
                    }
                    cout<<'\n';
                }
                cnt+=2;
            }while(next_permutation(num.begin(),num.end())&&cnt<=k);
    
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