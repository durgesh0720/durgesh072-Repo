#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string largestOddNumber(string num)
{
    for(int i=num.length()-1;i>=0;i--)
    {
       if(int(num[i])%2!=0)
            return num;
        num.pop_back();
    }
}
int main()
{
    cout<<largestOddNumber("486379402");
    return 0;
}