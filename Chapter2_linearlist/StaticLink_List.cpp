/*实现静态链表*/
/*便于在没有指针的高级语言中使用链表结构
数组元素中有两个分量：一个分量代表一个结点数据，同时另一个游标分量代替指针指示结点在数组中的相对位置
数组的第0分量看作头结点*/

/*在插入、删除元素时不需要像顺序线性表一样移动大量元素，只需要修改游标cur*/

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

int Init_SL(SLinkList &SL)
{
    for(int i=0;i<MAX_SIZE-1;i++){
        SL[i].cur=i+1;
    }
    SL[MAX_SIZE-1].cur=0;
    return 1;
}

int main()
{

}