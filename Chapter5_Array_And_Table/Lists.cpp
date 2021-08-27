#include <iostream>

using namespace std;

//广义表一般记作 LS=(α1,α2,...,αn), αi可以是单个元素也可以是广义表(称为LS的原子与子表)
//LS非空时，称α1为表头，其余元素组成的表(α2,...,αn)为LS的表尾
//对非空LS，其表头可能为原子/列表，而其表尾一定为列表
typedef int Atomtype;

enum ElemTag {ATOM, LIST};

struct Glnode{
    ElemTag tag;
    union{
        Atomtype atom;
        struct ptr {
            Glnode *hp, *tp;
        };
    };
};
//3个特点: 1.除空表的表头指针为空表，其他非空表头指针都指向一个表结点，结点中hp指向表头(元素/表结点)，tp指向表尾(除非空)
//         2.易分清列表中原子与子表所在层次
//         3.最高层表结点的个数即为表的长度
struct Mpnode{
    ElemTag tah;
    int exp;
    union{
        double coef;
        Mpnode *hp;
    };
    Mpnode* tp;
};
//可用该数据结构表示m元多项式
//因为任何一个多元多项式都可以递归地划分为不同变元的多项式: 先解析处出一个主变元、再递归地分解出第二个变元...
//因此广义表的深度即为变元个数

/*求广义表深度*/
// 基本项: DEPTH(LS)=1 , 当LS为空表
// 基本项: DEPTH(LS)=0 , 当LS为原子
// 归纳项: DEPTH(LS)=1+MAX{DEPTH(αi)} n>=1
// 实质上是一个遍历广义表的过程

/*复制广义表*/
// 任何一个非空广义表均可分解为表头和表尾<==>一对确定的表头和表尾可唯一确定一个广义表
// 所以复制只需要分别复制其表头与表尾，然后合成即可。


int main()
{
    return 0;
}