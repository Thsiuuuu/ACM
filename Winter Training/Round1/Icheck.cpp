#include <bits/stdc++.h>
using namespace std;
/*



*/

int cnt=0;
void dfs(int x,int y,vector<vector<int>> &num,vector<set<int>> &st,int k,int n){
    if(cnt>=1){
        return ;
    }
    if(x>k){

        set<vector<int>> exam;

        bool f1=false;
        

        int sum=0;
        for(int j=1;j<=n;j++){
            for(int i=1;i<=k;i++){
                sum=sum+num[i][j];
            }
            if(sum!=(n+1)*k/2){
                f1=true;
                break;
            }
            sum=0;
        }

        for(int i=1;i<=k;i++){
            exam.insert(num[i]);
        }

        if(exam.size()<k){
            // cout<<exam.size()<<'\n';
            f1=true;
        }
        if(!f1){
            cout<<cnt<<'\n';
            for(int i=1;i<=k;i++){
                for(int j=1;j<=n;j++){
                    cout<<num[i][j]<<" ";
                }
                cout<<'\n';
            }
            cnt++;
            // cout<<cnt<<'\n';
        }
        return ;
    }
    
    int number=1;
    for(number=1;number<=n;number++){
        if(st[x].find(number)==st[x].end()){


            int sum=0;
            for(int i=1;i<=x;i++){
                sum+=num[i][y];
            }
            if(sum>k*(n+1)/2) continue;
            
            st[x].insert(number);
            num[x][y]=number;
            if(y==n){
                dfs(x+1,1,num,st,k,n);
            }else{
                dfs(x,y+1,num,st,k,n);
            }
            st[x].erase(number);
        }
    }


}
void check(int k,int n){
    vector<vector<int>> num(k+1,vector<int>(n+1));
    vector<set<int>> st(k+1);
    cout<<"k= "<<k<<" n= "<<n<<'\n';
    for(int j=1;j<=n;j++){
        num[1][j]=j;
    }
    dfs(2,1,num,st,k,n);
    if(cnt==0){
        cout<<"NO\n";
    }
    cnt=0;
}



void sol() {
    // check(3,5);
    check(2,4);
    // check(5,5);
    // check(7,5);
    // for(int i=2;i<=5;i++){
    //     for(int j=2;j<=5;j++){
    //         if(i==j) continue;
    //         check(i,j);
    //     }
    // }


    // int n,k;
    // cin>>n>>k;

    // if(k==1){
    //     cout<<"NO\n";
    // }else if(k==2){
    //     cout<<"YES\n";
    //     vector<int> a(n);
    //     iota(a.begin(),a.end(),1);
    //     for(int i=0;i<n;i++){
    //         cout<<a[i]<<" ";
    //     }
    //     cout<<'\n';
    //     reverse(a.begin(),a.end());
    //     for(int i=0;i<n;i++){
    //         cout<<a[i]<<" ";
    //     }
    //     cout<<'\n';
    // }else if(k==n){
    //     cout<<"YES\n";
    //     vector<int> a(n);
    //     iota(a.begin(),a.end(),1);
    //     for(int i=0;i<k;i++){
    //         for(int j=0;j<n;j++){
    //             cout<<a[(j+i)%n]<<" ";
    //         }
    //         cout<<'\n';
    //     }
    // }else{
    //     cout<<"NO\n";
    // }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}