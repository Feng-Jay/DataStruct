#include <iostream>

using namespace std;

typedef int elemtype;
const int MAX=10000;
const int Max_Row=1000;

struct Triple{
    int i;
    int j;
    elemtype e;
};

struct Rlmartix{
    Triple data[MAX];
    int m,n,t;
    int rpos[Max_Row];
};

void init(Rlmartix &a,Rlmartix &b);
void print_m(Rlmartix a);

int multi_row(Rlmartix &a, Rlmartix &b, Rlmartix &c)
{
    if(a.n!=b.m){
        cout<<"The multi is illegal!"<<endl;
        return -1;
    }
    c.m=a.m;c.n=b.n;c.t=0;
    if(a.t*b.t){
        
    }
    return 0;
}

int main()
{

}
void print_m(Rlmartix a){
    for(int m=0;m<a.t;m++){
        cout<<a.data[m].i<<" "<<a.data[m].j<<" "<<a.data[m].e<<endl;
    }
}

void init(Rlmartix &a,Rlmartix &b)
{
    a.m=3; a.n=4;
    a.t=4;
    a.data[0].i=1; a.data[0].j=1; a.data[0].e=3;
    a.data[1].i=1; a.data[1].j=4; a.data[1].e=5;
    a.data[2].i=2; a.data[2].j=2; a.data[2].e=-1;
    a.data[3].i=3; a.data[3].j=1; a.data[3].e=2;
    for(int i=0;i<a.t;i++){
        a.rpos[a.data[i].i]++;
    }
    b.m=4;b.n=2;
    b.t=4;
    b.data[0].i=1; b.data[0].j=2; b.data[0].e=2;
    b.data[1].i=2; b.data[1].j=1; b.data[1].e=1;
    b.data[2].i=3; b.data[2].j=1; b.data[2].e=-2;
    b.data[3].i=3; b.data[3].j=2; b.data[3].e=4;
    for(int i=0;i<b.t;i++){
        b.rpos[b.data[i].i]++;
    }
}