#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <set>
#define endl "\n"
using namespace std;

const int maxn=10010;
const int maxm=2000010;
int a[maxm],cnt[maxn],b[maxm];


/*
    计数排序，
    第一次cnt记录数组a中每个数的出现个数

    然后对cnt进行前缀和处理，处理后cnt[i]表示不超过i的元素个数
    也就是说在升序排序情况下，最终前cnt[i]项都不超过i
    为了维持排序的稳定性,我们采用逆序遍历的方式，
    这样可以使同数值下相对位置靠后的数最终相对位置也靠后
    即每个元素a[i]，在排序后数组中的位置应位于--cnt[a[i]] (这里下标通通从0开始)
    因为枚举到a[i]的时候，a[i]是同数值且最靠后的，它在排序后数组中的位置也应该位于末尾

*/

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];cnt[a[i]]++;}
    for(int i=1;i<maxn;i++) cnt[i]+=cnt[i-1];

    for(int i=n-1;i>=0;i--){
        b[--cnt[a[i]]]=a[i];
    }

    for(int i=0;i<n;i++) cout<<b[i]<<" ";
    return 0;

}