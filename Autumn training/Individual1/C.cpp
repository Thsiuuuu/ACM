#include <bits/stdc++.h>
using namespace std;
/*


    非常好的构造题，分类讨论情况比较多
    首先考虑最简单情况，只有一种字符，那么就是原串
    其次，如果有两种字符：
    如果其中一种字符，只有一个，那么一定是它开头，剩下的放一起f()=0
    如果都是有多个字符，因为f()>=1，所以我们一定希望f()=1可以成立，并且字典序最小
    不妨设最小字符是a，那么开头最多有2个a，然后就是ba交叉，不妨设b的个数lenb,a的个数lena，这么构造一定满足lena-2<=lenb,ba之后还有多余的b就放下去
    如果lena-2>lenb，那么后缀一定有aa和前缀aa匹配，这个时候前缀不能放aa，可以构造abbbbbbbaaaaaaa，因为如果b放在a的后面，一定会有后缀ab和前缀ab对上

    最后，如果有三种字符：
    如果只有一种字符，只有一个，那么一定是它开头,剩下的放一起f()=0
    如果都是有多个字符，还是希望构造f()=1,并且字典序最小
    不妨设最小字符为a，那么开头最多有两个a，然后是xa交叉，不妨设其余字符为lenother,那么这么构造一定满足lena-2<=lenother，xa之后有多余的x就放下去
    如果lena-2>lenother,那么这个时候前缀不能是aa，可以构造axaaaaaaaaaayxxxxxxxxzzzzzzzzzzzzzz，这样字典序最小

*/
void out(char c,int&num){
    cout<<c;
    num--;
}

void sol(){
    string s,t;
    cin>>s;
    vector<int> but(27,0);//字符数量的桶
    int cnt=0;//字符种类数
    int lother=0,lmin=0;//分别记录其余的字符总数，最小的字符总数
    t=s;
    sort(t.begin(),t.end());//从小到大排序的
    bool f1=false;
    for(int i=0;i<t.size();i++){
        if(t[i]==t[0]){
            lmin++;
        }else{
            lother++;
        }
        if(++but[t[i]-'a']==1){
            cnt++;
        }
    }


    for(int i=0;i<26;i++){
        if(but[i]==1){
            cout<<(char)('a'+i);
            for(int j=0;j<t.size();j++){
                if(t[j]==(char)('a'+i)) continue;
                else cout<<t[j];
            }
            cout<<'\n';
            return ;
        }
    }

    if(cnt==1){
        cout<<s<<'\n';
        return ;
    }else if(cnt==2){
        int del=lmin-lother;
        if(del<=2){
            for(int i=1;i<=s.size();i++){
                if(i<=2){out(t[0],lmin);}
                else{
                    if(i&1){
                        out(t[s.size()-1],lother);
                    }else{
                        if(lmin){out(t[0],lmin);}
                        else{out(t[s.size()-1],lother);}
                    }
                }
            }
        }else if(del>=3){
            out(t[0],lmin);
            for(int i=0;i<=t.size();i++){
                if(lother)out(t[t.size()-1],lother);
                else if(lmin) out(t[0],lmin);
            }
        }
    }else{
        int del=lmin-lother;
        int st;
        char ob;
        for(st=0;st<=s.size()&&t[st]==t[0];st++){}//应该在排序后字符串找
        // cout<<st<<'\n';
        if(del<=2){
            for(int i=1;i<=s.size();i++){
                if(i<=2){
                    out(t[0],lmin);
                }else{
                    if(i&1){
                        out(t[st++],lother);
                    }else{
                        if(lmin){
                            out(t[0],lmin);
                        }else{
                            out(t[st++],lother);
                        }
                    }
                }
            }
        }else{
            vector<char> ans;
            for(int i=0;i<=26&&ans.size()<3;i++){
                if(but[i]) ans.push_back((char)('a'+i));
            }
            cout<<ans[0]<<ans[1];
            but[ans[0]-'a']--,but[ans[1]-'a']--;
            for(int i=0;i<t.size();i++){
                if(but[t[i]-'a']){
                    cout<<t[i];
                    but[t[i]-'a']--;
                    if(but[t[i]-'a']==0&&t[i]==ans[0]){
                        // cout<<"hel\n";
                        cout<<ans[2];
                        but[ans[2]-'a']--;
                    }
                }
            }
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}