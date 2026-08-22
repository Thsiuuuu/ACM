#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define int long long
#define nul nullptr

struct  node
{
    int key;
    node* left;
    node* right;
    node* parent;
    node(int k):key(k),left(nul),right(nul),parent(nul){}

    /* data */
};

void insert(node*& root,int k){
    node* z=new node(k);
    node* y=nul;
    node* x=root;
    while(x!=nul){
        y=x;
        if(z->key<x->key) x=x->left;
        else x=x->right;
    }
    z->parent=y;
    if(y==nul) root=z;
    else if(z->key<y->key) y->left=z;
    else y->right=z;
}

bool find(node* root,int k){
    while(root!=nul){
        if(root->key==k) return true;
        else if(k<root->key) root=root->left;
        else root=root->right;
    }
    return false;
}

void inorderTraversal(node* root,vector<int>&res){
    if(root==nul) return ;
    inorderTraversal(root->left,res);
    res.push_back(root->key);
    inorderTraversal(root->right,res);
}

void preorderTraversal(node* root,vector<int>&res){
    if(root==nul) return;
    res.push_back(root->key);
    preorderTraversal(root->left,res);
    preorderTraversal(root->right,res);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int m;
    cin>>m;
    
    node*root=nul;

    while(m--){
        string op;
        int k;
        cin>>op;
        if(op=="insert"){
            cin>>k;
            insert(root,k);
        }else if(op=="find"){
            cin>>k;
            cout<<(find(root,k)?"yes":"no")<<"\n";
        }else if(op=="print"){
            vector<int> inorder,preorder;
            inorderTraversal(root,inorder);
            preorderTraversal(root,preorder);

            for(int num:inorder){
                cout<<" "<<num;
            }
            cout<<"\n";
            for(int num:preorder){
                cout<<" "<<num;
            }
            cout<<"\n";
        }
    }
    return 0;
}