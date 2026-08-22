#include <bits/stdc++.h>
using namespace std;

int n;
const int N=110;
int mp[N][N];

/*

    从右上角开始涂
    尽量利用两个颜色交错涂，涂不了再用第三个涂

*/


void out1(int &xa,int &ya,int &la,int x,int &last,int ca){
    if(xa+la>n||ya+la>n){
        if(ya==1){
            xa+=2;
        }else if(ya==2){
            xa=2,ya=1;
        }else{
            ya-=2;
        }
        la=0;
    }
    if(ya==1&&xa>n){
        last=ca;
    }else{
        // mp[xa+la][ya+la]=ca;
        cout<<ca<<" "<<xa+la<<" "<<ya+la<<'\n';
        cout.flush();
        la++;
    }
}

void out2(int &xa,int &ya,int &la,int x,int last){
    if(xa+la>n||ya+la>n){
        if(ya==1){
            xa+=2;
        }else if(ya==2){
            xa=2,ya=1;
        }else{
            ya-=2;
        }
        la=0;
    }
    for(int i=1;i<=3;i++){
        if(i!=last&&i!=x){
            // mp[xa+la][ya+la]=i;
            cout<<i<<" "<<xa+la<<" "<<ya+la<<'\n';
            cout.flush();
            la++;
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;

    int xa,ya,la=0,xb,yb,lb=0;
    int ca,cb;
    int last=-1;    
    for(int i=1;i<=n*n;i++){
        int x;
        cin>>x;
        if(i==1){
            for(int j=1;j<=3;j++){
                if(j!=x){
                    ca=j;
                    xa=1,ya=n;
                    // mp[xa][ya]=ca;
                    cout<<ca<<" "<<xa<<" "<<ya<<'\n';
                    cout.flush();
                    la++;
                    break;
                }
            }
        }else if(i==2){
            for(int j=1;j<=3;j++){
                if(j!=x&&j!=ca){
                    cb=j;
                    xb=1,yb=n-1;
                    // mp[xb][yb]=cb;
                    cout<<cb<<" "<<xb<<" "<<yb<<'\n';
                    cout.flush();
                    lb++;
                    break;
                }
            }
        }else{
            if(last==-1){
                if(ca!=x){
                    out1(xa,ya,la,x,last,ca);
                }else{
                    out1(xb,yb,lb,x,last,cb);
                }
            }
            if(last!=-1){
                if(last==ca){
                    out2(xb,yb,lb,x,last);
                }else{
                    out2(xa,ya,la,x,last);
                }
            }
        }
    }

    // for(int i=1;i<=3;i++){
    //     cout<<'\n';
    //     for(int j=1;j<=3;j++){
    //         cout<<mp[i][j]<<" ";
    //     }
    // }

    return 0;
}