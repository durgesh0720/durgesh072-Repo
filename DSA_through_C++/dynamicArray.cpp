#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class dynamic_array{
    private:
        int lastIndex;
        int capecity;
        int*arr;
    public:
        dynamic_array();
        void doubleArray();
        void halfArray();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        int getIndex(int);
        void deletion(int);
        void viewData();
        int getCapecity();
        ~dynamic_array();
};
dynamic_array :: ~dynamic_array(){
    delete []arr;
}
int dynamic_array :: getCapecity(){
    return capecity;
}
void dynamic_array :: viewData(){
    if(lastIndex!=-1){
        cout<<endl;
        for(int i=0;i<=lastIndex;i++){
            cout<<" "<<arr[i];
        }
    }
}
void dynamic_array :: deletion(int index){
    if(capecity/(2-1)==lastIndex)
        halfArray();
    if(lastIndex!=-1 && index<=lastIndex && index>=0){
        for(int i=index;i<=lastIndex;i++)
            arr[i]=arr[i+1];
    }
    else
        cout<<"\nDeletion not possible at this index";
}
int dynamic_array :: getIndex(int data){
    if(lastIndex!=-1){
        for(int i=0;i<=lastIndex;i++){
            if(arr[i]==data)
                return i;
        }
    }
    return -1;
}
void dynamic_array::edit(int index,int data){
    if(index>=0 && index<=lastIndex){
        arr[index]=data;
    }
    else
        cout<<"\nEditing not possible at this index";
}
void dynamic_array::insert(int index,int data){
    if(lastIndex==capecity-1)
        doubleArray();
    if(index>=0 && index<=lastIndex){
        for(int i=lastIndex;i>=index;i--)
            arr[i+1]=arr[i];
        arr[index]=data;
        lastIndex++;
    }
    else
        cout<<"\nInsertion not possible at this index";
}
void dynamic_array::append(int data){
    if(lastIndex==capecity-1)
        doubleArray();
    lastIndex++;
    arr[lastIndex]=data;
}
void dynamic_array::halfArray(){
    capecity/=2;
    int *ptr=new int[capecity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr[i];
    
    delete []arr;
    arr=ptr;
}
void dynamic_array::doubleArray(){
    capecity*=2;
    int *ptr=new int[capecity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr[i];

    delete [] arr;
    arr=ptr;
}
dynamic_array::dynamic_array(){
    capecity=1;
    arr=new int[capecity];
    lastIndex=-1;
}

int main(){
    dynamic_array dA;
    dA.append(20);
    dA.viewData();
    cout<<"Capecity Now: "<<dA.getCapecity();
    dA.append(30);
    dA.viewData();
    cout<<"Capecity Now: "<<dA.getCapecity();
    dA.insert(0,10);
    dA.viewData();
    cout<<"Capecity Now: "<<dA.getCapecity();
    return 0;
}