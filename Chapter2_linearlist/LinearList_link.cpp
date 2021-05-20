#include <iostream>

using namespace std;

typedef int eleytpe;

typedef struct LNode{
    eleytpe data;
    struct LNode* next;//结构体自引用只能引用指针，若引用结构体，就会套娃，内存会用光。
}LNode, *LinkList; 
//
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