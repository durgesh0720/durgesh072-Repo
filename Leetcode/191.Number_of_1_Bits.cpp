#include<iostream>
#include<stdio.h>
using namespace std;

int hammingWeight(int n) 
{
    int count=0;

    while(n)
    {
        if(n%2==1)
            count++;
        n=n/2;
    }
    return count;   
}
int main()
{
    cout<<hammingWeight(11);
    return 0;
}