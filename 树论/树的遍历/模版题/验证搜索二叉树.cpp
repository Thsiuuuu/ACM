#include <climits>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 方法1：迭代中序遍历
bool isValidBST1(TreeNode* head) {
    if (head == nullptr) {
        return true;
    }
    std::stack<TreeNode*> stack;
    TreeNode* pre = nullptr;
    while (!stack.empty() || head != nullptr) {
        if (head != nullptr) {
            stack.push(head);
            head = head->left;
        } else {
            head = stack.top();
            stack.pop();
            if (pre != nullptr && pre->val >= head->val) {
                return false;
            }
            pre = head;
            head = head->right;
        }
    }
    return true;
}

// 方法2：递归验证
long long min = LLONG_MAX;
long long max = LLONG_MIN;

bool isValidBST2(TreeNode* head) {
    if (head == nullptr) {
        min = LLONG_MAX;
        max = LLONG_MIN;
        return true;
    }
    bool lok = isValidBST2(head->left);
    long long lmin = min;
    long long lmax = max;
    bool rok = isValidBST2(head->right);
    long long rmin = min;
    long long rmax = max;
    min = std::min(std::min(lmin, rmin), (long long)head->val);
    max = std::max(std::max(lmax, rmax), (long long)head->val);
    return lok && rok && lmax < head->val && head->val < rmin;
}