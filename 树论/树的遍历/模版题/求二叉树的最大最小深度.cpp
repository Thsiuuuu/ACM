#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


// 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
//树的最大深度
int maxDepth(TreeNode* root) {
    return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/

//树的最小深度
int minDepth(TreeNode* root) {
    if (root == nullptr) {
        // 当前的树是空树
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        // 当前root是叶节点
        return 1;
    }
    int ldeep = INT_MAX;
    int rdeep = INT_MAX;
    if (root->left != nullptr) {
        ldeep = minDepth(root->left);
    }
    if (root->right != nullptr) {
        rdeep = minDepth(root->right);
    }
    return min(ldeep, rdeep) + 1;
}