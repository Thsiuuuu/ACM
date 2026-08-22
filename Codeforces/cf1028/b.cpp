#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mod=998244353;

int qmi(int a,int b)
{
    int res=1%mod;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

struct number{
    int add=0,dis=0,pta=0,ptb=0;
};


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector<int> p(n),q(n);
        for(int i=0;i<n;i++) cin>>p[i]>>q[i];

        for(int i=0;i<n;i++){
            int now1=0,now2=0;
            number trie;
            for(int a=0,b=i;b>=0;a++,b--){
                now1=p[a]+q[b];
                now2=abs(p[a]-q[b]);
                if(now1>trie.add||(now1==trie.add&&now2>trie.dis)){
                    trie.add=p[a]+q[b];
                    trie.dis=now2;
                    trie.pta=a;
                    trie.ptb=b;
                }
            }
            //cout<<trie.pta<<" "<<trie.ptb;
            cout<<(qmi(2,p[trie.pta])+qmi(2,q[trie.ptb]))%mod<<" ";
        }
        cout<<"\n";
        /* code */
    }
    
}