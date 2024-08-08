#include<iostream>
#include<stdio.h>

using namespace std;

class ArrayDS{
    private:
        int *arr;
        int capecity;
        int lastIndex;
    public:
        ArrayDS(int);
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void remove(int);
        void show();
        ~ArrayDS();
};
ArrayDS::ArrayDS(int size){
    capecity=size;
    arr = new int[size];
    lastIndex = -1;
}
void ArrayDS::append(int data){
    if(lastIndex<capecity){
        lastIndex++;
        arr[lastIndex]=data;
    }
    else{
        cout<<"Array is full\n";
    }
}
void ArrayDS::insert(int data,int index){
    if(lastIndex<capecity && index<capecity && index >=0){
        for(int i=lastIndex;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=data;
        lastIndex++;
    }
    else
        cout<<"Array full or wrong Index";
}
void ArrayDS::edit(int data, int index){
    if(index<capecity && index>=0){
        arr[index]=data;
    }
    else
        cout<<"Wrong index!";
}
void ArrayDS::remove(int index){
    if(index<capecity && index>=0){
        for(int i=index;i<=lastIndex;i++){
            arr[i]=arr[i+1];
        }
        lastIndex--;
    }
    else
        cout<<"Wrong Index";
}
void ArrayDS::show(){
    if(lastIndex>=0){
        for(int i=0;i<=lastIndex;i++){
            cout<<" "<<arr[i];
        }
    }
    else
        cout<<"No data";
}
ArrayDS::~ArrayDS(){
    delete []arr;
}

int main(){
    ArrayDS DS(5);
    DS.append(10);
    DS.insert(20,1);
    DS.append(30);
    DS.insert(5,0);
    DS.remove(0);
    DS.show();
    return 0;
}
