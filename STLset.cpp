#include<iostream>
#include<set>
#include<string>
using namespace std;
class Employee
{
    private:
        int empid;
        string name;
        double salary;
    public:
        Employee(int id,string n,double s):empid(id),name(n),salary(s)
        {   }
        void showData()
        {
            cout<<"\nID: "<<empid<<"\nName: "<<name<<"\nSalary: "<<salary<<endl;
        }
        int getEmpid()
        {
            return empid;
        }
        string getName()
        {
            return name;
        }
        double getSalary()
        {
            return salary;
        }
};
class CompareBySalary
{
    public:
        bool operator()(Employee e1,Employee e2) const
        {
            return e1.getSalary()<e2.getSalary();
        }
};
int main()
{
    set<Employee,CompareBySalary> s1;
    s1={Employee(1011,"Alex",15200)};
    s1.insert(*new Employee(1012,"Javanigher",60000));
    s1.insert(*new Employee(1013,"Nikhil",50000));
    s1.insert(*new Employee(1016,"Raju",65000));
    s1.insert(*new Employee(1015,"Cutie",15000));
    s1.insert(*new Employee(1014,"Suraj",10000));
    for(auto x: s1)
        x.showData();
    return 0;
}
int f1()
{
    set<int> s1{10,20,30,40,70,60};
    set<int>::iterator it;
    for(auto x:s1)
        cout<<x<<" ";
    cout<<endl;
    for(it=s1.begin();it!=s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<s1.size();
    cout<<endl;
    s1.erase(s1.begin());
     for(it=s1.begin();it!=s1.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}