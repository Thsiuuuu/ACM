#include <cstddef> // 包含nullptr定义

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 计算从当前节点向左走到头的层数（当前节点所在层为level）
int mostLeft(TreeNode* cur, int level) {
    while (cur != nullptr) {
        level++;
        cur = cur->left;
    }
    return level - 1; // 回退到最后一个有效节点的层数
}

// 递归计算完全二叉树节点数
// cur: 当前节点，level: 当前节点所在层数，h: 整棵树的高度
int f(TreeNode* cur, int level, int h) {
    if (level == h) {
        return 1; // 叶子节点
    }
    // 计算右子树的最左节点能到达的层数
    int rightMostLeftLevel = mostLeft(cur->right, level + 1);
    if (rightMostLeftLevel == h) {
        // 左子树是满二叉树，节点数为2^(h-level) + 右子树节点数
        return (1 << (h - level)) + f(cur->right, level + 1, h);
    } else {
        // 右子树是满二叉树，节点数为2^(h-level-1) + 左子树节点数
        return (1 << (h - level - 1)) + f(cur->left, level + 1, h);
    }
}

// 主函数：计算完全二叉树的节点个数
int countNodes(TreeNode* head) {
    if (head == nullptr) {
        return 0;
    }
    // 先计算整棵树的高度（从根节点向左走到头的层数）
    int h = mostLeft(head, 1);
    return f(head, 1, h);
}