#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

struct node{
	int x,y;
	int len;
	int from;
	node(int x,int y,int len,int from):x(x),y(y),len(len),from(from){}
	bool operator<(const node&other)const{
		if(x==other.x){
			if(y==other.y){
				if(len==other.len){
					return from<other.from;
				}
				return len<other.len;
			}
			return y<other.y;;
		}
		return x<other.x;
	}	
};

void sol(){
	int n,m;
	cin>>n>>m;
	vector<vector<char>> a(n+1,vector<char>(m+1));
	pii s,t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='S') s={i,j};
			else if(a[i][j]=='T') t={i,j};
		}
	}
//	vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
	map<node,bool> mp;
	queue<pair<node,int>> q;
	q.push(make_pair(node{s.first,s.second,-1,-1},0));
	while(q.size()){
		auto[Nd,dis]=q.front();
		auto[x,y,len,from]=Nd;
		q.pop();
		if(make_pair(x,y)==t){
			cout<<dis<<'\n';
			return ;
		}
		for(int i=0;i<4;i++){
			if(len==3&&i==from){
				continue;
			}
			int px=x+dx[i],py=y+dy[i];
			if(px<=0||py<=0||px>n||py>m||a[px][py]=='#'||mp[node(px,py,1+len*(i==from),i)]) continue;
			mp[node(px,py,1+len*(i==from),i)]=true;
			q.push(make_pair(node(px,py,1+len*(i==from),i),dis+1));
		}
	}
	cout<<"-1";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int t=1;
//	cin>>t;
	while(t--){
		sol();
	}
	return 0;
}