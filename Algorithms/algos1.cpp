#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void example6()
{
    vector<int> v1={50,6,80,90,40,50,60,2,2,90,70,45};
    vector<int>::iterator it;
    it=find(v1.begin(),v1.end(),2);
    if(it==v1.end())
        cout<<"Value is not found!"<<endl;
    else
        cout<<"Value is found at index "<<it-v1.begin();
}

void example2()
{
    vector<int>v1={10,20,14,50,18,12};
    if(all_of(v1.begin(),v1.end(),[](int x)->bool {return (x%2)==0;}))
        cout<<"\nAll numbers are even";
    else
        cout<<"\nAll numbers are not even";
}
void example()
{
    vector <int> v1={10,50,6,80,90,40,50,60,2,2,90,70,45};
    int n=*adjacent_find(v1.begin(),v1.end());
    cout<<"Pair found with element value: "<<n; 
}
void example3()
{
    vector<int> v1={0,50,6,80,90,40,50,60,2,2,90,70,45};
    cout<<"\nMax_element:"<<*max_element(v1.begin(),v1.end());
    cout<<"\nMin_element:"<<*min_element(v1.begin(),v1.end());
}
void example4()
{
    vector<int>v1={10,50,6,80,90,40,50,60,21,25,90,70,45};
    for_each(v1.begin(),v1.end(),[](int x)-> void {cout<<endl<<x<<"- "<<x*x;});
}
void example5()
{
    vector<int>v1(10);
    generate(v1.begin(),v1.end(),[]()->int {static int i; ++i; return i*i;});
    for(auto x:v1)
        cout<<x<<" ";
}
int main()
{
    example6();
    cout<<endl;
    return 0;    
} 