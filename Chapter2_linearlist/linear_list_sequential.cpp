/*线性表的顺序实现*/

#include <iostream>
#include <new>

using namespace std;

const int List_size=100;
const int List_Size_Increment=10;
typedef int eletype;

typedef struct{
    eletype *elem;
    int len;
    int listsize;
}SqList;

bool Init_List(SqList &L){
    //为什么要传引用？
    //因为Init函数只返回bool量，而非结构体，所以在把L传进去后L就会被销毁，导致内存出现问题
    L.elem=new int[List_size];
    //new操作失败并不会返回空指针，而是抛出异常.所以传统的if(xx==0)完全没有意义。
    //使用这样的方式来检测
    if(L.elem==0){
        cout<<"New fault"<<endl;
        return -1;
    }
    L.len=0;
    L.listsize=List_size;
    return 1;
}

int main()
{
    SqList L;
    Init_List(L);
    return 0;
}
