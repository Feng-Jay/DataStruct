#include <iostream>

using namespace std;

typedef int eleytpe;

typedef struct LNode{
    eleytpe data;
    struct LNode* next;//结构体自引用只能引用指针，若引用结构体，就会套娃，内存会用光。
}LNode, *LinkList; 
//因为结构体内要有自引用指针，所以在C中必须要先给结构体命名
//后面的LinkList<==>LNode *;是结构体的指针
//为了兼容C，采用这种方式写
/*C++ Mode*/
// struct LNode{
//     eleytpe data;
//     LNode *next;
// };

int Create_List(LinkList &L, int n)
{
    //构造一个n个元素的链表
    L=new LNode;
    /*Attention! 在C++中，对于结构体指针，cpu会初始给他一个存指针的空间
    此时没有空间存放结构体中的数值，所以如果不申请堆上空间就会segmentation falut
    记住，在C++中一个new一定要对应一个delete*/
    L->data=n;
    L->next=NULL;
    cout<<"Please input the REVERSE Order "<<n<<" values of n nodes"<<endl;
    for(int i=0;i<n;i++){
        LinkList temp=new LNode;
        cin>>temp->data;
        temp->next=L->next;
        L->next=temp;
    }
    return 1;
}

int Getelem(LinkList L, int i, eleytpe &e)
{
    //找到第i个元素的值并用e返回，L为单链表的头结点
    LinkList temp=L->next;
    int j=1;
    while(temp!=nullptr&&j<i){
        temp=temp->next;
        j++;
    }
    if(temp==nullptr||j>i)
    return -1;

    e=temp->data;
    return 1;
}

bool Insert_List(LinkList &L, int i, eleytpe e)
{
    //在第i个位置前插入值为e的元素
    LinkList temp=L;
    int j=0;
    while(temp!=nullptr&&j<i-1){
        temp=temp->next;
        j++;
    }
    if(temp==nullptr||j>i-1){
        cout<<"No "<<i<<"th elem"<<endl;
        return -1;
    }
    LinkList insert_e=new LNode;
    insert_e->next=temp->next;
    temp->next=insert_e;
    insert_e->data=e;
    return 1;
}

int Delete_List (LinkList &L,int i, eleytpe &e)
{
    LinkList temp=L;
    int j=0;
    while(temp!=nullptr&&j<i-1){
        temp=temp->next;
        j++;
    }
    if(temp==nullptr||j>i-1){
        cout<<"No "<<i<<"th elem!"<<endl;
        return -1;
    }
    LinkList temp2=temp->next;
    temp->next=temp2->next;
    e=temp2->data;
    delete temp2;
    return 1;
}


int main()
{
    LinkList Head;
    eleytpe e;
    Create_List(Head,10);
    cout<<Head->data<<endl;
    Getelem(Head,1,e);
    cout<<e<<endl;
}