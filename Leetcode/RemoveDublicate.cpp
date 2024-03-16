#include<iostream>
#include<vector>
using namespace std;

int removeDublicates(vector<int>& nums)
{
    vector<int>::iterator it;
    int temp=nums[0];
    it=nums.begin()+1;
    while(it!=nums.end())
    {
        if(*it!=temp)
        {
            temp=*it;
            it++;
        }
        else
            it=nums.erase(it);
    }
    return nums.size();
}

int main()
{
    vector<int>v1={1,1,1,2,2,2,3,3,4,4,5,5,5};
    int size=removeDublicates(v1);

    for(auto x:v1)
    {
        cout<<x<<" ";
    }
    return 0;
}