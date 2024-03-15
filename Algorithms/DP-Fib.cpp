#include<iostream>
using namespace std;

int fib(int num, int* ptr) 
{
    if(ptr[num] != -1)
        return ptr[num];
    if(num==0 || num==1)
        ptr[num]=num;
    else
        ptr[num] = fib(num - 1, ptr) + fib(num - 2, ptr);
    cout<<ptr[num]<<" ";
    return ptr[num];
}
int* fiboArr(int n)
{
    int *ptr=new int[n+1];
    ptr[0]=0;
    ptr[1]=1;
    for(int i=2;i<=n;i++)
        ptr[i]=ptr[i-1]+ptr[i-2];
    return ptr;
}
int main() 
{
    // int* ptr = new int[20];
    // for(int i = 0; i < 20; i++)
    //     ptr[i] = -1;

    // cout <<endl<<"Fib is: "<<fib(6, ptr);
    // delete[] ptr; // Free allocated memory

    int* k;
    k=fiboArr(10);
    cout<<"fib series: ";
    for(int i=0;i<=10;i++)
        cout<<k[i]<<" ";
    return 0;
}
