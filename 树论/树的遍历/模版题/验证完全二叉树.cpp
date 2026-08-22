#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

const int MAXN = 101;
TreeNode* queue[MAXN];
int l, r;

bool isCompleteTree(TreeNode* h) {
    if (h == nullptr) {
        return true;
    }
    l = r = 0;
    queue[r++] = h;
    // 是否遇到过左右两个孩子不双全的节点
    bool leaf = false;
    while (l < r) {
        h = queue[l++];
        if ((h->left == nullptr && h->right != nullptr) || 
            (leaf && (h->left != nullptr || h->right != nullptr))) {
            return false;
        }
        if (h->left != nullptr) {
            queue[r++] = h->left;
        }
        if (h->right != nullptr) {
            queue[r++] = h->right;
        }
        if (h->left == nullptr || h->right == nullptr) {
            leaf = true;
        }
    }
    return true;
}