/*实现静态链表*/
/*便于在没有指针的高级语言中使用链表结构
数组元素中有两个分量：一个分量代表一个结点数据，同时另一个游标分量代替指针指示结点在数组中的相对位置
数组的第0分量看作头结点*/

/*在插入、删除元素时不需要像顺序线性表一样移动大量元素，只需要修改游标cur
也因此，我们需要自己维护一个空闲结点链表和一个已分配链表：
当前链表删除元素时，将其加入空闲结点链表
当插入元素时，从空闲结点链表中选择结点加入分配链表*/

#include <iostream>

using namespace std;

const int MAX_SIZE=100;//链表的最大长度

typedef int eletype;

typedef struct{
    eletype data;
    int cur;
}node, SLinkList[MAX_SIZE];
/*SLinkList类型代表了一个有MAX_SIZE个结构体元素的数组
逻辑上等价于：
typedef struct{
    eletype data;
    int cur;
}node, [MAX_SIZE] SLinkList;
只是C compiler不认识这个形式
*/

/*我们用0号结点当作空闲结点链表的头结点
用MAX_SIZE-1号结点当作当前分配结点的头节点*/
int Init_SL(SLinkList &SL)
{
    for(int i=0;i<MAX_SIZE-1;i++){
        SL[i].cur=i+1;
    }
    SL[MAX_SIZE-1].cur=0;//因为当前链表为空，所以指向0
    return 1;
}

int get_len(SLinkList &SL)
{
    int len=0;
    int i=SL[MAX_SIZE-1].cur;
    while(i){
        i=SL[i].cur;
        len++;
    }
    return len;
}

int New_SL(SLinkList &SL)
{
    int i=0; 
    i=SL[0].cur;
    if(SL[0].cur) SL[0].cur=SL[i].cur;
    return i;
}

int Insert_SL(SLinkList &SL, int i, eletype e)
{
    /*SL第i个元素前插入值为e的元素*/
    if(i<1||i>get_len(SL)+1){
        cout<<"i beyond SL's len"<<endl;
        return -1;
    }
    int j= New_SL(SL);
    int index=MAX_SIZE-1;
    if(j){
        SL[j].data=e;
        for(int m=0;m<i-1;m++){
            index=SL[index].cur;
        }
        SL[j].cur=SL[index].cur;
        SL[index].cur=j;
        return 1;
    }
    return 0;
}

int Free_SL(SLinkList &SL,int i)
{
    /*回收下标为i的元素*/
    SL[i].cur=SL[0].cur;
    SL[0].cur=i;
    return 1;
}

int Delete_SL(SLinkList &SL, int i)
{
    /*删除表中第i个元素*/
    if(i<1||i>get_len(SL)){
        cout<<"Delete i is beyond len"<<endl;
        return -1;
    }
    int index=MAX_SIZE-1;
    for(int m=0;m<i-1;m++){
        index=SL[index].cur;
    }
    int k=SL[index].cur;
    SL[index].cur=SL[k].cur;
    Free_SL(SL,k);
    return 1;
}

int Locate_elem(SLinkList &SL, eletype e)
{
    //寻找第一个值为e的元素，返回其下标
    int i=SL[MAX_SIZE-1].cur;
    while(SL[i].data!=e&&i){
        i=SL[i].cur;
    }
    if(i==0){
        cout<<"No elem's value="<<e<<endl;
        return 0;
    }
    return i;
}



int main()
{
    SLinkList SL;
    Init_SL(SL);
    Insert_SL(SL,1,100);
    Insert_SL(SL,2,666);
    Insert_SL(SL,3,100);
    Delete_SL(SL,1);
    cout<<Locate_elem(SL,100)<<endl;
}