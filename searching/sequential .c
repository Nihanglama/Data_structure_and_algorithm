// sequentail search or linear search

#include<stdio.h>


int main(){
    int num,i;
    int found=0;
    int arr[10]={1,2,3,4,5,10,6,7,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",size);
    printf("Enter the element to search :");
    scanf("%d",&num);
    for(i=0;i<size;i++){
        if(num==arr[i]){
            printf("The element found at index %d \n",i+1);
            found=1;
            break;
        }
    }
    if(found=0){
        printf("There is no element in the array");

    }
    
}