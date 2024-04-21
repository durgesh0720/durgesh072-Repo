#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// int ASCII(char ch)
// {
//     return int(ch);
// }
bool isVowel(char k)
{
   return k=='A'|| k=='a' || k=='E' || k=='e' || k=='I'||k=='i'||k=='O'||k=='o'||k=='U'||k=='u';
}
// string sortVowels(string s) 
// {
//     string vowels="AEIOUaeiou";
//     for(int i=0;i<s.length();i++)
//     {
//         if(isVowel(s[i]))
//         {
//             for(int j=i+1;j<s.length();j++)
//             {
//                 if(isVowel(s[j]))
//                     if(int(s[i])>int(s[j]))
//                     {    
//                         char temp=s[i];
//                         s[i]=s[j];
//                         s[j]=temp;
//                     }
//             }
//         }
//     }
//     return s;
// }
string sortVowels(string s) 
{
    string temp;
    for(char &ch : s)
    {
        if(isVowel(ch))
        {
            temp.push_back(ch);
        }
    }
    sort(begin(temp),end(temp)); 
    int j=0;
    for(int i=0;i<s.length();i++)
    {
        if(isVowel(s[i]))
        {
            s[i]=temp[j];
            j++;
        }
    }
    return s;
}
int main()
{
    string s="Ram is going to home";
    cout<<sortVowels(s);
    return 0;
}