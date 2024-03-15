#include<iostream>
#include<vector>
using namespace std;

int removeDublicates(vector<int>& nums)
{
    vector<int>::iterator it1,it2;
    if(!nums.empty())
    {
        for(it1=nums.begin();it1!=nums.end();it1++)
        {
            for(it2=it1+1;it2!=nums.end();it2++)
            {
                if(*it1==*it2)
                {
                    nums.erase(it2);
                }
            }
        }
    }
    return nums.size();
}

int main()
{
    vector<int>v1={1,1,1,2,2,3,3,4,4,5,5,5};
    int size=removeDublicates(v1);

    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++)
    {
        cout<<" "<<*it;
    }
    return 0;
}