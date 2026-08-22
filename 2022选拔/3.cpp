#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef long long ll;

struct node{
    int x,y;
};

bool cmp(node a,node b)
{
    return a.x<b.x;
}

bool check1(vector<node>&number,int s)
{
    for(int i=0;i<number.size();i++){
        if(s>number[i].x) s+=number[i].y;
        else return false;
    }
    return true;
}

bool check2(ll x)
{
    for(ll i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }return true;
}

void sol()
{
    ll n;
    cin>>n;
    vector<ll> number(n);
    ll cnt1=0,cnt3=0;
    for(ll i=0;i<n;i++){
        cin>>number[i];
        if(!number[i]) cnt3++;
        else if(number[i]<0) cnt1++;
    }
    ll sum=0;
    for(ll i=0;i<n;i++){
        if(number[i]<0) sum+=abs(number[i]+1);
        else if(number[i]>0) sum+=(number[i]-1);
        else sum+=1;
    }
    if((!cnt3)&&((cnt1%2)!=0))
        sum+=2;
    cout<<sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    //int t;
    //cin>>t;
    //while(t--)
    sol();
    return 0;
}