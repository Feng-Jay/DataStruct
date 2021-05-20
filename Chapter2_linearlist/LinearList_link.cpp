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

bool Getelem(LinkList L, int i, eleytpe &e)
{
    //找到第i个元素的值并用e返回，L为单链表的头结点
    LinkList temp=L->next;
    int j=1;
    while(temp!=nullptr&&j<i){
        temp=temp->next;
        j++;
    }
    if(temp==nullptr||j>i)
    return 0;

    e=temp->data;
    return 1;
}

int main()
{
    LinkList L,TEMP;
    L=new LNode;
    TEMP=new LNode;
    /*Attention! 在C++中，对于结构体指针，cpu会初始给他一个存指针的空间
    此时没有空间存放结构体中的数值，所以如果不申请堆上空间就会segmentation falut
    记住，在C++中一个new一定要对应一个delete*/
    eleytpe e;
    TEMP->next=L->next;
    L->next=TEMP;
    TEMP->data=5;
    L->data=1;
    Getelem(L,1,e);
    cout<<e<<endl;
    delete L;
    delete TEMP;
    return 0;
}