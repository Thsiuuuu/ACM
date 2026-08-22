## 虚树
### 法一：二次排序+LCA连边

1.  把所有点按DFS序排序
2.  枚举相邻两个数，两两求LCA并加入序列A中
3.  按照DFS从小到大排序并去重
4.  枚举相邻两点编号$x,y$，求$LCA$并连接$LCA(x,y),y$

总时间复杂度$O(klogn)$,$k$为关键点数，$n$为总点数，**常数较大（存疑？）**

### 法二：单调栈法

用单调栈维护虚树上的链，从底部到栈首是递增的。

出入栈时间复杂度$O(\sum k)$，排序和求LCA时间复杂度$O(\sum(k\log k+k\log n)),k$为每次的关键点数


代码
```cpp
    vector<int> p(k+1);   
    bool yes=false;
    for(int i=0;i<k;i++){
        cin>>p[i];
        is[p[i]]=true;
    }

    if(!is[1]) p.push_back(1);
    sort(p.begin(),p.end(),[&](int x,int y)->bool{
        return dfn[x]<dfn[y];
    });

    stk[++top]=p[0];
    int siz=p.size();
    for(int i=1;i<siz;i++){
        int lca=LCA(stk[top],p[i]);
        while(top>=2&&dep[stk[top-1]]>=dep[lca]){
            vt[stk[top-1]].push_back(stk[top--]);
        }
        if(lca^stk[top]){ vt[lca].push_back(stk[top]);  stk[top]=lca; p.push_back(lca);}
        stk[++top]=p[i];
    }
    while(top) vt[stk[top-1]].push_back(stk[top--]);
    dfs(1,yes);
    if(yes) cout<<"-1\n";
    else    cout<<f[1]<<'\n';
    for(int i=0;i<p.size();i++){
        g[p[i]]=is[p[i]]=false;
        f[p[i]]=0;
        vt[p[i]].clear();
    } 
    top=0;
```