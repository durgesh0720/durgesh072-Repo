#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *arr;
int capecity=5;
int lastIndex=-1;

int* createArray(int size){
    int *arr=(int*)calloc(size,sizeof(int));   //ptr = (cast-type*)calloc(n, element-size);
    return arr;
}
bool isEmpty(){
    return lastIndex==-1;
}
bool isFull(){
    return lastIndex==capecity-1;
}
void append(int data){
    if(lastIndex<capecity){
        lastIndex++;
        arr[lastIndex]=data;
    }
    else
        printf("\nArray Capecity full!");
}
void showData(){
    if(lastIndex>=0){
        int i=0;
        for(i;i<=lastIndex;i++)
            printf("\n%d ",arr[i]);
    }
    else
        printf("No data");
}
void insert(int data,int index){
    if(lastIndex<capecity-1 && index>=0 && index<=lastIndex){
        for(int i=lastIndex;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index]=data;
        lastIndex++;
    }
    else    
        printf("\nArray Capecity full!");
}
void _remove(int data){
    if(lastIndex>=0){
        int temp=0;
        for(int i=0;i<=lastIndex;i++){
            if(arr[i]==data){
                for(int k=i;k<lastIndex;k++){
                    arr[k]=arr[k+1];
                }
                lastIndex--;
            }
        }
    }
    else
        printf("No data availbale in array");
}
void edit(int data,int index){
    if(!isEmpty()&&index<=lastIndex){
        arr[index]=data;
        printf("Edit");
    }
    
}
int main(){
    arr=createArray(capecity);
    append(10);
    append(20);
    append(30);
    append(40);
    append(50);
    _remove(20);
    _remove(10);
    insert(60,1);
    insert(50,0);
    edit(20,1);
    edit(10,0);
    showData();
    return 0;
}