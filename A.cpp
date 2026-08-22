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
    贡献根据h决定


    统计s前缀和
    cnt1->s cnt2->t



    这里遍历超时
*/


struct node{
	string s;
    int  cnt1=0,cnt2=0;

    int wgt=0;//初始贡献
};

bool cmp(const node&a,const node&b){


    // int la=a.s.size(),lb=b.s.size();
    // if(la<lb){
    //     return a.s>=b.s.substr(0,la);
    // }else if(la>lb){
    //     return a.s.substr(0,lb)>=b.s;
    // }else{
    //     return a.s>b.s;
    // }
    // if(a.cnt2==0){
    //     return true;
    // }//a没有t
    // else if(a.cnt1==0){
    //     return false; 
    // }//a没有s
    // else if(b.cnt2==0){
    //     return false;
    // }//b没有t
    // else if(b.cnt1==0){
    //     return true;
    // }//b没有s
    return a.cnt1*b.cnt2>b.cnt1*a.cnt2;
    
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n;
	cin>>n;
	vector<node> all(n);

	for(int i=0;i<n;i++){
		cin>>all[i].s;
        for(int j=0;j<all[i].s.size();j++){
            if(all[i].s[j]=='s'){
                all[i].cnt1++;
            }else{
                all[i].cnt2++;
                all[i].wgt+=all[i].cnt1;
            }
        }
	}

    // for(int i=0;i<n;i++){
    //     cout<<all[i].cnt1<<" "<<all[i].cnt2<<" "<<all[i].wgt<<"\n";
    // }

    sort(all.begin(),all.end(),cmp);
    // string t=all[0].s;
    // for(int i=1;i<n;i++){
    //     t+=all[i].s;
    // }

    // int sum=0,ans=0;
    // for(int i=0;i<t.size();i++){
    //     if(t[i]=='s'){
    //         sum++;
    //     }else{
    //         ans+=sum;
    //     }
    // }
    int ans=0,sum=0;
    for(int i=0;i<n;i++){
        ans+=(all[i].wgt+sum*all[i].cnt2);
        sum+=all[i].cnt1;
    }



    //  cout<<t<<"\n";
    cout<<ans;
    
	
	
	
}