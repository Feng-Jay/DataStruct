#include <iostream>

using namespace std;

typedef int elemtype;

struct Clnode{
    int i,j;
    elemtype e;
    Clnode* down,*right;
};

struct Crosslist{
    Clnode **rhead, **chead;
    int m,n,t;
};

int create_crossll(Crosslist& list)
{
    cout<<"Please input Martix's row/column/non_zero_number"<<endl;
    cin>>list.m>>list.n>>list.t;
    int i,j,e;
    list.rhead=new Clnode*[list.m];
    list.chead=new Clnode*[list.n];
    for(int i=0;i<list.m;i++) {list.rhead[i]=new Clnode[list.m];list.rhead[i]->down=new Clnode;list.rhead[i]->right=new Clnode;}
    for(int i=0;i<list.n;i++) {list.chead[i]=new Clnode[list.n];list.chead[i]->down=new Clnode;list.chead[i]->right=new Clnode;}
    //注意这部分的内存分配是一个重点

    for(int i=0;i<list.m;i++) {list.rhead[i]->down=nullptr;list.rhead[i]->right=nullptr;list.rhead[i]=nullptr;}
    for(int i=0;i<list.n;i++) {list.chead[i]->down=nullptr;list.chead[i]->right=nullptr;list.chead[i]=nullptr;}

    cout<<"Please input non-zero elem's row/column/value"<<endl;
    for(int m=0;m<list.t;m++){
        Clnode* temp=new Clnode;
        Clnode* p=new Clnode;
        cin>>temp->i>>temp->j>>temp->e;
        i=temp->i; j=temp->j; e=temp->e;
        if(list.rhead[i]==nullptr||list.rhead[i]->j>temp->j){
            temp->right=list.rhead[i];
            list.rhead[i]=temp;
        }else{
            for(p=list.rhead[i];(p->right!=nullptr&&p->right->j<temp->j);p=p->right);
            temp->right=p->right;
            p->right=temp;
        }

        if(list.chead[j]==nullptr||list.chead[j]->i>temp->i){
            temp->down=list.chead[j];
            list.chead[j]=temp;
        }else{
            for(p=list.chead[j];(p->down!=nullptr&&p->down->i<temp->i);p=p->down);
            temp->down=p->down;
            p->down=temp;
        }
    }

    return 0;
}
void print_cll(Crosslist M);

int main()
{
    Crosslist M;
    create_crossll(M);
    print_cll(M);
    return 0;
}

void print_cll(Crosslist M)
{
    Clnode *temp=new Clnode;
    temp->right=new Clnode; temp->right=new Clnode;
    for(int i=0;i<M.m;i++){
        temp=M.rhead[i];
        while(temp!=nullptr){
            cout<<"|_"<<temp->i<<" "<<temp->j<<" "<<temp->e<<"_| ";
            temp=temp->right;
        }
        cout<<endl;
    }
    delete temp;
}