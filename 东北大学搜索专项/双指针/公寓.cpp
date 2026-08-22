#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl "\n"

/*
    先进行排序，然后再利用双指针算法替代线性查找，降低时间复杂度
*/


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    vector<int> person(n),house(m);

    for(int i=0;i<n;i++) cin>>person[i];
    for(int i=0;i<m;i++) cin>>house[i];

    sort(person.begin(),person.end());
    sort(house.begin(),house.end());


    int cnt=0;
    int i=0,j=0;
    while(i<n&&j<m){
        if(abs(person[i]-house[j])<=k){
            cnt++;
            i++;
            j++;
        }else if(house[j]<person[i])
            j++;
        else i++;
    }

    cout<<cnt;
    return 0;

}