#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

#define int long long 

const int MAXN =2e5+10;
int arr[MAXN];
int n,cnt;


// i位置的数，向上调整大根堆
void heapInsert(int i) {
    while (arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}


// i位置的数，向下调整大根堆
// 当前堆的大小为size
void heapify(int i, int size) {
    int l = i * 2 + 1;
    while (l < size) {
        int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
        best = arr[best] > arr[i] ? best : i;
        if (best == i) {
            break;
        }
        swap(arr[best], arr[i]);
        
        i = best;
        l = i * 2 + 1;
    }
}

// 从顶到底建立大根堆，O(n * logn)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
void heapSort1() {
    for (int i = 0; i < n; i++) {
        heapInsert(i);
    }
    int size = n;
    while (size > 1) {
        swap(arr[0], arr[--size]);
        heapify(0, size);
    }
}

// 从底到顶建立大根堆，O(n)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
void heapSort2() {
    for (int i = n - 1; i >= 0; i--) {
        heapify(i, n);
    }
    int size = n;
    while (size > 1) {
        swap(arr[0], arr[--size]);
        heapify(0, size);
    }
}

signed main() {
    // 输入数据
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 选择排序方法
    // heapSort1();
    heapSort2();
    
    // 输出结果
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
    
    return 0;
}
