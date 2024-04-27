#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void countCharacters(vector<string>& words, string chars) 
{
    for(int i=0;i<chars.length();i++)
    {
        string s=words[i];
        for(int j=0;j<s.length();j++)
        {
            if(chars[i]==s[j])
                
        }
    }
}
int main()
{
    vector<string> s1={"cat","ct","cct","azb"};
    string s2="ccat";

    countCharacters(s1,s2);
    return 0;
}   