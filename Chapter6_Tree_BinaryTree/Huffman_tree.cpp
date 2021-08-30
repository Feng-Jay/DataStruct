#include <iostream>
#include <string.h>

using namespace std;

const int MAXW=2147483647;

struct HFNode{
    int weight;
    int parent,lchild,rchild;
};

void Huffman_coding(HFNode *&root,char **&Hcode,int *w, int n);
void select(HFNode* &root,int upper,int &s1,int &s2);


int main()
{
    HFNode *root;
    char** Hcode;
    int n;
    cout<<"Please input the number of char"<<endl;
    cin>>n;
    int w[n];
    cout<<"Please input the weight of each char"<<endl;
    for(int i=0;i<n;i++)
    cin>>w[i];
    Huffman_coding(root,Hcode,w,n);
    return 0;
}

void Huffman_coding(HFNode *&root,char **&Hcode,int *w, int n)
{
    if(n<=0) return ;
    int m=2*n-1;
    int s1,s2;
    root= new HFNode[m+1];
    HFNode *p=root+1;
    for(int i=1;i<=n;i++,p++,w++) *p={*w,0,0,0};
    for(int i=n+1;i<=m;i++,p++) *p={0,0,0,0};
    for(int i=n+1;i<=m;i++){
        select(root,i-1,s1,s2);
        root[s1].parent=i; root[s2].parent=i;
        root[i].lchild=s1; root[i].rchild=s2;
        root[i].weight=root[s1].weight+root[s2].weight;
    }

    Hcode=new char*[n+1];
    char code[n]; code[n-1]='\0';
    int start,child,parent;
    cout<<"Please input the chars"<<endl;
    for(int i=1;i<=n;i++){
        start=n-1;
        child=i; parent=root[child].parent;
        while(parent!=0){
            if(child==root[parent].lchild) code[--start]='0';
            else code[--start]='1';
            child=parent;
            parent=root[parent].parent;
        }
        Hcode[i]=new char[n-start+1];
        cin>>Hcode[i][0];
        for(int j=1;j<=n-start;j++)
        Hcode[i][j]=code[start+j-1];
        cout<<Hcode[i][0]<<": ";
        for(int j=1;j<=n-start;j++)
        cout<<Hcode[i][j];
        cout<<endl;
    }
}

void select(HFNode* &root,int upper,int &s1,int &s2)
{
    int min1,min2;
    min1=MAXW;min2=MAXW;
    int flag;
    for(int i=1;i<=upper;i++){
        if(root[i].parent==0&&root[i].weight<=min1){
            min1=root[i].weight;
            flag=i;
        }
    }
    s1=flag; root[flag].parent=upper+1;
    for(int i=1;i<=upper;i++){
        if(root[i].parent==0&&root[i].weight<=min2){
            min2=root[i].weight;
            flag=i;
        }
    }
    s2=flag; root[flag].parent=upper+1;
}