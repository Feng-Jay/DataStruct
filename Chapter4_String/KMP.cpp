#include <iostream>
#include <string>

using namespace std;

void get_next(string sample, int * next)
{
    next[0]=0;
    int i,j;
    i=0;
    j=next[0];//用i作next数组索引，j表示sample中目前已知next值的最靠后下标
    while (i<sample.length()-1){
        if(j==0){
            i++;
            j++;
            next[i]=1;//也就是1.即对应第一种情况：求next[0]
        }
        else
        if(sample[i]==sample[j]){
            ++i;
            ++j;
            next[i]=j;//j+1，对应了pk=pj,那么next[j+1]=next[j]+1
        }
        else j=next[j];//对应pk!=pj,那么就一层层地向下去走，知道找到pj与某个匹配，或不存在匹配
    }
}

int main()
{
    string sample="abaabcac";
    string domain="acabaabaabcacaabc";
    int * next = new int [sample.length()];
    get_next(sample,next); 
    for(int i=0;i<sample.length();i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
}
