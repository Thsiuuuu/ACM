#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

using Path = std::vector<int>;
using Paths = std::vector<Path>;

void copy(const Path& path, Paths& ans) {
    Path copy;
    copy.reserve(path.size());
    copy.insert(copy.end(), path.begin(), path.end());
    ans.push_back(copy);
}

void f(TreeNode* cur, int aim, int sum, Path& path, Paths& ans) {
    if (cur->left == nullptr && cur->right == nullptr) {
        // 叶节点
        if (cur->val + sum == aim) {
            path.push_back(cur->val);
            copy(path, ans);
            path.pop_back();
        }
    } else {
        // 不是叶节点
        path.push_back(cur->val);
        if (cur->left != nullptr) {
            f(cur->left, aim, sum + cur->val, path, ans);
        }
        if (cur->right != nullptr) {
            f(cur->right, aim, sum + cur->val, path, ans);
        }
        path.pop_back();
    }
}

Paths pathSum(TreeNode* root, int aim) {
    Paths ans;
    if (root != nullptr) {
        Path path;
        f(root, aim, 0, path, ans);
    }
    return ans;
}