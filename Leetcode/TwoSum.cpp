#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

class solution
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {   
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if((nums[i]+nums[j])==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        } 
        return result;     
    }

};

int  main()
{
    solution s;
    vector<int> num={3,2,4};
    vector<int> num2;
    int k=6;
    num2=s.twoSum(num,k);
    for(auto x:num2)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}