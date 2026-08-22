#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN=5e4+10;

string s;
int n;
int Sum[10][MAXN];
struct node
{
    int Name;
    int Num;
}Gene[MAXN];

bool cmp(node a,node b)
{
    if(a.Num!=b.Num)
        return a.Num>b.Num;
    return a.Name<b.Name;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    s=" "+s;
    cin>>n;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')
        {
            Sum[1][i]=Sum[1][i-1]+1;
            Sum[2][i]=Sum[2][i-1];
            Sum[3][i]=Sum[3][i-1];
            Sum[4][i]=Sum[4][i-1];
        }else if(s[i]=='T')
        {
            Sum[1][i]=Sum[1][i-1];
            Sum[2][i]=Sum[2][i-1]+1;
            Sum[3][i]=Sum[3][i-1];
            Sum[4][i]=Sum[4][i-1];
        }else if(s[i]=='G')
        {
            Sum[1][i]=Sum[1][i-1];
            Sum[2][i]=Sum[2][i-1];
            Sum[3][i]=Sum[3][i-1]+1;
            Sum[4][i]=Sum[4][i-1];
        }else if(s[i]=='C')
        {
            Sum[1][i]=Sum[1][i-1];
            Sum[2][i]=Sum[2][i-1];
            Sum[3][i]=Sum[3][i-1];
            Sum[4][i]=Sum[4][i-1]+1;
        }
    }

    while(n--)
    {
        int a,b;
        cin>>a>>b;
        for(int i=1;i<=4;i++)
        {
            Gene[i].Num=Sum[i][b]-Sum[i][a-1];
            Gene[i].Name=i;
        }
        sort(Gene+1,Gene+5,cmp);
        for(int i=1;i<=4;i++)
        {
            if(Gene[i].Name==1)
                cout<<"A";
            else if(Gene[i].Name==2)
                cout<<"T";
            else if(Gene[i].Name==3)
                cout<<"G";
            else if(Gene[i].Name==4)
                cout<<"C";
        }
        cout<<'\n';
    }

}