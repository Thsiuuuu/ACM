#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define null nullptr
struct  node
{

    int key;
    node* left;
    node* right;
    node* parent;
    node(int k):key(k),left(null),right(null),parent(null){}
    /* data */
};


node* insert(node*& root,int key){
    node* newnode=new node(key);
    if(root==null) return newnode;
    node* cur=root;
    node* parent=null;
    while(cur){
        parent=cur;
        if(key<cur->key) cur=cur->left;
        else cur=cur->right;
    }


    newnode->parent=parent;
    if(key<parent->key) parent->left=newnode;
    else parent->right=newnode;

    return root;
}


node* find(node*root ,int key){
    node* cur=root;
    while(cur){
        if(cur->key==key) return cur;
        else if(key<cur->key) cur=cur->left;
        else cur=cur->right;
     }

     return null;
}


node* findmin(node* node){
    while(node->left) node=node->left;
    return node;
}

node* deletenode(node* root,int key){
    node* z=find(root,key);
    if(z==null) return root;

    node*y;
    if(z->left==null||z->right==null) y=z;
    else y=findmin(z->right);

    node* x;
    if(y->left!=null) x=y->left;
    else x=y->right;


    if(x!=null) x->parent=y->parent;

    if(y->parent==null) root=x;
    else if(y==y->parent->left) y->parent->left=x;
    else y->parent->right=x;

    if(y!=z) z->key=y->key;


    delete y;
    return root;
}

void inorder(node* root){
    if(root==null) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root==null) return ;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    node* root=null;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string op;
        cin>>op;
        if(op=="insert"){
            int k;
            cin>>k;
            root=insert(root,k);
        }else if(op=="find"){
            int k;
            cin>>k;
            cout<<(find(root,k)?"yes":"no")<<"\n";
        }else if(op=="delete"){
            int k;
            cin>>k;
            root=deletenode(root,k);
        }else if(op=="print"){
            inorder(root);
            cout<<endl;
            preorder(root);
            cout<<endl;
        }
    }

    return 0;
}