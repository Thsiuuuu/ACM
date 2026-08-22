#include <bits/stdc++.h>
using namespace std;
#define int long long 
void sol(){
	int n;
	cin>>n;
//	vector<int> a(n);
	map<int,int> mp;
	set<int,greater<int>> st;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		st.insert(x);
		mp[x]++;
	}
	int sum=0;
	int tot=0;
	for(int i:st){
		int num=mp[i];
        
        sum+=(i*((num/2)*2));
        tot+=(num/2);
	}
	if(!tot){
		cout<<"0\n";
		return ;
	}//不能构成一对 
	
	
    int la=0,nw=0;//
    int sig=0;//等腰三角形
    bool flag=false;

	for(int i:st){
		if(mp[i]%2==0) continue;//偶数条边不可以 

        int val=i;
        if(flag==false){
            la=nw;
            nw=val;
        }

        if((sig==0)&&sum>val) sig=val;//两边之和大于第三边
        if((flag==false)&&la&&nw&&(la-nw<sum)){

            flag=true;
        }


		if(flag&&sig>0) break;//如果等腰梯形和等腰三角形都凑齐了，那就退出，剪枝
	}
	if(tot==1&&(flag==false)&&(sig==0)){
		cout<<"0\n";
		return ;
	}//只有自己一对 
    // cout<<sig<<'\n'<<la<<' '<<nw<<'\n';
	cout<<sum+max(sig,(flag)?la+nw:(int)0)<<'\n';//判断的条件应该是符合条件即flag=true
} 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--) sol();
	return 0;
}