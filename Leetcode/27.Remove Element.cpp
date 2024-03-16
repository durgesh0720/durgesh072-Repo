#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums,int val) 
{
        vector<int>::iterator it;
        it=nums.begin();
        while(it!=nums.end())
        {
            if(val!=*it)
            {
                it++;
            }
            else
            {
                it=nums.erase(it);
            }
        }
        return nums.size();
}
int main()
{
    vector<int> v1={0,2,11,2,2,5,3,55,111,1,1,1,1,2};
    removeElement(v1,1);
    for(int x:v1)
    {
        cout<<x<<" ";
    }
    return 0;
}