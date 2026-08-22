#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#define endl "\n"
using namespace std;


typedef pair<char,int>PCI;

const int N=200006;
int /*a[N],*/ans=0,n,mn;

vector<PCI> card(N),cardcpy(N);

bool check()
{
    for(int i=0;i<n;i++){
        if(cardcpy[i].first!=card[i].first||cardcpy[i].second!=card[i].second){
            return false;
        }
    }
    return true;
}

bool cmp(const PCI& a,const PCI& b){
    return a.second<b.second;
}



int  partition(vector<PCI>& A,int p,int r){

    PCI obj=A[r];
    int i=p-1;
    for(int j=p;j<=r-1;j++){
        if(A[j].second<=obj.second){
            i++;
            swap(A[i],A[j]);
        }
    }

    swap(A[i+1],A[r]);
    
    return i+1;
}


void Quicksort(vector<PCI>& A,int p,int r){

    if(p<r){
        int q=partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }

}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>card[i].first>>card[i].second;
    
    for(int i=0;i<n;i++){
        cardcpy[i].first=card[i].first;
        cardcpy[i].second=card[i].second;
    }

    stable_sort(card.begin(),card.end(),cmp);

    Quicksort(cardcpy,0,n-1);



    if(check()) cout<<"Stable\n";
    else cout<<"Not stable\n";
    for(int i=0;i<n;i++) cout<<cardcpy[i].first<<" "<<cardcpy[i].second<<"\n";

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}