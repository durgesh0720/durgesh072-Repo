#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string s1,s2;
        char arr[strs[0].length()];
        vector<string>::iterator it,it1;
        it1=strs.begin();
        s1=*it1;

        for (it = it1 + 1; it != strs.end(); it++) 
        {
            s2 = *it;
            for (int i = 0; i < s1.length() && i < s2.length(); i++) {
                if (s1[i] != s2[i]) 
                {
                    arr[i]=s1[i];
                }
        }
    }
        return arr;
    }       
};