#include <iostream>

using namespace std;

typedef int elemtype;

const int INIT_SIZE=100;
const int INCREMENT=10;

typedef struct{
    elemtype *base;
    elemtype *top;
    int size;
}Stack;

int Init_Stack(Stack &s)
{
    try{
        s.base=new int[INIT_SIZE];
    }catch(const bad_alloc&e){
        cout<<"Base alloc failed!"<<endl;
        return -1;
    }
    s.top=s.base;
    s.size=INIT_SIZE;
    return 1;
}

int Get_Top(Stack s, elemtype &e)
{
    if(s.top==s.base){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    e=*(s.top-1);
    return e;
}

int Push(Stack &s, elemtype e)
{
    if(s.top-s.base>=s.size){
        try{
            elemtype* temp=new int[INIT_SIZE+INCREMENT];
            copy(s.base,s.base+s.size,temp);
        }catch(const bad_alloc&e){
            cout<<"Base alloc failed!"<<endl;
            return -1;
        }
        s.top=s.base+s.size;
        s.size+=INCREMENT;
    }
    *(s.top++)=e;
    return 1;
}

int Pop(Stack &s, elemtype &e)
{
    if(s.top==s.base){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    e=*(s.top-1);
    s.top--;
    return e;
}

int main()
{
    Stack s;
    elemtype e;
    Init_Stack(s);
    Push(s,666);
    Push(s,957);
    Push(s,987);
    cout<<Get_Top(s,e)<<endl;
    Pop(s,e);
    cout<<Get_Top(s,e)<<endl;
    return 0;
}