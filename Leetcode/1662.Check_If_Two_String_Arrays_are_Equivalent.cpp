#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
{
    string temp1,temp2;
    vector<string>::iterator it;
    for(it=word1.begin();it!=word1.end();it++)
        temp1+=*it;
    for(it=word2.begin();it!=word2.end();it++)
        temp2+=*it;
    return temp1==temp2;
}

int main()
{
    vector<string> w1{"a","bc"};
    vector<string> w2{"ab","c"};
    cout<<arrayStringsAreEqual(w1,w2);
    return 0;
}