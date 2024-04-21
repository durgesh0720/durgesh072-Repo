#include<iostream>
#include<string>
using namespace std;
int main()
{
   int num=15245,t1=1,t;
   while(num)
   {
    t=num%10;
    if(t>=t1)
    {
        t1=t;
    }
    num=num/10;
   }
   printf("%d",t1);
}