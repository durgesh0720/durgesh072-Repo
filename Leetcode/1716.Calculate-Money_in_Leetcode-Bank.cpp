#include<iostream>
#include<cstring>
using namespace std;
int totalMoney(int n)
{
    int total=0;
    int nums[n+1];
    memset(nums,0,sizeof(nums));
for (int i = 0; i <= n; i++)
    {
        int weekMoney;
        if(i % 7 == 0) 
             weekMoney=7 + (i / 7 - 1);
        else
            weekMoney=i % 7;

        total +=weekMoney;
    }
    return total;
}
int main()
{
    cout<<totalMoney(10);
}

// (1 + 2 + 3 + 4 + 5 + 6 + 7) +   (2 + 3 + 4 + 5 + 6 + 7 + 8) +    (3 + 4 + 5 + 6 + 7 + 8 + 9)
//  0   1   2   3   4   5   6       7   8   9   10  11  12  13      14  15  16  17  18  19  20
//  1   3   6   10  15  21  28      30  33  37  42  48  55  63      66  70  75  81  88  96  105
//                  7                       7                              7
