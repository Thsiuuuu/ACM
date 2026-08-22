#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

bool check(const vector<int>& nums,int k,int mid){
    int cnt=1;
    int sum=0;

    for(int num:nums){
        if(sum+num>mid){
            cnt++;
            sum=num;
        }else{
            sum+=num;
        }
    }

    return cnt<=k;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,k;
    cin>>n>>k;

    vector<int> nums(n);
    int left=0,right=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        left=max(left,nums[i]);
        right+=nums[i];
    }

    while(left<right){
        int mid=left+(right-left)/2;
        if(check(nums,k,mid)){
            right=mid;
        }else left=mid+1;
    }

    cout<<left;
    return 0;
}