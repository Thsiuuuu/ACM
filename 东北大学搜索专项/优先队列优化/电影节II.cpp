#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

typedef  pair<int,int> pii;

bool cmp(const pii& a,const pii& b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    

    int n,k;
    cin>>n>>k;

    vector<pii> movie(n);
    for(int i=0;i<n;i++){
        cin>>movie[i].first>>movie[i].second;
    }

    sort(movie.begin(),movie.end(),cmp);


    priority_queue<int,vector<int>,greater<int>> time;
    
    int cnt=0;
    for(const auto& mov:movie){

        if(time.size()<k){
            cnt++;
            time.push(mov.second);
            continue;
        }

        if(mov.first>=time.top()){
            cnt++;
            time.pop();
            time.push(mov.second);
        }
    }

    cout<<cnt;
    return 0;
}