#include <iostream>
#include <algorithm>
#include <string>


#define int long long
using namespace std;





struct Node {
    int key;
    int pri; // 优先级
    Node *left, *right;
    Node(int k, int p) : key(k), pri(p), left(nullptr), right(nullptr) {}
};


// 右旋：t 的左孩子 s 成为新根
Node* rightRotate(Node* t) {
    Node* s = t->left;
    t->left = s->right;
    s->right = t;
    return s;
}

// 左旋：t 的右孩子 s 成为新根
Node* leftRotate(Node* t) {
    Node* s = t->right;
    t->right = s->left;
    s->left = t;
    return s;
}

Node* insert(Node* root, int key, int pri) {
    if (!root) return new Node(key, pri); // 递归到底，创建新节点
    if (key < root->key) { // 插入左子树
        root->left = insert(root->left, key, pri);
        if (root->left->pri > root->pri) // 左子节点优先级更高，右旋
            root = rightRotate(root);
    } else { // 插入右子树
        root->right = insert(root->right, key, pri);
        if (root->right->pri > root->pri) // 右子节点优先级更高，左旋
            root = leftRotate(root);
    }
    return root;
}

bool find(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    else if (key < root->key) return find(root->left, key);
    else return find(root->right, key);
}

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else { // 找到目标节点
        if (!root->left && !root->right) { // 叶子节点
            delete root;
            return nullptr;
        } else if (!root->right) { // 只有左子节点
            Node* leftChild = root->left;
            delete root;
            return leftChild;
        } else if (!root->left) { // 只有右子节点
            Node* rightChild = root->right;
            delete root;
            return rightChild;
        } else { // 有两个子节点，根据优先级旋转
            if (root->left->pri > root->right->pri) {
                root = rightRotate(root); // 右旋，提升左子节点
                root->right = deleteNode(root->right, key); // 递归删除原节点
            } else {
                root = leftRotate(root); // 左旋，提升右子节点
                root->left = deleteNode(root->left, key); // 递归删除原节点
            }
        }
    }
    return root;
}

void inorderTraverse(Node* root, vector<int>& res) {
    if (!root) return;
    inorderTraverse(root->left, res);
    res.push_back(root->key);
    inorderTraverse(root->right, res);
}

void preorderTraverse(Node* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->key);
    preorderTraverse(root->left, res);
    preorderTraverse(root->right, res);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    Node* root = nullptr;
    while (m--) {
        string op;
        cin >> op;
        if (op == "insert") {
            int k, p;
            cin >> k >> p;
            root = insert(root, k, p);
        } else if (op == "find") {
            int k;
            cin >> k;
            cout << (find(root, k) ? "yes" : "no") << '\n';
        } else if (op == "delete") {
            int k;
            cin >> k;
            root = deleteNode(root, k);
        } else if (op == "print") {
            vector<int> in, pre;
            inorderTraverse(root, in);
            preorderTraverse(root, pre);
            // 输出中序
            for (size_t i = 0; i < in.size(); ++i) {
                if (i > 0) cout << ' ';
                cout << in[i];
            }
            cout << '\n';
            // 输出先序
            for (size_t i = 0; i < pre.size(); ++i) {
                if (i > 0) cout << ' ';
                cout << pre[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
