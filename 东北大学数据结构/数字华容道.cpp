#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

string target ="123456780";
int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int bfs(string start){

    queue<pair<string,int>> q;
    unordered_map<string,bool> visited;

    q.push({start,0});
    visited[start]=true;
    while(!q.empty()){
        auto [state,steps]=q.front();
        q.pop();

        if(state==target) return steps;

        int zero=state.find('0');
        int x=zero/3;
        int y=zero%3;

        for(auto& [dx,dy]:dirs){
            int nx=x+dx;
            int ny=y+dy;

            if(nx>=0&&nx<3&&ny>=0&&ny<3){
                string newstate=state;
                int newpos=nx*3+ny;
                swap(newstate[zero],newstate[newpos]);

                if(!visited[newstate]){
                    visited[newstate]=true;
                    q.push({newstate,steps+1});
                }
            }
        }
    }
    return -1;
}


int main(){
    string start;
    for(int i=0;i<9;i++){
        int num;
        cin>>num;
        start+='0'+num;
    }

    cout<<bfs(start)<<"\n";
    return 0;
}