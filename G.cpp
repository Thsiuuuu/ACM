#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long 
typedef pair<int,int> pii;

/*
 	按区间左右端点排序，依次处理
    同时还要去除一些操作区间，？

    同时记录左右端点，
    能贪就贪
*/

struct node{
    int l,r;
};

bool cmp(const node&a,const node&b){
    if(a.l==b.l) return a.r>b.r;
    return a.l<b.l;
}

const int N=1e5+10;
int lazy[N],



signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
    
        vector<int> num(n);
        vector<node> order(m);
        for(int i=0;i<m;i++){
            cin>>order[i].l>>order[i].r;
        }
        sort(order.begin(),order.end(),cmp);

        int point=0,tri=1;
        for(int i=order[0].l;i<=order[0].r;i++){
            num[i]=(++point);
        }
        for(int i=0;i<order[0].l;i++){
            num[i]=1;
        }//处理第一段之前
        set<int> wnd;
        point=order[0].r;//point存储上一次操作区间右侧位置
        for(int i=1;i<m;i++){
            if(point>=order[i].r){
                continue;
            }else if(point>=order[i].l){
                for(int )
            }
        }

    }
	
	
}