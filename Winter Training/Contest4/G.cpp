#include <bits/stdc++.h>
using namespace std;
/*

    真是人类智慧了

    如果分析不出来，就尝试在已有答案的基础上进行构造
    n=5可以继承n=3的所有答案并在末尾添加2个00
    然后还缺少两个答案，这时10609和90601都是答案，因为它们可以分解成完全平方数，分别把每一位非零位用十进制表示就可以观察出来

    所以n>=5的时候的答案相当于在n-2的所有答案基础上在结尾加"00"，并构造1...6...9和9...6...1得到答案，...表示插上(n-3)/2个0
    
*/

vector<vector<string>> ans(100);

void init(){
    ans[1].push_back("1");
    ans[3].push_back("169"),ans[3].push_back("196"),ans[3].push_back("961");
    for(int i=5;i<=99;i+=2){
        for(int j=0;j<ans[i-2].size();j++){
            ans[i].push_back(ans[i-2][j]+"00");
        }
        int number=(i-3)/2;
        ans[i].push_back("1"+string(number,'0')+"6"+string(number,'0')+"9");
        ans[i].push_back("9"+string(number,'0')+"6"+string(number,'0')+"1");
    }
}

void sol() {
    int n;
    cin>>n;
    for(string s:ans[n]){
        cout<<s<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    init();
    int t = 1;
    cin >> t;

    while (t--) {
        sol();
    }
    return 0;
}