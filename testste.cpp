#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include  <sstream>
#include <iomanip>
#include <string>
#include <map>

#define int long long 

using namespace std;



const int maxn=1e6+10;



void solve(){


    map<string,int> stu;

    int q;
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            string name;
            int score;
            cin>>name>>score;
            stu[name]=score;
            cout<<"OK\n";
        }else if(op==2){
            string name;
            cin>>name;
            if(stu.find(name)==stu.end()){
                cout<<"Not found\n";
            }else cout<<stu[name]<<"\n";
        }else if(op==3){
            string name;
            cin>>name;
            if(stu.find(name)==stu.end()){
                cout<<"Not found\n";
            }else{
                stu.erase(name);
                cout<<"Deleted successfully\n";
            }
        }else cout<<stu.size()<<"\n";
    }

}


signed main(){
    

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    solve();
    
    return 0;

}



