#include<iostream>
#include<string>
#include<array>
#include<cstring>
#include<algorithm>
using namespace std;

int maxDepth(string s) 
{
    array<int,5> arr;
    int k=0;
    while(k<5)
    { 
        arr[k]=0;
        k++;
    }
    k=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            arr[k]+=1;
        }
        if(s[i]==')'&& arr[k]>0)
            k++;
    } 
    for(int j=s.length()-1;j>0;j--)
    {
        if(s[j]==')')
            arr[k]+=1;
        if(s[j]=='(' && arr[k]>0)
            k++;
    }   
    return *max_element(arr.begin(),arr.end());
}

int main()
{
    cout<<maxDepth("1*((3+8-9)/(1/8-3)-4-5*(2-4+3)+4)+(4+3)*(1-3)");
    return 0;
}