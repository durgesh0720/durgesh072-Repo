#include<iostream>
#include<cstring>
using namespace std;

// int tribonacci1(int n) 
// {
//     int arr[n];
//     arr[0]=0;
//     arr[1]=1;
//     arr[2]=1;
//     if(n==0||n==1||n==2)
//         return arr[n];
//     else
//     {
//         for(int i=3;i<=n;i++)
//         {
//             arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
//         }
//     }
//    return arr[n];
// }
// int tribonacci(int n)
// {
//     if(n==0)
//         return n;
//     if(n==1||n==2)
//         return 1;
//     return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
// }


int fiboArr(int n)
{
    int ptr[n+1];
    ptr[0]=0;
    ptr[1]=1;
    ptr[2]=1;
    if(n>2)
    {
        for(int i=3;i<=n;i++)
            ptr[i]=ptr[i-1]+ptr[i-2]+ptr[i-3];
    }
    return ptr[n];
}

int t[38];
int find(const int& n)
{
    if(n==0)
        return 0;
    if(n==1||n==2)
        return 1;
    if(t[n]!=-1)
        return t[n];
    
    int a=find(n-1);
    int b=find(n-2);
    int c=find(n-3);

    return t[n]=a+b+c;
}
int tribonacci(int n)
{
    memset(t,-1,sizeof(t));
    return find(n);
}
int main()
{
    for(int i=0;i<=35;i++)
        cout<<i<<": "<<tribonacci(i)<<endl;
    return 0;
}