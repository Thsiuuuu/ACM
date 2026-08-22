#include <iostream>

using namespace std;

const int N=5e5+10;


int a[N],tmp[N];

int cnt=0;

void merge_sort(int q[],int l,int r){

    if(l>=r) return ;

    int mid=l+r>>1;

    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while (i<=mid&&j<=r)
    {
        cnt++;
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
        /* code */
    }
    while(i<=mid){tmp[k++]=q[i++];cnt++;}
    while(j<=r) {tmp[k++]=q[j++];cnt++;}
    for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
    
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n%d",cnt);
    return 0;
}