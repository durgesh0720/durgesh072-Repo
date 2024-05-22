#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
vector<string> findRelativeRanks(vector<int>& score) 
{
    vector<string> result;
    map<int,string> athletes;
    athletes[1]="Gold Medal";
    athletes[2]="Silver Medal";
    athletes[3]="Bronze Medal";
     
}

int main()
{
    vector<string> vs;
    vector<int> a{10,3,8,9,4}; //   10      3        8            9        4

    vs=findRelativeRanks(a);  //  "Gold"   5th      Bronze      silver    4th

    for(auto x: vs)
        cout<<x<<endl;
    return 0;
}