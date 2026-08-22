#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int n,query,l,r,q,point;


void sol(){

    cin>>n>>q;
    vector<set<int>> number(n+1);
    for(int i=1;i<=n;i++) number[i].insert(0);

    while(q--){
        cin>>query;
        switch (query)
        {
            case 1:
                cin>>l>>r;
                for(int i=l;i<=r;i++){
                    number[i].insert(i-l+1);
                }
                break;
            
            case 2:
                cin>>point;
                int left=0,right=1145149,mid;
                while(left<right){
                    mid=(left+right)/2;
                    if(number[point].find(mid)==number[point].end()){
                        right=mid;
                    }else{
                        left=mid+1;
                    }
                }
                cout<<left<<"\n";
                break;
        }   
    }

}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    sol();
    return 0;
}