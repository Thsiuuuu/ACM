#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long 


struct Node
{

    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node(int k):key(k),left(nullptr),right(nullptr),parent(nullptr){}
    /* data */
};



//t最开始是空节点，z是要插入的节点
//x初始化为根节点，通过和z节点不断比较并调整，确认z的节点和父节点位置
void insert(Node*& t,int k){
    Node* z=new Node(k);
    Node* y=nullptr;
    Node* x=t;
    while(x!=nullptr){
        y=x;
        if(z->key<x->key) x=x->left;
        else x=x->right;
    }

    z->parent=y;
    if(y==nullptr) t=z;
    else if(z->key<y->key) y->left=z;
    else y->right=z;
}

void inorderTraversal(Node* root,vector<int>& result){
    if(root!=nullptr){
        inorderTraversal(root->left,result);
        result.push_back(root->key);
        inorderTraversal(root->right,result);
    }
}

void preorderTraversal(Node* root,vector<int>& result){
    if(root!=nullptr){
        result.push_back(root->key);
        preorderTraversal(root->left,result);
        preorderTraversal(root->right,result);
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int m;
    cin>>m;

    Node*t=nullptr;
    string op;
    int k;


    for(int i=0;i<m;i++){
        cin>>op;
        if(op=="insert"){
            cin>>k;
            insert(t,k);
        }else if("print"){
            vector<int> inorder,preorder;
            inorderTraversal(t,inorder);
            preorderTraversal(t,preorder);

            for(int i=0;i<inorder.size();i++){
                if(i) cout<<" ";
                cout<<inorder[i];
            }
            cout<<"\n";
            for(int j=0;j<preorder.size();j++){
                if(j) cout<<" ";
                cout<<preorder[j];
            }
            cout<<"\n";
        }
    }
    return 0;
}