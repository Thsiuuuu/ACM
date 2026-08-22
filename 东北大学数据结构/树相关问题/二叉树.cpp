#include <iostream>
#include <queue>
#include <functional>
#include <string>

using namespace std;

struct Node
{

    int left=-1;
    int right=-1;
    int parent=-1;
    int deg=0;
    int dep=0;
    int h=0;
    int sibling =-1;
    string type;
    /* data */
};


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n;
    cin>>n;
    Node nodes[26];


    for(int i=0;i<n;i++){
        int id,left,right;
        cin>>id>>left>>right;
        nodes[id].left=left;
        nodes[id].right=right;
        if(left!=-1) nodes[left].parent=id;
        if(right!=-1) nodes[right].parent=id;
    }

    //寻找根节点
    int root=-1;
    for(int i=0;i<n;i++){
        if(nodes[i].parent==-1){
            root=i;
            break;
        }
    }


    //计算子节点数
    for(int i=0;i<n;i++){
        int cnt=0;
        if(nodes[i].left!=-1) cnt++;
        if(nodes[i].right!=-1) cnt++;
        nodes[i].deg=cnt;
    }

    //BFS计算深度
    queue<int> q;
    q.push(root);
    nodes[root].dep=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int left=nodes[u].left,right=nodes[u].right;
        if(left!=-1){
            nodes[left].dep=nodes[u].dep+1;
            q.push(left);
        }
        if(right!=-1){
            nodes[right].dep=nodes[u].dep+1;
            q.push(right);
        }
    }



    //递归计算高度
    function<int(int)> getHeight=[&](int id)->int{
        if(id==-1) return -1;
        int left_h=getHeight(nodes[id].left);
        int right_h=getHeight(nodes[id].right);
        return max(left_h,right_h)+1;
    };

    for(int i=0;i<n;i++) nodes[i].h=getHeight(i);

    //计算兄弟节点
    for(int i=0;i<n;i++){
        int p=nodes[i].parent;
        if(p==-1) nodes[i].sibling=-1;
        else{
            int pl=nodes[p].left,pr=nodes[p].right;
            nodes[i].sibling=(pl==i)?pr:pl;
        }
    }

    //确定节点类型
    for(int i=0;i<n;i++){
        if(nodes[i].parent==-1) nodes[i].type="root";
        else nodes[i].type=(nodes[i].deg==0)?"leaf":"internal node";
    }

    for(int i=0;i<n;i++){
        cout<<"node "<<i<<": parent = "<<nodes[i].parent
            <<", sibling = "<<nodes[i].sibling
            <<", degree = "<<nodes[i].deg
            <<", depth = "<<nodes[i].dep
            <<", height = "<<nodes[i].h
            <<", "<<nodes[i].type<<"\n";
    }

    return 0;
}