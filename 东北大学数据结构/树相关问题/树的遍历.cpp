#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};



vector<TreeNode*> nodes;
bool is_child[27];


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
    
    int n;
    cin>>n;
    nodes.resize(n);

    vector<pair<int,int>> children(n);
    fill(is_child,is_child+27,false);

    for(int i=0;i<n;i++){
        int val,l,r;
        cin>>val>>l>>r;
        nodes[val]=new TreeNode(val);
        
        children[val]={l,r};
    }

    for(int val=0;val<n;val++){
        int l=children[val].first;
        int r=children[val].second;
        if(l!=-1){
            nodes[val]->left=nodes[l];
            is_child[l]=true;
        }
        if(r!=-1){
            nodes[val]->right=nodes[r];
            is_child[r]=true;
        }
    }

    int rootid=-1;
    for(int i=0;i<n;i++){
        if(!is_child[i]){
            rootid=i;
            break;
        }
    }

    TreeNode* head=nodes[rootid];

    
    
    std::cout <<"Preorder"<< std::endl;
    preOrder(head);
    std::cout << std::endl;

    std::cout << "Inorder" << std::endl;
    inOrder(head);
    std::cout << std::endl;
    

    
    std::cout << "Postorder" << std::endl;
    posOrder(head);
    std::cout << std::endl;
    

    // 释放内存
    destroyTree(head);

    return 0;
}