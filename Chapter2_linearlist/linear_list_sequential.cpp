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
   
    //new操作失败并不会返回空指针，而是抛出异常.所以传统的if(xx==0)完全没有意义。
    //使用这样的方式来检测
    try{
         L.elem=new int[List_size];
    }catch(const bad_alloc&e){
        return -1;
    }
    L.len=0;
    L.listsize=List_size;
    return 1;
}

bool Insert_List(SqList&L, int i, eletype e)
{
    //在第i个位置前插入元素
    if(i<1||i>L.len+1){
        cout<<"INSERT:i Beyon Limit"<<endl;
        return -1;
    }
    if(L.len>=L.listsize){
        eletype *newbase;
        try{
            newbase=new int[List_size+List_Size_Increment];
        }catch(bad_alloc&e){
            return -1;
        }
        L.elem=newbase;
        L.listsize+=List_Size_Increment;
    }
    int *begin=&(L.elem[i-1]);
    int *end=&(L.elem[L.len-1]);
    for(begin;begin<=end;end--){
        *(begin+1)=*begin;
    }
    *begin=e;
    L.len++;
    return 1;
}

eletype Delete_List(SqList& L, int i,eletype &e)
{
    //删除第i个元素，用e返回其值
    if(i<1||i>L.len){
        cout<<"DLELTE:i Beyon Limit"<<endl;
        return -1;
    }
    int *begin=&(L.elem[i-1]);
    int *end=&(L.elem[L.len-1]);
    e=L.elem[i-1];
    for(++begin;begin<=end;begin++){
        *(begin-1)=*(begin);
    }
    L.len--;
    return e;
}

int Locate_List(SqList &L,eletype e)
{
    //找到L中值为e的第一个位置并返回
    eletype* p =L.elem;
    for(int i=0;i<L.len;i++){
        if(*(p+i)==e){
            return i;
        }
    }
    return -1;
}

bool Merge_List(SqList &La, SqList &Lb, SqList &Lc)
{
    Lc.len=La.len+Lb.len;
    Lc.listsize=La.len+Lb.len;
    try{
         Lc.elem=new eletype [Lc.len];
    }catch(const bad_alloc&e){
        return -1;
    }
    eletype *pa=La.elem;
    eletype *pb=Lb.elem;
    eletype *pc=Lc.elem;
    eletype *paend=&La.elem[La.len-1];
    eletype *pbend=&La.elem[La.len-1];

    while(pa<=paend&&pb<=pbend){
        if(*pa<=*pb) *(pc++)=*(pa++);
        else *(pc++)=*(pb++);
    }
    while(pa<=paend){
        *(pc++)=*(pa++);
    }
    while(pb<=pbend){
        *(pc++)=*(pb++);
    }
}

int main()
{
    // eletype e;
    SqList L;
    Init_List(L);
    Insert_List(L,1,2);
     Insert_List(L,2,3);
    //Delete_List(L,1,e);
    int temp=Locate_List(L,3);
    cout<<temp<<endl;
    return 0;
}
