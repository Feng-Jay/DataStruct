#include <iostream>
#include <math.h>

using namespace std;

const int dimision=5;

/**************对称矩阵的压缩存储********************/
//书本上存储的是下三角矩阵，本次我们就有所改变，存储上三角
//但通过计算下标发现还是下三角矩阵计算方便，上三角的话需要知道矩阵的具体大小才能计算
//不推荐
int smartix[dimision][dimision]={1,2,3,4,5,
                                 2,2,0,8,6,
                                 3,0,3,9,7,
                                 4,8,9,4,8,
                                 5,6,7,8,5};

int zip[(dimision+1)*dimision/2]={1,2,3,4,5,2,0,8,6,3,9,7,4,8,5};

/**************三对角矩阵的压缩存储********************/
int tri[dimision][dimision]=     {1,2,0,0,0,
                                  2,3,4,0,0,
                                  0,5,6,7,0,
                                  0,0,9,0,1,
                                  0,0,0,2,3};

int zip_tri[3*dimision-1]={1,2,2,3,4,5,6,7,9,0,1,2,3,0};//额外+1个存储常量的空间

//tri[i][j]=zip_tri[2i+j]这是推导出来的
//对于zip_tri中的下标k处元素,假设对应tri中的tri[i][j]
//因为在tri[i][j]前共有：2+(i-1)*3+j-i+1=2i+j个元素
//即k=2i+j
//tri[i][j]=zip_tri[2i+j]

//另外可以推导出i、j与k的关系：i=(k+1)/3(向下取整) j=k-2i


int main()
{
    /**************对称矩阵的压缩存储验证********************/
    int test=1;
    cout<<"***************test1****************"<<endl;
    for(int i=0;i<dimision;i++){
        for(int j=0;j<dimision;j++){
            if(i<j&&smartix[i][j]!=zip[((2*dimision-i+1)*i)/2+j-i]){
                test=0;
                cout<<"ERROR: while i= "<<i<<" j= "<<j<<endl;
                return -1;
            }
            else if(i>=j&&smartix[i][j]!=zip[((2*dimision-j+1)*j)/2+i-j]){
                test=0;
                cout<<"ERROR: while i= "<<i<<" j= "<<j<<endl;
                return -1;
            }

        }
    }
    if(test){
        cout<<"congratulations! pass!"<<endl;
    }

    /**************三对角矩阵的压缩存储验证********************/
    int test2=1;
    cout<<"***************test2****************"<<endl;
    for(int i=0;i<dimision;i++){
        for(int j=0;j<dimision;j++){
            if(abs(j-i)>1){
                if(tri[i][j]!=zip_tri[3*dimision-2]){
                    test2=0;
                    cout<<"ERRO while: i= "<<i<<" j= "<<j<<endl;
                    return -1;
                }
            }
            else if(tri[i][j]!=zip_tri[2*i+j]){
                test2=0;
                cout<<"ERRO while: i= "<<i<<" j= "<<j<<endl;
                return -1;
            }
        }
    }

    if(test2){
        cout<<"congratulations! pass!"<<endl;
    }

}