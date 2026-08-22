#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000001;

int arr[MAXN];
int stack[MAXN];
int ans[MAXN][2];
int n, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // 计算左右最近且小的位置
        r = 0;
        for (int i = 0; i < n; i++) {
            while (r > 0 && arr[stack[r - 1]] >= arr[i]) {
                int cur = stack[--r];
                ans[cur][0] = r > 0 ? stack[r - 1] : -1;
                ans[cur][1] = i;
            }
            stack[r++] = i;
        }
        
        // 清算阶段
        while (r > 0) {
            int cur = stack[--r];
            ans[cur][0] = r > 0 ? stack[r - 1] : -1;
            ans[cur][1] = -1;
        }
        
        // 修正阶段
        for (int i = n - 2; i >= 0; i--) {
            if (ans[i][1] != -1 && arr[ans[i][1]] == arr[i]) {
                ans[i][1] = ans[ans[i][1]][1];
            }
        }
        
        // 输出结果
        for (int i = 0; i < n; i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
    
    return 0;
}