/*检查由([{)]}组成的括号字符序列是否正确*/
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int test(stack<char> &mystack)
{
    char mylist[255];
    int flag=0;
    cout<<"Please input a string."<<endl;
    cin>>mylist;
    int len=strlen(mylist);
    for(int i=0;i<len;i++){
        if(mylist[i]=='['||mylist[i]=='('||mylist[i]=='{'){
            mystack.push(mylist[i]);
        }else{
            if(mystack.empty()){
                flag=1;
                break;
            }
            switch (mylist[i])
            {
            case ']':
            {
                if(mystack.top()=='[')
                mystack.pop();
                else flag=1;
                break;
            }
            case ')':
            {
                if(mystack.top()=='(')
                mystack.pop();
                else flag=1;
                break;
            }
            case '}':
            {
                if(mystack.top()=='{')
                mystack.pop();
                else flag=1;
                break;
            }
            default:
            {
                flag=1;
                break;
            }
            }
        }
    }
    if(flag){
        cout<<"Incorrect format! Please test:";
        cout<<mylist<<endl;
    }else{
        cout<<"Correct!"<<endl;
    }
    return 1;
}

int main()
{
    stack<char> mystack;
    test(mystack);
    return 0;
}