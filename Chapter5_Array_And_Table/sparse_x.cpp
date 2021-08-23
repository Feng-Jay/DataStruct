#include <iostream>
#include <string.h>

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
    int num[Max_Row];
    int rpos[Max_Row];
};

void init(Rlmartix &a,Rlmartix &b);
void print_m(Rlmartix a);

int multi_row(Rlmartix &a, Rlmartix &b, Rlmartix &c)
{
    int clo=b.n;
    int sum[clo];
    if(a.n!=b.m){
        cout<<"The multi is illegal!"<<endl;
        return -1;
    }
    c.m=a.m;c.n=b.n;c.t=0;
    int c_clo;
    int next_a,next_b;
    if(a.t*b.t){
        for(int arow=0;arow<a.m;arow++){
            memset(sum,0,sizeof(sum));
            c.rpos[arow]=c.t;
            if(arow<a.m-1) next_a=a.rpos[arow+1];
            else next_a=a.t;
            for(int p=a.rpos[arow];p<next_a;p++){
                int brow=a.data[p].j;
                if(brow<b.m-1) next_b=b.rpos[brow+1];
                else next_b=b.t;
                for(int q=b.rpos[brow];q<next_b;q++){
                    c_clo=b.data[q].j;
                    sum[c_clo]+=a.data[p].e*b.data[q].e;
                }
            }
            for(int i=0;i<c.n;i++){
                if(sum[i]){
                    if(c.t>=MAX){
                        cout<<"ERROR: out of c's range!"<<endl;
                        return -1;
                    }
                    c.data[c.t].e=sum[i];
                    c.data[c.t].i=arow;
                    c.data[c.t].j=i;
                    c.t++;
                }
            }
        }
    }
    return 0;
}

int main()
{
    Rlmartix a,b;
    Rlmartix outcome;
    init(a,b);
    cout<<"Here is martix a "<<endl;
    print_m(a);
    cout<<"Here is martix b "<<endl;
    print_m(b);
    multi_row(a,b,outcome);
    cout<<"Here is outcome "<<endl;
    print_m(outcome);
    return 0;
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
    memset(a.data,0,sizeof(a.data));
    memset(b.data,0,sizeof(b.data));
    a.data[0].i=0; a.data[0].j=0; a.data[0].e=3;
    a.data[1].i=0; a.data[1].j=3; a.data[1].e=5;
    a.data[2].i=1; a.data[2].j=1; a.data[2].e=-1;
    a.data[3].i=2; a.data[3].j=0; a.data[3].e=2;
    for(int i=0;i<a.m;i++) {a.num[i]=0;a.rpos[i]=0;}

    for(int i=0;i<a.t;i++){
        a.num[a.data[i].i]++;
    }
    a.rpos[0]=0;
    for(int i=1;i<a.m;i++){
        a.rpos[i]+=a.rpos[i-1]+a.num[i-1];
    }
    for(int i=0;i<a.m;i++){
        cout<<a.rpos[i]<<" ";
    }
    cout<<endl;
    b.m=4;b.n=2;
    b.t=4;
    b.data[0].i=0; b.data[0].j=1; b.data[0].e=2;
    b.data[1].i=1; b.data[1].j=0; b.data[1].e=1;
    b.data[2].i=2; b.data[2].j=0; b.data[2].e=-2;
    b.data[3].i=2; b.data[3].j=1; b.data[3].e=4;
    for(int i=0;i<b.m;i++) {b.num[i]=0;b.rpos[i]=0;}
    
    for(int i=0;i<b.t;i++){
        b.num[b.data[i].i]++;
    }
    b.rpos[0]=0;
    for(int i=1;i<b.m;i++){
        b.rpos[i]+=b.rpos[i-1]+b.num[i-1];
    }
    for(int i=0;i<b.m;i++){
        cout<<b.rpos[i]<<" ";
    }
}