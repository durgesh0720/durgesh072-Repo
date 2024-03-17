#include<iostream>
#include<math.h>
using namespace std;

bool isPowerFour(int n)
{
    if(n>0)
    {
        if(n==1)
            return true;
        while(n%4==0)
            n/=4;
        if(n==1)
            return true;
    }
    return false;
}
bool isPowerFour1(int n)
{
    if(n<=0)
        return false;
    int x=(log(n))/(log(4));
    if(pow(4,x)==n)
        return true;
    return false;
}
bool isPowerFour2(int n)
{
    if(n<=0)
        return false;
    if((n&(n-1))==0 && (n-1)%3==0)
        return true;
    return false;
}
int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(isPowerFour2(num))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"Not";
    }
    return 0;
}