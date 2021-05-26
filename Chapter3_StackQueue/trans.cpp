/*学习C++的stack库的使用！*/
/*本节进行数制转换！*/
#include <iostream>
#include <stack>
using namespace std;

int trans(stack<int> &mystack,int n,int tar)
{
    /*将十进制数n转换为tar进制数字*/
    while(n){
        mystack.push(n%tar);
        n=n/tar;
    }
    while(!mystack.empty()){
        int e=mystack.top();
        mystack.pop();
        cout<<e;
    }
    cout<<endl;
    return 1;
}

int main()
{
    stack<int> mystack;
    trans(mystack,4,2);
    return 0;
}