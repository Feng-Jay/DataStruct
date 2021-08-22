#include <iostream>

using namespace std;

typedef int elemtype;

const int MAX=10000;
//稀疏矩阵没有特殊的定义，定义稀疏系数=t/(m*n)，(t为不为0元素个数)通常在其<=0.05时认为是稀疏矩阵
//存储其非零元素的值+其坐标，即一个三元组
//稀疏矩阵<==>非零三元组+矩阵行列数

struct triple{
    int i;
    int j;
    elemtype e;
};

struct martix{
    triple data[MAX];//数组可以表示为三元组集合+矩阵规格，另外加上非零元素数便于操作
    int m,n,t;
};

void init(martix &a);
void print_m(martix a);

int transfer_1(martix &a, martix &outcome)
{
    //时间复杂度为O(n*t)，而当t与m*n接近同数量级时时间复杂度->O(m*n^2)
    //所以适用于t<<m*n的情况
    outcome.m=a.m;
    outcome.n=a.n;
    outcome.t=a.t;
    int count=0;
    for(int i=0;i<a.n;i++){
        for(int j=0;j<a.t;j++){
            if(a.data[j].j==i){
                outcome.data[count].i=a.data[j].j;
                outcome.data[count].j=a.data[j].i;
                outcome.data[count].e=a.data[j].e;
                count++;
            }
        }
    }
    return 1;
}

int transfer_2(martix &a, martix &outcome)
{
    //时间复杂度为O(n+t),在t->m*n的情况下，时间复杂度为O(m*n)与经典算法相同
    int num[a.n];
    int cpot[a.n];
    outcome.m=a.m; outcome.n=a.n; outcome.t=a.t;

    for(int i=0;i<a.n;i++) num[i]=0;

    for(int i=0;i<a.t;i++) num[a.data[i].j]++;

    cpot[0]=0;
    for(int i=1;i<a.n;i++) cpot[i]=cpot[i-1]+num[i-1];

    for(int m=0;m<a.t;m++){
        int temp1=a.data[m].j;
        int temp2=cpot[temp1];
        outcome.data[temp2].i=a.data[m].j;
        outcome.data[temp2].j=a.data[m].i;
        outcome.data[temp2].e=a.data[m].e;
        cpot[temp1]++;
    }
    return 1;
}

int main()
{
    martix a,outcome1,outcome2;
    init(a);
    cout<<a.t<<endl;
    transfer_1(a,outcome1);
    transfer_2(a,outcome2);
    print_m(a);
    cout<<"*******transfer_1********"<<endl;
    print_m(outcome1);
    cout<<"*******transfer_1********"<<endl;
    print_m(outcome2);
}
void print_m(martix a){
    for(int m=0;m<a.t;m++){
        cout<<a.data[m].i<<" "<<a.data[m].j<<" "<<a.data[m].e<<endl;
    }
}

void init(martix &a)
{
    a.m=6; a.n=7;
    a.t=8;
    a.data[0].i=1; a.data[0].j=2; a.data[0].e=12;
    a.data[1].i=1; a.data[1].j=3; a.data[1].e=9;
    a.data[2].i=3; a.data[2].j=1; a.data[2].e=-3;
    a.data[3].i=3; a.data[3].j=6; a.data[3].e=14;
    a.data[4].i=4; a.data[4].j=3; a.data[4].e=24;
    a.data[5].i=5; a.data[5].j=2; a.data[5].e=18;
    a.data[6].i=6; a.data[6].j=1; a.data[6].e=15;
    a.data[7].i=6; a.data[7].j=4; a.data[7].e=-7;
}
