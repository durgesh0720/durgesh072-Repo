#include<iostream>
#include<array>
#include<vector>
using namespace std;
typedef vector<vector<int>> ARRAY;
vector<int> getSumAbsoluteDifferences(vector<int>& nums)
{
    int sum=0;
    int length_nums=nums.size();
    vector<int>v1;
    int j=0,i=0;
    while(i<length_nums)
    {
        if(j<length_nums)
        {
            sum+=nums[j]-nums[i];
            j++;
        }
        else
        {
            v1.push_back(sum);
            sum=0;
            j=0;
            i++;
        }   
    }
    return v1;
}
vector<int> getSumAbsoluteDifferences1(vector<int>& nums)
{
    int length_nums = nums.size();
    vector<int> v1(length_nums, 0); // Initialize v1 with correct size

    // Calculate the sum of absolute differences for each element in nums
    int total_sum = 0;
    int right_sum = 0;

    for (int i = 0; i < length_nums; ++i) {
        right_sum += nums[i];
    }

    for (int i = 0; i < length_nums; ++i) {
        v1[i] = (i * nums[i] - right_sum) + ((length_nums - i - 1) * nums[i] + right_sum);
    }

    return v1;
}
int main()
{
    vector<int> v1={1,4,6,8,10};
    vector<int>v2;
    v2=getSumAbsoluteDifferences(v1);
    for(auto x:v2)
        cout<<x<<" ";
    
    return 0;
}