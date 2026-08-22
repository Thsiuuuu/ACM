#include <bits/stdc++.h>
using  namespace std;
#define ll long long 

bool is1(char x){
    return (x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0'&&x<='9');
}

bool is2(char x){
    return (x>='A'&&x<='Z');
}
bool is3(char x){
    return (x>='a'&&x<='z')||(x>='A'&&x<='Z');
}

void tran(char& x){
    x+=32;
}

void sol(){
    string s;
    getline(cin,s);
    cout<<s<<'\n';
    stringstream l1(s); 
    vector<string> v1,v2;
    string token,tmp;
    int k=0;
    while(l1>>token){
        if(!is1(token[0])){
            tmp+=token;
        }else if(k) tmp+=(" "+token);
        else tmp+=token;
        k++;
    }
    stringstream l3(tmp);
    while(l3>>token){
        v1.push_back(token);
    }
    for(int i=0;i<tmp.size();i++){
        if(is2(tmp[i])&&tmp[i]!='I') tran(tmp[i]);
    }
    while(tmp.find("can you")!=string::npos){
        auto it=tmp.find("can you");
        tmp.replace(it,7,"I can");
    }
    while(tmp.find("could you")!=string::npos){
        auto it=tmp.find("could you");
        tmp.replace(it,9,"I could");
    }
    // while(tmp.find("I")!=string::npos){
    //     auto it=tmp.find("I");
    //     tmp.replace(it,1,"you");
    // }
    // while(tmp.find("me")!=string::npos){
    //     auto it=tmp.find("me");
    //     tmp.replace(it,2,"you");
    // }
    while(tmp.find("?")!=string::npos){
        auto it=tmp.find("?");
        tmp.replace(it,1,"!");
    }
    cout<<"AI: ";
    stringstream l2(tmp);
    k=0;
    while(l2>>token){
        if(k) cout<<" ";
        int number=0;
        if(token==v1[k]
            &&((token.find("I")!=string::npos)||(token.find("me")!=string::npos))
            // &&(token=="I"||token=="me"||(!is1(token[0])&&(token.substr(1,token.size()-1)=="I"||token.substr(1,token.size()-1)=="me")))
        ){
            int i1=token.find("I"),i2=token.find("me");
            if(i1!=string::npos&&(!i1||(!is3(token[i1-1])))&&(i1+1==token.size()||(!is3(token[i1+1]))))  token.replace(i1,1,"you");
            if(i2!=string::npos&&(!i2||(!is3(token[i2-1])))&&(i2+2==token.size()||(!is3(token[i2+2])))) token.replace(i2,2,"you");      

        }
        cout<<token;
        k++;
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    cin.ignore();
    while(t--){
        sol();
    }
    return 0;
} 