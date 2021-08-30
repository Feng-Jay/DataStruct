#include <iostream>

using namespace std;

enum PorT{Link,Clue};

typedef char elemtype;

// 遍历二叉树的过程是将二叉树中的结点按某种规则排列为一个线性队列 (非线性结构-->线性结构)
// 但以二叉链表为结构的二叉树无法直接得到结点在某一序列中的直接前驱与后继信息，只有通过遍历的动态过程才能得到
// 为了保存这种在便利过程中的信息，提出线索二叉树

struct BiThrNode{
    elemtype data;
    BiThrNode *left, *right;
    PorT Ltag,Rtag;//若tag=0，指针指向孩子；若tag=1，左指针指向前驱，右指针指向后继
};                                                                                                                                                                                                                                                                           

int create_bintree(BiThrNode *&root);
void Inthreading(BiThrNode *&root,BiThrNode *&pre);
int Inorder_Threading(BiThrNode *&root,BiThrNode *&T);

int main()
{
    BiThrNode * root;
    cout<<"Please input the value of tree_nodes"<<endl;
    create_bintree(root);
    BiThrNode * thrd;
    Inorder_Threading(thrd,root);
}

int create_bintree(BiThrNode *&root)
{
    char ch;
    cin>>ch;
    if(ch=='#'){
        root=NULL;
    }else{
        root=new BiThrNode;
        root->data=ch;
        create_bintree(root->left);
        create_bintree(root->right);
    }
    return 0;
}

void Inthreading(BiThrNode *&root,BiThrNode *&pre)
{
    if(root!=NULL){
        Inthreading(root->left,pre);
        if(root->left==NULL){root->Ltag=Clue; root->left=pre;}
        if(root->right==NULL){root->Rtag=Clue;pre->right=root;}
        pre=root;
        Inthreading(root->right,pre);
    }
}
int Inorder_Threading(BiThrNode *&root,BiThrNode *&T)
{
    root=new BiThrNode;
    BiThrNode *pre;
    root->Ltag=Link; root->Rtag=Clue;
    root->right=root;
    if(T==NULL) root->left=root;
    else{
        root->left=T; pre=root;
        Inthreading(T,pre);
        pre->Rtag=Clue;
        pre->right=root;
        root->right=pre;
    }
    return 0;
}

