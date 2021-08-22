#include <iostream>

typedef int array[3];
typedef array array2[3]; 

using namespace std;

//数组一旦被定义，他的维数和维界就不再改变，因此除了结构的初始化和销毁之外，数组只有存取元素和修改元素值的操作
//采用顺序存储的数组有随机存储结构


int main()
{
    array2 list1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        cout<<list1[i][j]<<" ";
        cout<<endl;
    }
}