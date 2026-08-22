#include <bits/stdc++.h>
using namespace std;

int fa[27];
struct node{
    char c='&';
    int l,r;
}node[27];

void dfs(int u){
    cout<<node[u].c;
    if(node[u].l!=-1) dfs(node[u].l);
    if(node[u].r!=-1) dfs(node[u].r);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        node[s[0]-'a'].c=s[0];
        if(s[1]=='*'){
            node[s[0]-'a'].l=-1;
        }else{
            node[s[0]-'a'].l=s[1]-'a';
            fa[s[1]-'a']=1;
        }
        if(s[2]=='*'){
            node[s[0]-'a'].r=-1;
        }else{
            node[s[0]-'a'].r=s[2]-'a';
            fa[s[2]-'a']=1;
        }
    }
    int root;
    for(int i=0;i<26;i++){
        if(node[i].c!='&'&&fa[i]==0){
            root=i;
            break;
        }  
    }
    dfs(root);
    return 0;
}