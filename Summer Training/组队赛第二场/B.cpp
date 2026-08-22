    #include <bits/stdc++.h>
    using namespace std;
    /*
        /\_/\
        ( =o.o= ) *
        / >  \>
    */
    #define ll long long 
    #define i128 __int128_t
    #define ld long double
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define pil pair<int,ll>
    #define pli pair<ll,int>
    #define ull unsigned long long
    #define VI  vector<int>
    #define VII vector<VI>
    #define VL  vector<ll>
    #define VLL vector<VL>
    struct P{
        int x,y;
        bool operator<(const P&o)const{
            if(y==o.y) return x<o.x;
            return y<o.y;
        }
    }a[5],b[5],m;
    ld ji[5];
    ld mi[5];
    ld g2=1;
    ld cal(P&o1,P&o2){
        return sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
    }
    void sol() {
        for(int i=1;i<=4;i++){
            cin>>a[i].x>>a[i].y;
        }
        for(int i=1;i<=4;i++){
            cin>>b[i].x>>b[i].y;
        }
        sort(a+1,a+5);
        sort(b+1,b+5);
        // ld bi=cal(b[3],b[4]);
        ji[1]=b[1].y+g2*b[1].x;
        ji[2]=b[3].y+g2*b[3].x;
        ji[3]=b[1].y-g2*b[1].x;
        ji[4]=b[2].y-g2*b[2].x;
        // m.x=(a[1].x+a[2].x)/2.0;
        // m.y=(a[1].y+a[3].y)/2.0;
        mi[1]=a[1].y+g2*a[1].x;
        mi[2]=a[2].y-g2*a[2].x;
        mi[3]=a[3].y-g2*a[3].x;
        mi[4]=a[4].y+g2*a[4].x;
        // for(int i=1;i<=4;i++){
        //     cout<<a[i].x<<" "<<a[i].y<<'\n';
        // }
        // for(int i=1;i<=4;i++){
        //     cout<<b[i].x<<" "<<b[i].y<<'\n';
        // }

        if(b[3].x<a[1].x||b[4].y<a[1].y||b[2].x>a[2].x||b[1].y>a[4].y
            ||
            (ji[1]<ji[2]&&(ji[2]<mi[1]||ji[1]>mi[4]))
            ||
            (ji[3]<ji[4]&&(ji[4]<mi[2]||ji[3]>mi[3]))
        ){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }

    signed main() {
        ios::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);

        int t = 1;
        // cin >> t;
        while (t--) {
            sol();
        }
        return 0;
    }