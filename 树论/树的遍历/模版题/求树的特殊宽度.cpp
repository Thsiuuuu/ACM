#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

const int MAXN = 3001;

TreeNode* nq[MAXN];
long long iq[MAXN];
int l, r;

int widthOfBinaryTree(TreeNode* root) {
    int ans = 1;
    l = r = 0;
    nq[r] = root;
    iq[r++] = 1;
    while (l < r) {
        int size = r - l;
        ans = max(ans, (int)(iq[r - 1] - iq[l] + 1));
        for (int i = 0; i < size; i++) {
            TreeNode* node = nq[l];
            long long id = iq[l++];
            if (node->left != nullptr) {
                nq[r] = node->left;
                iq[r++] = id * 2;
            }
            if (node->right != nullptr) {
                nq[r] = node->right;
                iq[r++] = id * 2 + 1;
            }
        }
    }
    return ans;
}