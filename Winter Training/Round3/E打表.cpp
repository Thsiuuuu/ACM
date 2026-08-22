#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 记忆化存储：map 的 key 是排序后的堆大小集合，value 是该状态是否为必胜态
map<vector<int>, bool> memo;

/**
 * 判断当前状态是否为必胜态
 * @param state 当前所有石子堆的大小
 * @param m 堆的大小上限
 * @return true 表示先手必胜，false 表示先手必败
 */
bool canWin(vector<int> state, int m) {
    // 排序是为了消除顺序影响，实现状态压缩
    sort(state.begin(), state.end());
    if (memo.count(state)) return memo[state];

    int n = state.size();
    // 尝试所有可能的合并操作
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // 规则：合并后的两堆之和不能超过 m
            if (state[i] + state[j] <= m) {
                vector<int> next_state;
                // 生成下一个状态：去掉被合并的两堆，加入合并后的新堆
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next_state.push_back(state[k]);
                }
                next_state.push_back(state[i] + state[j]);

                // 博弈论核心：如果有一种移动能让对方进入必败态，则当前是必胜态
                if (!canWin(next_state, m)) {
                    return memo[state] = true;
                }
            }
        }
    }

    // 无法进行任何合并，或者所有移动都导致对方必胜，则当前是必败态
    return memo[state] = false;
}

void solve() {
    int max_n = 10; // 测试 n 从 1 到 10
    int max_m = 10; // 测试 m 从 1 到 10

    cout << "n\\m\t";
    for (int m = 1; m <= max_m; ++m) cout << "m=" << m << "\t";
    cout << endl << "--------------------------------------------------------------------------" << endl;

    for (int n = 1; n <= max_n; ++n) {
        cout << n << "\t";
        for (int m = 1; m <= max_m; ++m) {
            memo.clear(); // 每个不同的 m 逻辑不同，需要清空缓存
            
            // 初始状态：n 个大小为 1 的石子堆
            vector<int> initial_state(n, 1);
            bool win = canWin(initial_state, m);
            
            // 根据题目要求：0 代表先手胜，1 代表后手胜
            cout << (win ? 0 : 1) << "\t";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}