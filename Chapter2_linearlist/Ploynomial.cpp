#include <iostream>

using namespace std;


typedef struct PLnode{
    double coef;
    int exp;
    struct PLnode *next;
}PLnode, *PLinkList;

int Init_List(PLinkList &L, int n)
{
    cout<<"Please Input "<<n<<" coefs and exps"<<endl;
    L=new PLnode;
    L->coef=n;
    PLinkList temp;
    PLinkList temp2=L;//指针的赋值为地址的赋值，即将一个指针指向的地址给另一个指针
    for(int i=0;i<n;i++){
        temp=new PLnode;
        temp->next=nullptr;
        cin>>temp->coef>>temp->exp;
        temp2->next=temp;
        temp2=temp;
    }
    return 1;
}

int Print_List(PLinkList L)
{
    PLinkList temp=L;
    while(temp->next!=nullptr){
        temp=temp->next;
        cout<<temp->coef<<"X^"<<temp->exp;
        if(temp->next!=nullptr)
        cout<<"+";
       // temp=temp->next;
    }
    return 1;
}

int main()
{
    PLinkList L;
    Init_List(L,5);
    Print_List(L);
    return 0;
}