#include <iostream>
#include <stack>
#include <vector>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 创建新节点
TreeNode* createNode(int v) {
    TreeNode* node = new TreeNode;
    node->val = v;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// 先序打印所有节点，非递归版
void preOrder(TreeNode* head) {
    if (head != nullptr) {
        std::stack<TreeNode*> stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            std::cout << head->val << " ";
            if (head->right != nullptr) {
                stack.push(head->right);
            }
            if (head->left != nullptr) {
                stack.push(head->left);
            }
        }
        std::cout << std::endl;
    }
}

// 中序打印所有节点，非递归版
void inOrder(TreeNode* head) {
    if (head != nullptr) {
        std::stack<TreeNode*> stack;
        while (!stack.empty() || head != nullptr) {
            if (head != nullptr) {
                stack.push(head);
                head = head->left;
            } else {
                head = stack.top();
                stack.pop();
                std::cout << head->val << " ";
                head = head->right;
            }
        }
        std::cout << std::endl;
    }
}

// 后序打印所有节点，非递归版 - 两个栈实现
void posOrderTwoStacks(TreeNode* head) {
    if (head != nullptr) {
        std::stack<TreeNode*> stack;
        std::stack<TreeNode*> collect;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            collect.push(head);
            if (head->left != nullptr) {
                stack.push(head->left);
            }
            if (head->right != nullptr) {
                stack.push(head->right);
            }
        }
        while (!collect.empty()) {
            std::cout << collect.top()->val << " ";
            collect.pop();
        }
        std::cout << std::endl;
    }
}

// 后序打印所有节点，非递归版 - 一个栈实现
void posOrderOneStack(TreeNode* h) {
    if (h != nullptr) {
        std::stack<TreeNode*> stack;
        stack.push(h);
        TreeNode* lastPrinted = h; // 上一次打印的节点
        
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            if (cur->left != nullptr && lastPrinted != cur->left && lastPrinted != cur->right) {
                // 有左子树且左子树未处理
                stack.push(cur->left);
            } else if (cur->right != nullptr && lastPrinted != cur->right) {
                // 有右子树且右子树未处理
                stack.push(cur->right);
            } else {
                // 左右子树都已处理或为空
                std::cout << cur->val << " ";
                lastPrinted = cur;
                stack.pop();
            }
        }
        std::cout << std::endl;
    }
}

// 释放二叉树内存
void destroyTree(TreeNode* head) {
    if (head == nullptr) return;
    destroyTree(head->left);
    destroyTree(head->right);
    delete head;
}

// 先序遍历返回结果列表
std::vector<int> preorderTraversal(TreeNode* head) {
    std::vector<int> ans;
    if (head != nullptr) {
        std::stack<TreeNode*> stack;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            ans.push_back(head->val);
            if (head->right != nullptr) {
                stack.push(head->right);
            }
            if (head->left != nullptr) {
                stack.push(head->left);
            }
        }
    }
    return ans;
}

// 中序遍历返回结果列表
std::vector<int> inorderTraversal(TreeNode* head) {
    std::vector<int> ans;
    if (head != nullptr) {
        std::stack<TreeNode*> stack;
        while (!stack.empty() || head != nullptr) {
            if (head != nullptr) {
                stack.push(head);
                head = head->left;
            } else {
                head = stack.top();
                stack.pop();
                ans.push_back(head->val);
                head = head->right;
            }
        }
    }
    return ans;
}

// 后序遍历返回结果列表 - 两个栈实现
std::vector<int> postorderTraversalTwoStacks(TreeNode* head) {
    std::vector<int> ans;
    if (head != nullptr) {
        std::stack<TreeNode*> stack;
        std::stack<TreeNode*> collect;
        stack.push(head);
        while (!stack.empty()) {
            head = stack.top();
            stack.pop();
            collect.push(head);
            if (head->left != nullptr) {
                stack.push(head->left);
            }
            if (head->right != nullptr) {
                stack.push(head->right);
            }
        }
        while (!collect.empty()) {
            ans.push_back(collect.top()->val);
            collect.pop();
        }
    }
    return ans;
}

// 后序遍历返回结果列表 - 一个栈实现
std::vector<int> postorderTraversalOneStack(TreeNode* h) {
    std::vector<int> ans;
    if (h != nullptr) {
        std::stack<TreeNode*> stack;
        stack.push(h);
        TreeNode* lastPrinted = h;
        
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            if (cur->left != nullptr && lastPrinted != cur->left && lastPrinted != cur->right) {
                stack.push(cur->left);
            } else if (cur->right != nullptr && lastPrinted != cur->right) {
                stack.push(cur->right);
            } else {
                ans.push_back(cur->val);
                lastPrinted = cur;
                stack.pop();
            }
        }
    }
    return ans;
}

int main() {
    // 创建测试二叉树
    TreeNode* head = createNode(1);
    head->left = createNode(2);
    head->right = createNode(3);
    head->left->left = createNode(4);
    head->left->right = createNode(5);
    head->right->left = createNode(6);
    head->right->right = createNode(7);

    preOrder(head);
    std::cout << "先序遍历非递归版" << std::endl;
    
    inOrder(head);
    std::cout << "中序遍历非递归版" << std::endl;
    
    posOrderTwoStacks(head);
    std::cout << "后序遍历非递归版 - 2个栈实现" << std::endl;
    
    posOrderOneStack(head);
    std::cout << "后序遍历非递归版 - 1个栈实现" << std::endl;

    // 测试返回列表的遍历函数
    std::vector<int> preOrderList = preorderTraversal(head);
    std::cout << "先序遍历列表结果: ";
    for (int val : preOrderList) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 释放内存
    destroyTree(head);

    return 0;
}