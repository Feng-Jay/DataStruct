#include <iostream>
#include <stack>
using namespace std;
// 二叉树的特点是每个结点至多只有两棵子树，且子树有左右之分，是有序树
/*二叉树的性质*/
// 1.在二叉树的第i层至多有2^i-1个结点
// 2.深度为K的二叉树至多有2^k-1个结点
// 3.对任意二叉树，若终端结点数为n0，度为2的结点数为n2，则n0=n2+1
//      推导: 结点总数n=n0+n1+n2
//                   n=n1+2n2+1 除根结点外，每个结点都有一个入度
//               可得 n0=n2+1
// 4.具有n个结点的完全二叉树的深度为 |_log2n_|+1 因为对深度为k的BinTree 2^(k-1)-1<n<=2^k -1
// 5.对有n个结点的完全二叉树的结点按层序编号，则对任一结点i有：
//   (1)若i=1, 则结点i为二叉树的根，无双亲；若i>1，则其双亲为结点|_i/2_|
//   (2)若2i>n, 则结点i无左孩子；否则其左孩子为结点2i
//   (3)若2i+1>n, 则结点i无右孩子；否则其右孩子为2i+1

/*顺序存储表示二叉树*/ 
// #define MAX_TREE_SIZE 100
// typedef int elemtype;
// typedef elemtype SqBitree[MAX_TREE_SIZE];
// 缺点：仅适用于表示完全二叉树，否则就会出现大量存储空间用来表示空元素的情况
// 推荐使用下面的链式表示

typedef char elemtype;
struct BiTNode{
    elemtype data;
    BiTNode *left, *right;
};

int create_bintree(BiTNode *&root);
void Inorder(BiTNode* root);
void Inorder2(BiTNode* root);
void Preorder(BiTNode* root);

int main()
{
    BiTNode * bintree;
    create_bintree(bintree);
    Inorder2(bintree);
}
int create_bintree(BiTNode *&root)
{
    char ch;
    cout<<"Please input the value of tree_nodes"<<endl;
    cin>>ch;
    if(ch=='#'){
        root=NULL;
    }else {
        root=new BiTNode;
        root->data=ch;
        create_bintree(root->left);
        create_bintree(root->right);
    }
        return 0;
}

void Preorder(BiTNode* root){
    if(root){
        cout<<root->data<<endl;
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(BiTNode* root){
    stack<BiTNode*> s;
    BiTNode *temp=root;
    while(temp!=NULL||!s.empty()){
        if(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        else{
            temp=s.top()->right;
            cout<<s.top()->data;
            s.pop();
        }
    }
}

void Inorder2(BiTNode* root){
    stack<BiTNode*> s;
    s.push(root);
    BiTNode* temp=root;
    while(!s.empty()){
        while(temp!=NULL){
            temp=temp->left;
            s.push(temp);
        }
        s.pop();
        if(!s.empty()){
            temp=s.top()->right;
            cout<<s.top()->data;
            s.pop();
            s.push(temp);
        }
    }
}