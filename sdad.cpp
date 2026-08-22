#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.size()==5){
            cout<<"3\n";
        }else{
            if(s[0]=='o'&&s[1]=='n'){
                cout<<"1\n";
            }else if(s[0]=='o'&&s[2]=='e'){
                cout<<"1\n";
            }else if(s[1]=='n'&&s[2]=='e'){
                cout<<"1\n";
            }else if(s[0]=='t'&&s[1]=='w'){
                cout<<"2\n";
            }else if(s[1]=='w'&&s[2]=='o'){
                cout<<"2\n";
            }else if(s[0]=='t'&&s[2]=='o'){
                cout<<"2\n";
            }
        }
    }
	return 0;
}