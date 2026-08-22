#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long 
typedef pair<int,int> pii;

/*
 	按照s,h数量排列
	 s多的在左边，h多的在右边 

     按贡献排序
    统计s前缀和
    cnt1->s cnt2->t
*/




signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n;
    cin>>n;
    vector<int> num(n);
    for(int i=0;i<n;i++) cin>>num[i];
    sort(num.begin(),num.end());
    int sum=0;
    auto it=lower_bound(num.begin(),num.end(),0);
    for(auto i=it;i<num.end();i++){
        sum+=(*i);
    }
    if(sum%2!=0) cout<<sum;
    else{
        //两种情况，删左边和删右边，取最大值
        bool a=false,b=false;
        int sum1=sum,sum2=sum;
        for(auto i=it;i<num.end();i++){
            if((sum-*i)%2==1){
                sum1-=*i;
                a=true;
                break;
            }
        }

        for(auto i=it-1;i>=num.begin();i--){
            if(abs((sum2-*i))%2==1){
                sum2+=(*i);
                b=true;
                break;
            }
        }
        if(a&&b){
            sum=max(sum1,sum2);
        }else if(!a&&b){
            sum=sum2;
        }else{
            sum=sum1;
        }
        // cout<<sum1<<" "<<sum2<<"\n";
        cout<<sum;
    }
	
	
	
}