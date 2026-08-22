#include <bits/stdc++.h>
using namespace std;


constexpr int N=4e6+10,M=2e6+10,B=66,mod=1e9+7;
const double PI=acos(-1),eps=1e-8;

int T,n,m;

struct Complex{
    double x,y;
    Complex operator+(const Complex&t)const{
        return {x+t.x,y+t.y};
    }
    Complex operator-(const Complex&t)const{
        return {x-t.x,y-t.y};
    }
    Complex operator*(const Complex&t)const{
        return {x*t.x-y*t.y,x*t.y+y*t.x};
    }
}a[N],b[N];

int rev[N],bit,tot,res[N];
void fft(Complex a[],int inv){
    for(int i=0;i<tot;i++){
        if(i<rev[i]) swap(a[i],a[rev[i]]);
    }
    for(int mid=1;mid<tot;mid<<=1){
        auto w1=Complex({cos(PI/mid),inv*sin(PI/mid)});
        for(int i=0;i<tot;i+=mid*2){
            auto wk=Complex({1,0});
            for(int j=0;j<mid;j++,wk=wk*w1){
                auto x=a[i+j],y=wk*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;
            }
        }
    }
}

void workFFT(int n,int m){
    while((1<<bit)<n+m+1){
        bit++;
    }
    tot=1<<bit;
    for(int i=0;i<tot;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    fft(a,1),fft(b,1);
    for(int i=0;i<tot;i++) a[i]=a[i]*b[i];//点表示法
    fft(a,-1);//逆变换，点表示法转换为多项式表示法
    for(int i=0;i<=n+m;i++) res[i]=(int)(a[i].x/tot+0.5);//向上取整
}

int main(){
    string sa,sb;
    cin>>sa>>sb;
    n=sa.length()-1;
    m=sb.length()-1;
    for(int i=0;i<=n;i++) a[i].x=sa[n-i]-'0';
    for(int i=0;i<=m;i++) b[i].x=sb[m-i]-'0';
    workFFT(n,m);
    int top=n+m;
    int i=0;
    while(i<=top){
        if(res[i]>=10){
            res[i+1]+=res[i]/10;//进位
            top+=i==top;
            res[i]%=10;
        }
        i++;
    }
    while(!res[top]&&top>0){//去掉最高位0，同时保证答案为0不会被抹除掉
        top--;
    }
    for(int i=top;i>=0;i--) cout<<res[i];
    return 0;
}