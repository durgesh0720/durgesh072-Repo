#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int vertex;
    node* next;
};
class AdjList
{
    private:
        node* start;
    public:
        AdjList();
        void AddNode(int);
        void showAdjList();
        int size();
        int* get();
};
int AdjList :: size()
{
    int i=0;
    node* t=start;
    while(t)
    {
        i++;
        t=t->next;
    }
    return i;
}
int* AdjList :: get()
{
    int *temp=new int[size()];
    int i=0;
    node* t=start;
    while(t)
    {
        temp[i]=t->vertex;
        i++;
        t=t->next;
    }
    return temp;
}
void AdjList :: showAdjList()
{
    node* t=start;
    while(t)
    {
        cout<<t->vertex<<" ";
        cout<<endl;
        t=t->next;
    }
}
void AdjList :: AddNode(int vno)
{
    node* n= new node;
    node* t;
    n->next=NULL;
    n->vertex=vno;
    if(start==NULL)
        start=n;
    else
    {
        t=start;
        while(t->next)
            t=t->next;
        t->next=n;
    }
}
AdjList :: AdjList()
{
    start=NULL;
}

class graph
{
    private:
        int v_count;
        AdjList *arr;
    public:
        graph();
        void createGraph(int);
        void showGraph();
        void roadmap(int,int);
};
void graph :: roadmap(int source,int destination)
{
    
}
void graph :: showGraph()
{
    for(int i=0;i<v_count;i++)
    {
        cout<<"Vertex v"<<i<<": ";
        arr[i].showAdjList();
    }
}
void graph :: createGraph(int vno)
{
    int eno,n;
    v_count=vno;
    arr = new AdjList[vno];
    for(int i=0;i<vno;i++)
    {
        cout<<"Enter v"<<i<<" neighbours: ";
        cin>>eno;
        for(int j=0;j<eno;j++)
        {
            cout<<"Enter "<<j<<" neighbour: ";
            cin>>n;
            arr[i].AddNode(n);
        }
    }
}
graph :: graph()
{
    arr=NULL;
}

int main()
{
    graph g1;
    g1.createGraph(5);
    g1.showGraph();
    return 0;
}
