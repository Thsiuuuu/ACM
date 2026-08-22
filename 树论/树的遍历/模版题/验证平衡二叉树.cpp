#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool balance = true;

int height(TreeNode* cur) {
    if (!balance || cur == nullptr) {
        return 0;
    }
    int lh = height(cur->left);
    int rh = height(cur->right);
    if (std::abs(lh - rh) > 1) {
        balance = false;
    }
    return std::max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    balance = true;
    height(root);
    return balance;
}