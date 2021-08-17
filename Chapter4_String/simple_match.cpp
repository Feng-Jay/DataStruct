#include<iostream>
#include<string>
using namespace std;

int matching (string a, string b)
{
    int i,j;
    // cout<<a<<endl;
    // cout<<a.length()<<endl;
    // cout<<b<<endl;
    // cout<<b.length()<<endl;
    i=j=0;
    while(i<=a.length()-1&&j<=b.length()-1){
        if(a[i]==b[j]){
            ++i;
            ++j;
        }else {
            i=i-j+1;
            j=0;
        }
    }
    if(j>=b.length()){
        return i-b.length();
    }else return -1;
}

int main()
{
    string mylist,sample;
    mylist="aaaabbcc";
    sample="aabbcc";
    int outcome =matching(mylist,sample);
    if(outcome!=-1){
        cout<<"the sample is from mylist's "<<outcome+1<<" position"<<endl;
    } else{
        cout<<"not matched!"<<endl;
    }
    return 0;
}