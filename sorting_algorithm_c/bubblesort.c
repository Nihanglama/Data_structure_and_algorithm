#include<stdio.h>
#define size 10
#include<stdbool.h>

void swap(int *l,int *f){
    int temp;
    temp=*l;
    *l=*f;
    *f=temp;
}

void bubblesort(int arr[size],int n){
    int i,j;
    

    for(i=0;i<n-1;i++){
        int swaps=0;
        for(j=0;j<n-1-i;j++){
            if(arr[j+1]<arr[j]){
                swap(&arr[j+1],&arr[j]);
                swaps=1;

            }
            
        }
        if(swaps==0){
            break;
        }
    }

}

void print(int arr[size],int n){
    int i;
    for(i=0;i<n-1;i++){
        printf("%d ",arr[i]);

    }
}



int main(){
    int arr[size];
    int i;

    printf("Enter the array elements");
    for(i=0;i<size-1;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,size);
    print(arr,size);




}
