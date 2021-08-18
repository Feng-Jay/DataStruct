#include <iostream>
#include <string>

using namespace std;

void get_next(string sample, int * next)
{
    next[0]=-1;
    int i,j;
    i=0; j=-1;//用i作next数组索引，j表示sample中目前已知next值的最靠后下标
    while (i<sample.length()){
        if(j==-1){
            i++;
            j++;
            next[i]=j;//对应j找到0第一个元素仍然没有找到对应的字符
        }
        else 
        if(sample[i]==sample[j]){
            i++;
            j++;
            next[i]=j;//j+1，对应了pk=pj,那么next[j+1]=next[j]+1 
        }
        else j=next[j];//对应pk!=pj,那么就一层层地向下去走，知道找到pj与某个匹配，或不存在匹配
    }
}

int KMP (string domain, string sample, int* next)
{
    int index1=0;
    int index2=0;
    int l1=domain.length();
    int l2=sample.length();//
    while(index1<l1&&index2<l2){
        if(index2==-1||domain[index1]==sample[index2]){
            index1++;
            index2++;
        }
        else {
            index2=next[index2];
        }
    }

    if(index2>=sample.length()){
        cout <<index1<<" "<<index2<<endl;
        return index1-sample.length();
    }
    else {
        return -1;
    }
}

int KMP (string domain, string sample, int* next, int pos)
{
    int index1=pos-1;
    int index2=0;
    int l1=domain.length();
    int l2=sample.length();//
    while(index1<l1&&index2<l2){
        if(index2==-1||domain[index1]==sample[index2]){
            index1++;
            index2++;
        }
        else {
            index2=next[index2];
        }
    }

    if(index2>=sample.length()){
        cout <<index1<<" "<<index2<<endl;
        return index1-sample.length();
    }
    else {
        return -1;
    }
}

int main()
{
    string sample="abaabcac";
    string domain="acabaabaabcacaabc";
    int * next = new int [sample.length()];
    get_next(sample,next);
    cout<<"sample's next is : "; 
    for(int i=0;i<sample.length();i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;

    int ans=KMP(domain,sample,next,1);
    if(ans!=-1)
    cout<<"the sample appears from the "<<ans+1<<" pos of domain"<<endl;
    else cout<<"no such sample in domain string!"<<endl;
    return 0;
}
