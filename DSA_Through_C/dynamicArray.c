#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int lastIndex;
int capecity;
int *arr;

void createArray(){
    capecity=1;
    lastIndex=-1;
    arr=(int*)calloc(capecity,4);
}

void halfArray(){
    capecity/=2;
    int*ptr=(int*)calloc(capecity,4);
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr[i];
    free(arr);
    arr=ptr;
}

void doubleArray(){
    capecity*=2;
    int*ptr=(int*)calloc(capecity,4);
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr[i];
    free(arr);
    arr=ptr;
}
void append(int data){
    if(lastIndex==capecity-1)
        doubleArray();
    lastIndex++;
    arr[lastIndex]=data;
}
void insert(int index,int data){
    if(lastIndex==capecity-1)
        doubleArray();
    if(index>=0 && index<=lastIndex){
        for(int i=lastIndex;i>=index;i--)
            arr[i+1]=arr[i];
        arr[index]=data;
        lastIndex++;
    }
    else
        printf("\nInsertion not possible at this index");
}
void showData(){
    printf("\n");
    if(lastIndex!=-1)
        for(int i=0;i<=lastIndex;i++)
            printf("%d ",arr[i]);
    else
        printf("\nNo Data available");
}
int getIndex(int data){
    if(lastIndex!=-1){
        for(int i=0;i<=lastIndex;i++)
            if(arr[i]==data)
                return i;
    }
    else
        return -1;
}
void deletion(int index){
    if(capecity/2-1==lastIndex)
        halfArray();
    for(int i=index;i<=lastIndex;i++)
        arr[i]=arr[i+1];
    lastIndex--;
}
int main(){
    createArray();
    append(10);
    showData();
    printf("\nNow Capecity: %d",capecity);
    append(20);
    showData();
    printf("\nNow Capecity: %d",capecity);
    insert(0,5);
    showData();
    printf("\nNow Capecity: %d",capecity);

    deletion(getIndex(5));
    showData();
    printf("\nAfter deletion Now Capecity: %d",capecity);

    deletion(getIndex(10));
    showData();
    printf("\nAfter deletion Now Capecity: %d",capecity);

    return 0;
}