#include <iostream>

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

// 递归基本样子，用来理解递归序
void f(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    // 1
    f(head->left);
    // 2
    f(head->right);
    // 3
}

// 先序打印所有节点
void preOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    std::cout << head->val << " ";
    preOrder(head->left);
    preOrder(head->right);
}

// 中序打印所有节点
void inOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    std::cout << head->val << " ";
    inOrder(head->right);
}

// 后序打印所有节点
void posOrder(TreeNode* head) {
    if (head == nullptr) {
        return;
    }
    posOrder(head->left);
    posOrder(head->right);
    std::cout << head->val << " ";
}

// 释放二叉树内存
void destroyTree(TreeNode* head) {
    if (head == nullptr) return;
    destroyTree(head->left);
    destroyTree(head->right);
    delete head;
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
    std::cout << std::endl;
    std::cout << "先序遍历递归版" << std::endl;

    inOrder(head);
    std::cout << std::endl;
    std::cout << "中序遍历递归版" << std::endl;

    posOrder(head);
    std::cout << std::endl;
    std::cout << "后序遍历递归版" << std::endl;

    // 释放内存
    destroyTree(head);

    return 0;
}