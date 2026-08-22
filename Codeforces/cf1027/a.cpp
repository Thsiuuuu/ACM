#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> PLL;



void sol(){

    string s;
    cin>>s;
    int number=stoi(s);
    int srt=sqrt(number);
    if(srt*srt!=number){
        cout<<-1<<"\n";
        return ;
    }else{
        cout<<0<<" "<<srt<<"\n";
    }
}

int main(){

    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }

}