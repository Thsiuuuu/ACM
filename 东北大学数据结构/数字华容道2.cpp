#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

const vector<int> target={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};


string tostring(const vector<int>&state){

    string s;
    for(int num:state) s+=to_string(num)+",";
    return s;

}


int findzero(const vector<int>& state){
    for(int i=0;i<state.size();i++){
        if(!state[i]) return i;
    }
}

bool istarget(const vector<int>&state){
    return state==target;
}

int bfs(){
    vector<int> initial(16);
    for(int i=0;i<16;i++) cin>>initial[i];


    if(istarget(initial)) return 0;


    queue<pair<pair<vector<int>,int>,int>> q;

    int inizero=findzero(initial);
    q.push({{initial,0},inizero});

    unordered_set<string> visited;
    visited.insert(tostring(initial));

    vector<int> dirs={-4,4,-1,1};

    while(!q.empty()){

        auto tag=q.front();
        auto cur=tag.first.first;
        auto steps=tag.first.second;
        auto zero=tag.second;

       // auto [cur,steps,zero]=q.front();

        q.pop();


        int row=zero/4;
        int col=zero%4;

        for(int dir:dirs){
            int newzero=zero+dir;
            int newrow=newzero/4;
            int newcol=newzero%4;

            if(newrow<0||newrow>=4||newcol<0||newcol>=4) continue;

            vector<int> newstate=cur;
            swap(newstate[zero],newstate[newzero]);

            if(istarget(newstate)) return steps+1;

            string newstatestr=tostring(newstate);
            if(visited.find(newstatestr)==visited.end()){
                visited.insert(newstatestr);
                q.push({{newstate,steps+1},newzero});
            }
        }
    }

    return -1;
}

int main(){
    cout<<bfs();
    return 0;
}