## 字符串
### KMP算法
#### 前缀函数
$\pi[i]$，子串$s[0\dots i]$最长的相等的真前缀与真后缀的长度。
$\pi[0]=0$



### manacher算法
代码
```cpp
void Manacher(const string&t,int*R){
    //R记录i位置的最长回文半径（不含自己），r是回文串最右侧再+1，最后的len是最长回文半径（不含自己）+1，每次通过取min更新len的时候，r-i的len是已知最长合法+1，R和0都是已知最长合法(不含自己)

    //模板中的R是在原串当中的最长回文直径
    string s="#";
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
        R[i]=len-1;
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
}
```

#### 统计以某个点作为左端点时的回文串数量(差分)
```cpp
void Manacher(const string&t,int *R,int *diff){
    string s="#";
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
        R[i]=len-1;
        if(i+len>r){
            r=i+len;
            c=i;
        }
        if(R[i]){
            int lmin=(i-R[i]+1)/2,lmax=(i-1)/2;
            if(lmin<=lmax){
                diff[lmin]++;
                if(lmax+1<t.size()) diff[lmax]--;
            }
        }
    }
}

```