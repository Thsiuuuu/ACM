#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int n=7,ans;
int vis[8][8];

void dfs(int u, int v, int depth) 
{
    if (depth == 48) {
        if (u == n && v == 1) ans++;
        return;
    }

    if (u == n && v == 1) return;

    if (check(u, v)) return;
    
    char req = s[depth];
    for (int i = 0; i < 4; i++) {
        if (req != '?' && req != dir[i]) continue;
        
        int x = u + dx[i], y = v + dy[i];
        if (x < 1 || x > n || y < 1 || y > n || vis[x][y]) continue;
        
        vis[x][y] = 1;
        dfs(x, y, depth + 1);
        vis[x][y] = 0;
    }
}

int main(){
    cin>>s;
    dfs(1,1,0);
    cout<<ans;
    return 0;
}