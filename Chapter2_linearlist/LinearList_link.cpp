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


int main()
{
    return 0;
}