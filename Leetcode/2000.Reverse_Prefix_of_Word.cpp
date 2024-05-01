#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string reversePrefix(string word, char ch) 
{
    string::iterator st,st1;
    int count=0;
    st1=word.begin();
    for(st=word.begin();st!=word.end();st++)
        if(*st==ch)
            break;
        else
            count++;
    if(count==word.length())
        return word;
    reverse(st1,st+1);
    return word;
}
int main()
{
    string k=reversePrefix("abcdefd",'d');
    for(auto x:k)
        cout<<x;
    return 0;
}