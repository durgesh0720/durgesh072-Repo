#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) 
{
    int i=0;
    int sizeN=needle.size();
    for(i=0;i<haystack.size();i++)
    {
        if(haystack[i]==needle[0])
        {
            int t=i,count=0;
            for(int j=0;j<needle.size();j++)
            {
                if(haystack[t]==needle[j])
                {
                    count++;
                    t++;
                }
                else
                    break;
            }
        if(count==sizeN)
            return i;
        }
    }
    return -1;
}
int strStr1(string haystack, string needle) 
{
        return haystack.find(needle);
}
int main()
{
    string s1="mississippi";
    string s2="issip";
    int s=strStr1(s1,s2);
    cout<<s;
    return 0;
}