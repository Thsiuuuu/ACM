#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

#define endl "\n"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 大根堆，维护较小的一半元素
    priority_queue<int> maxHeap;
    // 小根堆，维护较大的一半元素
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 记录待删除的元素及其次数
    unordered_map<int, int> delayed;

    // 初始化前k个元素
    for (int i = 0; i < k; ++i) {
        maxHeap.push(nums[i]);
    }
    // 将较大的k/2个元素移到minHeap
    for (int i = 0; i < k / 2; ++i) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }

    // 输出第一个窗口的中位数
    cout << maxHeap.top() << " ";

    for (int i = k; i < n; ++i) {
        int left = nums[i - k];  // 窗口左侧要删除的元素
        int right = nums[i];     // 窗口右侧要添加的元素

        // 记录待删除元素
        delayed[left]++;

        // 计算平衡因子：left对maxHeap的影响
        int balance = (left <= maxHeap.top()) ? -1 : 0;

        // 添加新元素
        if (right <= maxHeap.top()) {
            maxHeap.push(right);
            balance++;
        } else {
            minHeap.push(right);
        }

        // 调整两个堆的平衡
        if (balance > 0) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (balance < 0) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 清理堆顶的待删除元素
        while (!maxHeap.empty() && delayed[maxHeap.top()] > 0) {
            delayed[maxHeap.top()]--;
            maxHeap.pop();
        }
        while (!minHeap.empty() && delayed[minHeap.top()] > 0) {
            delayed[minHeap.top()]--;
            minHeap.pop();
        }

        // 输出当前窗口的中位数
        cout << maxHeap.top() << " ";
    }

    return 0;
}
