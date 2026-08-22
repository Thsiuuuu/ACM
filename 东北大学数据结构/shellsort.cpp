#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> knuth(int n) {
    vector<int> seq;
    int k = 1;
    while (k <= n){
        seq.push_back(k);
        k =3*k+1;
    }
    reverse(seq.begin(), seq.end());
    return seq;
}

void shell(vector<int>& a, const vector<int>& gaps, int& cnt) {
    cnt=0;
    int n =a.size();
    for (int g:gaps) {
        for (int i =g; i <n; ++i) {
            for (int j = i; j >= g && a[j - g]>a[j]; j -= g) {
                swap(a[j - g], a[j]);
                cnt++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i =0;i<n;++i) {
        cin>>a[i];
    }
    
    vector<int> gaps=knuth(n);
    int m =gaps.size();
    cout << m<<endl;
    for (int g : gaps) {
        cout <<g<< " ";
    }
    cout << endl;
    
    int cnt;
    shell(a, gaps, cnt);
   
    cout <<cnt<<endl;
    
    for (int num:a)    cout<<num<<endl;
    
    return 0;
}