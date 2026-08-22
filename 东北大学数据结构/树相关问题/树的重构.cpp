#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(const vector<int>& pre, int l1, int r1,
                          const vector<int>& in, int l2, int r2,
                          const unordered_map<int, int>& map) {
    if (l1 > r1) return nullptr;
    
    TreeNode* root = new TreeNode(pre[l1]);
    if (l1 == r1) return root;
    
    int k = map.find(pre[l1])->second; // 在中序数组中找到根节点位置
    int leftSize = k - l2; // 左子树节点数量
    
    // 递归构建左子树和右子树
    root->left = buildTreeHelper(pre, l1 + 1, l1 + leftSize, in, l2, k - 1, map);
    root->right = buildTreeHelper(pre, l1 + leftSize + 1, r1, in, k + 1, r2, map);
    
    return root;
}

TreeNode* buildTree(const vector<int>& pre, const vector<int>& in) {
    if (pre.empty() || in.empty() || pre.size() != in.size()) {
        return nullptr;
    }
    
    // 构建值到索引的映射
    unordered_map<int, int> valToIndex;
    for (int i = 0; i < in.size(); i++) {
        valToIndex[in[i]] = i;
    }
    
    return buildTreeHelper(pre, 0, pre.size() - 1, in, 0, in.size() - 1, valToIndex);
}

void change(TreeNode* root,vector<int>& post){
    if(root==nullptr) return ;
    change(root->left,post);
    change(root->right,post);
    post.push_back(root->val);
}

int main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;

    vector<int> pre(n),in(n);
    
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>in[i];

    vector<int> post;
    TreeNode* root=buildTree(pre,in);

    change(root,post);

    for(int i=0;i<n;i++){
        if(i) cout<<" ";
        cout<<post[i];
    }

    return 0;
}