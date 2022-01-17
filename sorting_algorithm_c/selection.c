#include<stdio.h>

#define size 10


void selection(int arr[size],int n){
    int i,j,temp,temp1;
    for(i=0;i<n;i++){
        temp=i;
        for(j=i+1;j<n;j++){
            if(arr[temp]>arr[j]){
                temp=j;
            }
        }
        temp1=arr[temp];
        arr[temp]=arr[i];
        arr[i]=temp1;
    }
}

void print(int arr[size],int n){
    int i;
    printf("The sorted array is :");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
int main(){
    int arr[size]={9,8,2,3,1,6,5,7,0,4};

    selection(arr,size);
    print(arr,size);
}