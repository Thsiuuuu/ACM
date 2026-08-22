#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int q[N];

// 实现题目要求的 Lomuto 分区
int partition(int p, int r) {
    int pivot = q[r];  // 主元是最后一个元素
    int i = p - 1;     // i 跟踪“≤ 主元”的边界
    for (int j = p; j <= r - 1; j++) {
        if (q[j] <= pivot) {
            i++;
            swap(q[i], q[j]);  // 将 q[j] 放到左边区域
        }
    }
    swap(q[i + 1], q[r]);  // 主元归位到 i+1
    return i + 1;          // 返回主元最终位置
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    int pivot_pos = partition(0, n - 1);  // 对整个数组分区（p=0，r=n-1）
    
    // 输出结果，主元位置用 [] 标注
    for (int i = 0; i < n; i++) {
        if (i == pivot_pos) {
            printf("[%d] ", q[i]);
        } else {
            printf("%d ", q[i]);
        }
    }
    return 0;
}