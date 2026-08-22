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
constexpr int N = 1000010;
//cnt[]大小和m的最大值保持一致
char s[N];
int n;
int m, p, rk[N * 2], oldrk[N*2], sa[N * 2], id[N], cnt[N],height[N],L[N];
void sol() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    m = 128;

    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1;; w <<= 1, m = p) {  // m = p 即为值域优化
        int cur = 0;
        for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
        for (int i = 1; i <= n; i++)
        if (sa[i] > w) id[++cur] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[rk[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        p = 0;
        memcpy(oldrk, rk, sizeof(oldrk));
        for (int i = 1; i <= n; i++) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
            oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
            rk[sa[i]] = p;
        else
            rk[sa[i]] = ++p;
        }

        if (p == n) break;  // p = n 时无需再排序
    }
    for(int i=1,k=0;i<=n;i++){
        if(rk[i]==1) continue;
        if(k) k--;
        while(s[i+k]==s[sa[rk[i]-1]+k]) k++;
        height[rk[i]]=k;
    }
    ll ans=(ll)n*(n+1)*(n-1)/2;
    stack<int> stk;
    height[0]=-1;
    stk.push(0);
    for(int i=1;i<=n;i++){
        while(stk.size()&&height[stk.top()]>=height[i]) stk.pop();
        L[i]=i-stk.top();
        stk.push(i);
    }
    height[n+1]=-1;
    while(stk.size()) stk.pop();
    stk.push(n+1);
    for(int i=n;i>=1;i--){
        while(stk.size()&&height[stk.top()]>height[i]) stk.pop();
        ans-=2ll*((ll)height[i]*L[i]*(stk.top()-i));
        stk.push(i);
    }
    printf("%lld",ans);
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}