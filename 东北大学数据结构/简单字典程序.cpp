#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#define endl "\n"
using namespace std;

int main(){


    set<string> fas;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){

        string op,s;
        cin>>op>>s;
        if(op=="insert") fas.insert(s);
        else{
            if(fas.count(s)) cout<<"yes\n";
            else cout<<"no\n";
        }

    }
    return 0;
}