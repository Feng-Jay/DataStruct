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

int Add_Ploy(PLinkList &La, PLinkList &Lb)
{
    PLinkList Lc;
    // Lc=new PLnode;
    PLinkList tempa,tempb,tempc;
    Lc=La;
    tempa=La; tempb=Lb; tempc=Lc;
    while(tempa->next!=nullptr&&tempb->next!=nullptr){
        tempa=tempa->next; tempb=tempb->next;
        if(tempa->exp<tempb->exp){
            tempc->next=tempa;
            tempc=tempa;
            tempa=tempa->next;
        }
        else if (tempa->exp>tempb->exp){
            PLinkList p =new PLnode;
            p=tempb->next;
            tempb->next=tempa;
            tempc->next=tempb;
            tempc=tempb;
            tempb=p;
        }
        else if(tempa->exp==tempb->exp){
            double y = tempa->coef+tempb->coef;
            if(y!=0.0){
                tempa->coef=y;
                tempc->next=tempa;
                tempc=tempa;
            }else {
                tempc->next=tempa->next;
                delete tempa;
            }
            PLinkList p=new PLnode;
            p=tempb;
            tempa=tempc->next;
            tempb=tempb->next;
            delete p;
        }
    }
    if(tempb->next!=nullptr){
        tempc->next=tempb;
    }
    return 1;
}

int main()
{
    PLinkList La,Lb;
    Init_List(La,5);
    Init_List(Lb,5);
    Add_Ploy(La,Lb);
    Print_List(La);
    return 0;
}