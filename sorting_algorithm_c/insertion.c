#include<stdio.h>
#define size 10


void insertion(int arr[size],int n){
    int i,j;
    int temp;
    for(i=1;i<=n-1;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
        
    }

}

void print(int arr[size],int n){
    int i;
    printf("The sorted array is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        

    }
}

int main(){
    int arr[size]={2,4,3,1,5,7,6,9,8,0};

    insertion(arr,size);
    print(arr,size);


}