// binary searching

#include<stdio.h>

int main(){
    int num,i;
    int mid;
    int arr[10]={7,9,18,19,21,34,38,43,56,78};
    int high=9,low=0;
    printf("Enter the number to search");
    scanf("%d",&num);
    while(low<=high){
        mid=(high+low)/2;
        if(num==arr[mid]){
            printf("found at %d",mid+1);
            break;
            }
        else{
            if(num>arr[mid]){
                low=mid+1;

            }else{
                high=mid-1;
            }
            
        }
    }


}

