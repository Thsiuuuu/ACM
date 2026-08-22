#include <iostream>
#include <algorithm>

using namespace std;


void sol(){

    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>=b){
        if(c>=d) cout<<"Gellyfish\n";
        else{
            if(b<=c) cout<<"Gellyfish\n";
            else cout<<"Flower\n";
        }
    }else{
        if(c<d) cout<<"Flower\n";
        else{
            if(a>=d) cout<<"Gellyfish\n";
            else cout<<"Flower\n";
        }
    }

}



int main(){
    ios::sync_with_stdio(0),cin.tie(0);


    int t;
    cin>>t;
    while(t--)
    sol();
}