#include<iostream>
#include<vector>
using namespace std;

int minFallingPathSum(vector<vector<int>>& grid) 
{
    int i=0,j=0,k=0;
    if(grid[i].size()==1)
        return grid[i][i];

    for(i=0; i<grid[i].size(); i++)
    {
        if(i!=j)
        {
            for(j=0;j<grid[i].size();j++)
            {
                if(j!=k)
                {
                    for(k=0;k<grid[i].size();k++)
                    {
                        cout<<grid[i][i]<<grid[j][j]<<grid[k][k]<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> v1;
    v1={{1,2,3},{4,5,6},{7,8,9}};
    minFallingPathSum(v1);
    return 0;
}
// https://leetcode.com/problems/number-of-1-bits/submissions/1242162082?envType=daily-question&envId=2024-04-26