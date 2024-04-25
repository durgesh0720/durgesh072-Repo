#include<iostream>
#include<string>
using namespace std;

string largestGoodInteger(string num) 
{
    char ch;
    string s="\0";
    if(num.size()>2)
    {
        for(int i=2;i<num.size();i++)
        {
            if((num[i]==num[i-1])&&(num[i]==num[i-2]))
            {
                if(ch<num[i])
                    ch=num[i];
            }
        }
    }
    if(ch!='\0')
        s=string(3,ch);
    return s;
}

int main()
{
    cout<<largestGoodInteger("42352338");
    return 0;
}