#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<int,vector<int>,less<int>> pq1,pq2;
    priority_queue<int,vector<int>,greater<int>>pq3;
    for(int i=0;i<n;i++){
        if(a[i]&1){
            pq1.push(a[i]);
        }else{
            pq2.push(a[i]);
            pq3.push(a[i]);
        }
    }
    if(pq1.size()==0){
        for(int i=1;i<=n;i++){
            cout<<"0 ";
        }
    }else if(pq2.size()==0){
        for(int i=1;i<=n;i++){
            if(i&1){
                cout<<pq1.top()<<" ";
            }else{
                cout<<"0 ";
            }
        }
    }else{
        int sum=0,sum1=0;
        int siz=pq2.size(),siz1=siz;
        for(int i=1;i<=n;i++){
            if(i==1){
                cout<<pq1.top()<<" ";
            }else{
                if(pq2.size()){
                    int val=pq2.top();
                    pq2.pop();
                    pq3.push(val);
                    sum+=val;
                    sum1=sum;
                    cout<<sum+pq1.top()<<" ";
                }else{
                    int del=i-(siz+1);
                    if(del&1){
                        if(i==n){
                            cout<<"0 ";//是通过偶数丢1个，然后奇数加1个得到的，但是如果所有的数都要选就只能是0了
                        }else if(i&1){
                            while(1){
                                if(siz1%2==0){
                                    cout<<pq1.top()+sum1<<" ";
                                    break;
                                }else{
                                    siz1--;
                                    sum1-=pq3.top();
                                    pq3.pop();
                                }
                            }
                        }else{
                            while(1){
                                if(siz1&1){
                                    cout<<pq1.top()+sum1<<" ";
                                    break;
                                }else{
                                    siz1--;
                                    sum1-=pq3.top();
                                    pq3.pop();
                                }
                            }
                        }
                    }else cout<<sum+pq1.top()<<" ";
                }
            }
        }
    }
    cout<<'\n';
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