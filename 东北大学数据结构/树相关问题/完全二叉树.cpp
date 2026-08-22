#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define int long long 



signed main(){
    int h;
    cin>>h;
    vector<int> keys(h+1);

    for(int i=1;i<=h;i++) cin>>keys[i];
    for(int i=1;i<=h;i++){
        int k=keys[i];
        int parent=i/2;
        int left=2*i;
        int right=2*i+1;
        

        vector<string> parts;
        parts.push_back("key = " + to_string(k));

        if (parent >= 1) {
            parts.push_back("parent key = " + to_string(keys[parent]));
        }

        if (left<= h) {
            parts.push_back("left key = " + to_string(keys[left]));
        }

        if (right <= h) {
            parts.push_back("right key = " + to_string(keys[right]));
        }

        string mid;
        for(int j=0;j<parts.size();j++){
            if(j) mid+=", ";
            mid+=parts[j];
        }

        cout << "node " << i << ": " << mid << ", " << endl;

    }

    return 0;
}