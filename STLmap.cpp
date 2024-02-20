#include<iostream>
#include<map>
#include<set>
#include<string>
#include<utility>
using namespace std;
int main()
{
    multiset<int> s1={10,20,30,20,10,30,10,20};
    for(auto x: s1)
        cout<<x<<" ";
}
int f2()
{
    map<int,string> m1={{1,"Bhopal"},{2,"Indore"},{3,"Pune"}};
    map<int,string>::iterator it;
    pair <int,string> p1={1,"Patana"};
    for(it=m1.begin();it!=m1.end();it++)
        cout<<"Key: "<<it->first<<"\nValue: "<<it->second<<endl;
    cout<<endl;
    m1.insert(p1);
    for(it=m1.begin();it!=m1.end();it++)
        cout<<"Key: "<<it->first<<"\nValue: "<<it->second<<endl;
    cout<<endl;
    return 0;
}