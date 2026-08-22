#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#include <string>


using namespace std;

int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    set<string> sset;
    do{
        sset.insert(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<sset.size()<<"\n";
    for(auto s:sset) cout<<s<<"\n";
    return 0;
}