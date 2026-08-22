#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> songs(n),sortsongs(n);
    for(int i=0;i<n;i++){
        cin>>songs[i];
        sortsongs[i]=songs[i];
    }

    sort(sortsongs.begin(),sortsongs.end());
    sortsongs.erase(unique(sortsongs.begin(),sortsongs.end()),sortsongs.end());

    unordered_map<int,int> idm;

    for(int i=0;i<n;i++){
        idm[sortsongs[i]]=i;
    }

    vector<int> tran(n);
    for(int i=0;i<n;i++){
        tran[i]=idm[songs[i]];
    }

    vector<int> last(n,-1);

    int mxlen=0;
    int left=0;

    for(int right=0;right<n;right++){
        
        int id=tran[right];
        if(last[id]>=left){
            left=last[id]+1;
        }
        last[id]=right;
        mxlen=max(mxlen,right-left+1);
    }

    cout<<mxlen;
    return 0;
}