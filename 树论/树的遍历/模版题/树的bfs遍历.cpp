#include <vector>
#include <queue>

using namespace std;

// 二叉树的层序遍历

// 不提交这个结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


// 提交时把方法名改为levelOrder，此方法为普通bfs，此题不推荐
vector<vector<int>> levelOrder1(TreeNode* root) {
    vector<vector<int>> ans;
    if (root != nullptr) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(currentLevel);
        }
    }
    return ans;
}


// 如果测试数据量变大了就修改这个值
const int MAXN = 2001;

TreeNode* que[MAXN];

int l, r;

// 提交时把方法名改为levelOrder，此方法为每次处理一层的优化bfs，此题推荐
vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> ans;
    if (root != nullptr) {
        l = r = 0;
        que[r++] = root;
        while (l < r) { // 队列里还有东西
            int size = r - l;
            vector<int> list;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que[l++];
                list.push_back(cur->val);
                if (cur->left != nullptr) {
                    que[r++] = cur->left;
                }
                if (cur->right != nullptr) {
                    que[r++] = cur->right;
                }
            }
            ans.push_back(list);
        }
    }
    return ans;
}