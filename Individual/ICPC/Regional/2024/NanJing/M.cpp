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
#define db double
const db eps=1e-6;
const db PI=acos(-1);
struct Point{
    db x,y;
    Point(){}
    Point(db x,db y):x(x),y(y){}
    db dis(){
        return sqrt(x*x+y*y);
    }
};
db cal(db a){
    if(a<=eps) a=2*PI-a;
    return a;
}

void out(db x){
    cout<<x<<'\n';
}


void sol() {
    int n,x0,y0,d;
    db t;
    cin>>n>>x0>>y0>>d>>t;
    vector<Point> p(n);
    vector<db> Ang;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        Ang.push_back(atan2(p[i].y,p[i].x)+asin(d/p[i].dis()));
        Ang.push_back(atan2(p[i].y,p[i].x)-asin(d/p[i].dis()));
    }
    for(int i=0;i<Ang.size();i++){
        if(Ang[i]<0) Ang[i]+=2*PI;
    }
    sort(Ang.begin(),Ang.end());
    db pln;
    db L,R;
    for(int i=0;i<Ang.size();i++){
        if(i==0){
            pln=Ang[0]+2*PI-Ang[2*n-1];
            R=Ang[2*n-1],L=Ang[0];
        }else{
            if(Ang[i]-Ang[i-1]>pln){
                L=Ang[i],R=Ang[i-1];
                pln=Ang[i]-Ang[i-1];
            }
        }
    }
    if(R<L) R+=2*PI;
    db ans=0;
    db du=atan2(y0,x0);
    if(du<0) du+=2*PI;
    for(int k=-1;L-du+2*k*PI<=t;k++){
        db r=min(R-du+2*k*PI,t),
           l=max((db)0,L-du+2*k*PI);
        if(r>l){
            ans+=(min(R-du+2*k*PI,t)-max((db)0,L-du+2*k*PI));
        }
    }
    cout<<fixed<<setprecision(8)<<ans;
    // if(du<=eps) du=2*PI-du;
    // cout<<Ang[2*n-1]<<'\n';
    // if(du+eps>=Ang[0]&&du<=Ang[2*n-1]+eps){
    //     tmp=min((db)t,Ang[2*n-1]-du);   
    //     du+=tmp;
    // }else if(
    //     Ang[0]>=eps
    //     &&
    //     Ang[2*n-1]<=eps
    //     &&
    //     cal(du)>=Ang[0]-eps&&cal(du)<=Ang[2*n-1]+eps
    // ){
    //     tmp=min((db)t,Ang[2*n-1]-du);
    //     du+=tmp;
    //     if(du>=PI-eps){
    //         du=2*PI-du;
    //     }
    // }
    // // cout<<du<<'\n';
    // // cout<<tmp<<'\n';
    // // if(du<=eps) du=2*PI-du;
    // db ans=tmp,one=min(abs(2*PI-(Ang[2*n-1]-Ang[0])),abs(Ang[2*n-1]-Ang[0]));
    // // cout<<one<<'\n';
    // db L=cal(Ang[2*n-1]),R=cal(Ang[0]);
    // t-=(tmp);
    // // out(t);
    // tmp=min({t,2*PI-one});
    // if(cal(du)<=R+eps){
    //     tmp=min({tmp,R-du});
    // }else if(Ang[0]>=-eps&&Ang[0]+2*PI>=cal(du)){
    //     tmp=min({tmp,Ang[0]+2*PI-cal(du)});
    // }
    // t-=tmp;
    // // cout<<t<<'\n';
    // int mal=(t/2/PI+eps);
    // ans+=(db)mal*one;
    // ans+=min(one,(t-t*mal)*2*PI);
    // cout<<fixed<<setprecision(8)<<ans;
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