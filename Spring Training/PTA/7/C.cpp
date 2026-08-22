    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long 
    #define pii pair<int,int>
    #define ld long double

    const int N=1010;
    ld a[N][N];
    int sex[N];

    // struct node{
    //     int sex;    
    //     double dis;
    //     int idx;
    //     bool operator<(const node&other)const{
    //         if(sex==other.sex) return true;
    //         if(dis==other.dix) return idx<other.idx;
    //         return dis<other.dis;
    //     }    
    // };

    bool cmp(pair<int,ld>&l1,pair<int,ld>&l2){
        if(l1.second==l2.second) return l1.first<l2.first;
        return l1.second>l2.second;
    }

    void sol(){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++) sex[i]=1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         a[i][j]=a[j][i]=0;
        //     }
        // }
        while(m--){
            int k;cin>>k;
            vector<int> all(k);
            for(int i=0;i<k;i++) cin>>all[i];
            for(int i=0;i<k;i++){
                for(int j=i+1;j<k;j++){
                    if(all[i]<0) all[i]=abs(all[i]),sex[all[i]]=-1;
                    if(all[j]<0) all[j]=abs(all[j]),sex[all[j]]=-1;
                    if(all[j]^all[i]){
                        a[all[i]][all[j]]+=1.0/k,a[all[j]][all[i]]+=1.0/k;
                    }
                }
            }
            // for(int i=0;i<k;i++) cout<<all[i]<<" ";
            // cout<<'\n';
        }
        // for(int i=0;i<n;i++) cout<<sex[i]<<" ";
        int x,y;
        cin>>x>>y;
        x=abs(x),y=abs(y);
        vector<pair<int,ld>> a1,a2;
        for(int i=0;i<n;i++){
            if(i^x){
                // cout<<i<<" "<<a[x][i]<<'\n';
                a1.push_back({i,a[x][i]});
            }
            if(y^i){
                // cout<<i<<" "<<a[y][i]<<'\n';
                a2.push_back({i,a[y][i]});
            }
        }
        // for(int i=0;i<a1.size();i++){
        //     cout<<a1[i].first<<" "<<a1[i].second<<'\n';
        // }
        // for(int i=0;i<a2.size();i++){
        //     cout<<a2[i].first<<" "<<a2[i].second<<'\n';
        // }
        // sort(a1.begin(),a1.end(),cmp);
        // sort(a2.begin(),a2.end(),cmp);

        // for(int i=0;i<a1.size();i++){
        //     cout<<a1[i].first<<" "<<a1[i].second<<'\n';
        // }
        // for(int i=0;i<a2.size();i++){
        //     cout<<a2[i].first<<" "<<a2[i].second<<'\n';
        // }

        ld mx1=-1,mx2=-1;
        for(int i=0;i<a1.size();i++){
            mx1=max(mx1,a1[i].second);
        }
        for(int i=0;i<a2.size();i++){
            mx2=max(mx2,a2[i].second);
        }
        // cout<<mx1<<" "<<mx2<<'\n';
        if(mx1==a[x][y]&&mx2==a[x][y]){
            cout<<x*sex[x]<<" "<<y*sex[y]<<'\n';
        }else{
            int j=0;
            while(j<a1.size()){
                // cout<<j<<" ";
                if(sex[x]!=sex[a1[j].first]&&mx1==a1[j].second){
                    cout<<x*sex[x]<<" "<<a1[j].first*sex[a1[j].first]<<"\n";
                }
                j++;
            }   
            j=0;
            // cout<<'\n';
            while(j<a2.size()){
                // cout<<j<<" ";
                if(sex[y]!=sex[a2[j].first]&&mx2==a2[j].second){
                    cout<<y*sex[y]<<" "<<a2[j].first*sex[a2[j].first]<<"\n";
                }
                j++;
            }
        }
    }

    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);

        int t=1;
        // cin>>t;
        while(t--){
            sol();
        }
        return 0;
    }